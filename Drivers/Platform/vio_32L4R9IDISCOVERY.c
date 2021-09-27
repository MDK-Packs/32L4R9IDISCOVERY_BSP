/******************************************************************************
 * @file     vio_32L4R9IDISCOVERY.c
 * @brief    Virtual I/O implementation for board 32L4R9IDISCOVERY
 * @version  V1.0.0
 * @date     22. September 2021
 ******************************************************************************/
/*
 * Copyright (c) 2021 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \page vio_32L4R9IDISCOVERY Physical I/O Mapping

The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.

Virtual Resource  | Variable       | Physical Resource on 32L4R9IDISCOVERY |
:-----------------|:---------------|:--------------------------------------|
vioBUTTON0        | vioSignalIn.0  | Joystic (with define VIO_BUTTON_REMAP)|
vioJOYup          | vioSignalIn.4  | MFX_IO1:   Joystic UP                 |
vioJOYdown        | vioSignalIn.5  | MFX_IO2:   Joystic DOWN               |
vioJOYleft        | vioSignalIn.6  | MFX_IO4:   Joystic LEFT               |
vioJOYright       | vioSignalIn.7  | MFX_IO3:   Joystic RIGHT              |
vioJOYselect      | vioSignalIn.8  | GPIO C.13: Joystic SELECT             |
vioLED0           | vioSignalOut.0 | GPIO H.4:  LD2 GREEN                  |
vioLED1           | vioSignalOut.1 | MFX_IO0:   LD1 ORANGE                 |
*/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "cmsis_vio.h"

#include "RTE_Components.h"
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "stm32l4r9i_discovery.h"
#include "stm32l4r9i_discovery_io.h"
#if !defined VIO_LCD_DISABLE
#include "stm32l4r9i_discovery_lcd.h"

#include "cmsis_os2.h"
#endif
#endif

// VIO input, output definitions
#define VIO_PRINT_MAX_SIZE      64U     // maximum size of print memory
#define VIO_PRINTMEM_NUM         4U     // number of print memories
#define VIO_VALUE_NUM            3U     // number of values
#define VIO_VALUEXYZ_NUM         3U     // number of XYZ values
#define VIO_IPV4_ADDRESS_NUM     2U     // number of IPv4 addresses
#define VIO_IPV6_ADDRESS_NUM     2U     // number of IPv6 addresses

// VIO input, output variables
__USED uint32_t      vioSignalIn;                                       // Memory for incoming signal
__USED uint32_t      vioSignalOut;                                      // Memory for outgoing signal
__USED char          vioPrintMem[VIO_PRINTMEM_NUM][VIO_PRINT_MAX_SIZE]; // Memory for the last value for each level
__USED int32_t       vioValue   [VIO_VALUE_NUM];                        // Memory for value used in vioGetValue/vioSetValue
__USED vioValueXYZ_t vioValueXYZ[VIO_VALUEXYZ_NUM];                     // Memory for XYZ value for 3-D vector
__USED vioAddrIPv4_t vioAddrIPv4[VIO_IPV4_ADDRESS_NUM];                 // Memory for IPv4 address value used in vioSetIPv4/vioGetIPv4
__USED vioAddrIPv6_t vioAddrIPv6[VIO_IPV6_ADDRESS_NUM];                 // Memory for IPv6 address value used in vioSetIPv6/vioGetIPv6

#if !defined CMSIS_VOUT
// Global types, variables, functions
#if !defined VIO_LCD_DISABLE
static osMutexId_t  mid_mutLCD;         // Mutex ID of mutex:  LCD
#endif

#if !defined VIO_LCD_DISABLE
typedef struct displayArea {
  uint16_t   xOrigin;          // x Origin
  uint16_t   xWidth;           // x width
  uint16_t   xPos;             // current x position
  uint16_t   yOrigin;          // y Origin
  uint16_t   yHeight;          // y height
  uint16_t   yPos;             // current y position
  uint16_t   fontWidth;        // font width
  uint16_t   fontHeight;       // font height
} displayArea_t;

static displayArea_t display[4];

/**
  Scroll content of the selected display for dy pixels vertically

  \param[in]   idx   Display index.
*/
static void displayScrollVertical (uint32_t idx) {
  uint32_t x, y, color;

  for (y = display[idx].yOrigin; y < (display[idx].yHeight - display[idx].fontHeight); y++) {
    for (x = display[idx].xOrigin; x < display[idx].xWidth; x++) {
      color = BSP_LCD_ReadPixel(x, y + display[idx].fontHeight);
      BSP_LCD_DrawPixel(x, y, color);
    }
  }

  for (; y < display[idx].yHeight; y++) {
    for (x = display[idx].xOrigin; x < display[idx].xWidth; x++) {
      BSP_LCD_DrawPixel(x, y, LCD_COLOR_BLACK);
    }
  }
}

/**
  write a string to the selected display

  \param[in]   idx   Display index.
  \param[in]   str   String
*/
static void displayString (uint32_t idx, char *str) {
  char ch;
  uint8_t i = 0;

  while (str[i] != '\0') {
    ch = str[i++];                                                   /* Get character and increase index */

    switch (ch) {
      case 0x0A:                          // Line Feed
        display[idx].yPos += display[idx].fontHeight;                /* Move cursor one row down */
        if (display[idx].yPos >= display[idx].yHeight) {             /* If bottom of display was overstepped */
          displayScrollVertical(idx);
          display[idx].yPos -= display[idx].fontHeight;              /* Stay in last row */
        }
        break;
      case 0x0D:                                                     /* Carriage Return */
        display[idx].xPos = display[idx].xOrigin;                    /* Move cursor to first column */
        break;
      default:
        // Display character at current cursor position
        BSP_LCD_DisplayChar(display[idx].xPos, display[idx].yPos, ch);
        display[idx].xPos += display[idx].fontWidth;                 /* Move cursor one column to right */
        if (display[idx].xPos >= display[idx].xWidth) {              /* If last column was overstepped */
          display[idx].xPos = display[idx].xOrigin;                  /* First column */
          display[idx].yPos += display[idx].fontHeight;              /* Move cursor one row down and to */
        }
        if (display[idx].yPos >= display[idx].yHeight) {             /* If bottom of display was overstepped */
          displayScrollVertical(idx);
          display[idx].yPos -= display[idx].fontHeight;              /* Stay in last row */
        }
        break;
    }

  }
}
#endif
#endif

#if !defined CMSIS_VIN
// Add global user types, variables, functions here:

#endif

// Initialize test input, output.
void vioInit (void) {
uint32_t x_size, y_size;
#if !defined CMSIS_VOUT
#if !defined VIO_LCD_DISABLE
// Add user variables here:

#endif
#endif

#if !defined CMSIS_VIN
// Add user variables here:

#endif

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

  memset(vioPrintMem, 0, sizeof(vioPrintMem));
  memset(vioValue,    0, sizeof(vioValue));
  memset(vioValueXYZ, 0, sizeof(vioValueXYZ));
  memset(vioAddrIPv4, 0, sizeof(vioAddrIPv4));
  memset(vioAddrIPv6, 0, sizeof(vioAddrIPv6));

  // Initialize IO functionalities
  BSP_IO_Init();

#if defined MemoryCard_CD0_Pin_Extern
  // Configure SD card detect pin according to IO mode
  if(BSP_IO_ReadPin(SD_DETECT_PIN) == IO_PIN_RESET) {
    // Card present
    BSP_IO_ConfigPin(SD_DETECT_PIN, IO_MODE_IT_RISING_EDGE_PU);
  }
  else {
    // Card not present
    BSP_IO_ConfigPin(SD_DETECT_PIN, IO_MODE_IT_FALLING_EDGE_PU);
  }
#endif

#if !defined CMSIS_VOUT
  // Initialize LEDs pins
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_ORANGE);

#if !defined VIO_LCD_DISABLE
  // Create LCD mutex
  mid_mutLCD = osMutexNew(NULL);
  if (mid_mutLCD == NULL) { /* add error handling */ }

  // Initialize the LCD
  BSP_LCD_Init();

  // Check that frame buffer is available
  while(BSP_LCD_IsFrameBufferAvailable() != LCD_OK);

  // Set LCD Foreground Layer
  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER_BACKGROUND);

  // Set Font
  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);

  // Clear the LCD
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
  BSP_LCD_Clear(LCD_COLOR_BLACK);

  // Set the display on
  BSP_LCD_DisplayOn();

  x_size = BSP_LCD_GetXSize() - 120U;
  y_size = BSP_LCD_GetYSize() - 120U;

  // Initialize display areas
  display[vioLevelHeading].fontWidth  = 11;
  display[vioLevelHeading].fontHeight = 16;
  display[vioLevelHeading].xOrigin    =  3 + 60;
  display[vioLevelHeading].xWidth     = x_size - 4;
  display[vioLevelHeading].xPos       = display[vioLevelHeading].xOrigin;
  display[vioLevelHeading].yOrigin    = 64;
  display[vioLevelHeading].yHeight    = 2 * display[vioLevelHeading].fontHeight + display[vioLevelHeading].yOrigin;
  display[vioLevelHeading].yPos       = display[vioLevelHeading].yOrigin;

  display[vioLevelNone].fontWidth     = 7;
  display[vioLevelNone].fontHeight    = 12;
  display[vioLevelNone].xOrigin       =  3 + 60;
  display[vioLevelNone].xWidth        = x_size - 4;
  display[vioLevelNone].xPos          = display[vioLevelNone].xOrigin;
  display[vioLevelNone].yOrigin       = 140;
  display[vioLevelNone].yHeight       = 2 * display[vioLevelNone].fontHeight + display[vioLevelNone].yOrigin;
  display[vioLevelNone].yPos          = display[vioLevelNone].yOrigin;

  display[vioLevelError].fontWidth    = 7;
  display[vioLevelError].fontHeight   = 12;
  display[vioLevelError].xOrigin      = 3 + 60;
  display[vioLevelError].xWidth       = x_size - 4;
  display[vioLevelError].xPos         = display[vioLevelError].xOrigin;
  display[vioLevelError].yOrigin      = 155;
  display[vioLevelError].yHeight      = 4 * display[vioLevelError].fontHeight + display[vioLevelError].yOrigin;
  display[vioLevelError].yPos         = display[vioLevelError].yOrigin;

  display[vioLevelMessage].fontWidth  = 7;
  display[vioLevelMessage].fontHeight = 12;
  display[vioLevelMessage].xOrigin    = 3 + 60;
  display[vioLevelMessage].xWidth     = x_size - 4;
  display[vioLevelMessage].xPos       = display[vioLevelMessage].xOrigin;
  display[vioLevelMessage].yOrigin    = 230;
  display[vioLevelMessage].yHeight    = 8 * display[vioLevelMessage].fontHeight + display[vioLevelMessage].yOrigin;
  display[vioLevelMessage].yPos       = display[vioLevelMessage].yOrigin;

  // Set the LCD Text Color
  BSP_LCD_SetTextColor(LCD_COLOR_ORANGE);

  // Draw LCD layout
  BSP_LCD_DrawRect(60U, 60U, x_size,    y_size   );
  BSP_LCD_DrawRect(61U, 61U, x_size-2U, y_size-2U);
  /*   3        pixel row empty */
  /*   4.. 35   2 lines font16 =  2*16 vioLevelHeading */
  /*  36        pixel row empty  */

  BSP_LCD_DrawHLine(62U, 100U, x_size-4U);
  BSP_LCD_DrawHLine(62U, 101U, x_size-4U);
  /*  39        pixel row empty */
  /*  40.. 63   2 lines font12 =  2*12 vioLevelNone */
  /*  64        pixel row empty */

  BSP_LCD_DrawHLine(62U, 150U, x_size-4U);
  BSP_LCD_DrawHLine(62U, 151U, x_size-4U);
  /*  67        pixel row empty */
  /*  68..115   4 lines font12 =  4*12 vioLevelError */
  /* 116        pixel row empty */

  BSP_LCD_DrawHLine(62U, 220U, x_size-4U);
  BSP_LCD_DrawHLine(62U, 221U, x_size-4U);
  /* 119        pixel row empty */
  /* 120..227   9 lines font12 = 9*12 vioLevelMessage */
  /* 228        pixel row empty */

  // Refresh the display
  BSP_LCD_Refresh();
#endif
#endif

#if !defined CMSIS_VIN
  // Initialize joystick pins
  BSP_JOY_Init(JOY_MODE_GPIO);

#endif
}

// Print formated string to test terminal.
int32_t vioPrint (uint32_t level, const char *format, ...) {
  va_list args;
  int32_t ret;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (level > vioLevelError) {
    return (-1);
  }

  if (level > VIO_PRINTMEM_NUM) {
    return (-1);
  }

  va_start(args, format);

  ret = vsnprintf((char *)vioPrintMem[level], sizeof(vioPrintMem[level]), format, args);

  va_end(args);

#if !defined CMSIS_VOUT
#if !defined VIO_LCD_DISABLE
// Draw LCD level
  osMutexAcquire(mid_mutLCD, osWaitForever);
  switch (level) {
    case vioLevelNone:
      BSP_LCD_SetFont(&Font12);
      BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelHeading:
      BSP_LCD_SetFont(&Font16);
      BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelMessage:
      BSP_LCD_SetFont(&Font12);
      BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
      displayString(level, (char *)vioPrintMem[level]);
      break;
    case vioLevelError:
      BSP_LCD_SetFont(&Font12);
      BSP_LCD_SetTextColor(LCD_COLOR_RED);
      displayString(level, (char *)vioPrintMem[level]);
      break;
  }
      BSP_LCD_SetFont(&Font12);
      BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
  osMutexRelease(mid_mutLCD);

  // Refresh the display
  BSP_LCD_Refresh();

#endif
#endif

  return (ret);
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  // Output signals to LEDs
  if ((mask & vioLED0) != 0U) {
    if ((signal & vioLED0) != 0U) {
      BSP_LED_On(LED_GREEN);
    } else {
      BSP_LED_Off(LED_GREEN);
    }
  }

  if ((mask & vioLED1) != 0U) {
    if ((signal & vioLED1) != 0U) {
      BSP_LED_On(LED_ORANGE);
    } else {
      BSP_LED_Off(LED_ORANGE);
    }
  }
#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

#if !defined CMSIS_VIN
  // Get input signals from joystick
#if defined VIO_BUTTON_REMAP
  if ((mask & vioBUTTON0) != 0U) {
    if (BSP_JOY_GetState() != JOY_NONE ) {
      vioSignalIn |=  vioBUTTON0;
    } else {
      vioSignalIn &= ~vioBUTTON0;
    }
  }
#endif

  if ((mask & vioJOYup) != 0U) {
    if (BSP_JOY_GetState() == JOY_UP) {
      vioSignalIn |=  vioJOYup;
    } else {
      vioSignalIn &= ~vioJOYup;
    }
  }

  if ((mask & vioJOYselect) != 0U) {
    if (BSP_JOY_GetState() == JOY_SEL) {
      vioSignalIn |=  vioJOYselect;
    } else {
      vioSignalIn &= ~vioJOYselect;
    }
  }

  if ((mask & vioJOYright) != 0U) {
    if (BSP_JOY_GetState() == JOY_RIGHT) {
      vioSignalIn |=  vioJOYright;
    } else {
      vioSignalIn &= ~vioJOYright;
    }
  }

  if ((mask & vioJOYleft) != 0U) {
    if (BSP_JOY_GetState() == JOY_LEFT) {
      vioSignalIn |=  vioJOYleft;
    } else {
      vioSignalIn &= ~vioJOYleft;
    }
  }

  if ((mask & vioJOYdown) != 0U) {
    if (BSP_JOY_GetState() == JOY_DOWN) {
      vioSignalIn |=  vioJOYdown;
    } else {
      vioSignalIn &= ~vioJOYdown;
    }
  }
#endif

  signal = vioSignalIn;

  return (signal & mask);
}

// Set value output.
void vioSetValue (uint32_t id, int32_t value) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValue[index] = value;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get value input.
int32_t vioGetValue (uint32_t id) {
  uint32_t index = id;
  int32_t  value = 0;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return value;                       /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValue[index] = ...;
#endif

  value = vioValue[index];

  return value;
}

// Set XYZ value output.
void vioSetXYZ (uint32_t id, vioValueXYZ_t valueXYZ) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUEXYZ_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValueXYZ[index] = valueXYZ;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get XYZ value input.
vioValueXYZ_t vioGetXYZ (uint32_t id) {
  uint32_t index = id;
  vioValueXYZ_t valueXYZ = {0, 0, 0};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUEXYZ_NUM) {
    return valueXYZ;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValueXYZ[index] = ...;
#endif

  valueXYZ = vioValueXYZ[index];

  return valueXYZ;
}

// Set IPv4 address output.
void vioSetIPv4 (uint32_t id, vioAddrIPv4_t addrIPv4) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_IPV4_ADDRESS_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioAddrIPv4[index] = addrIPv4;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get IPv4 address input.
vioAddrIPv4_t vioGetIPv4 (uint32_t id) {
  uint32_t index = id;
  vioAddrIPv4_t addrIPv4 = {0U, 0U, 0U, 0U};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_IPV4_ADDRESS_NUM) {
    return addrIPv4;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioAddrIPv4[index] = ...;
#endif

  addrIPv4 = vioAddrIPv4[index];

  return addrIPv4;
}

// Set IPv6 address output.
void vioSetIPv6 (uint32_t id, vioAddrIPv6_t addrIPv6) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_IPV6_ADDRESS_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioAddrIPv6[index] = addrIPv6;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get IPv6 address input.
vioAddrIPv6_t vioGetIPv6 (uint32_t id) {
  uint32_t index = id;
  vioAddrIPv6_t addrIPv6 = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
                            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_IPV6_ADDRESS_NUM) {
    return addrIPv6;                    /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioAddrIPv6[index] = ...;
#endif

  addrIPv6 = vioAddrIPv6[index];

  return addrIPv6;
}
