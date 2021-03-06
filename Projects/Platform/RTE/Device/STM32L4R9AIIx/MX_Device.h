/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 22/09/2021 10:22:24
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            16000000
#define MX_SYSCLKFreq_VALUE                     120000000
#define MX_HCLKFreq_Value                       120000000
#define MX_FCLKCortexFreq_Value                 120000000
#define MX_CortexFreq_Value                     120000000
#define MX_AHBFreq_Value                        120000000
#define MX_APB1Freq_Value                       120000000
#define MX_APB2Freq_Value                       120000000
#define MX_APB1TimFreq_Value                    120000000
#define MX_APB2TimFreq_Value                    120000000
#define MX_LCDTFTFreq_Value                     15000000
#define MX_PWRFreq_Value                        120000000
#define MX_RTCFreq_Value                        32000
#define MX_USBFreq_Value                        16000000
#define MX_WatchDogFreq_Value                   32000
#define MX_MCO1PinFreq_Value                    120000000

/*-------------------------------- DMA        --------------------------------*/

#define MX_DMA                                  1

/* NVIC Configuration */

/* NVIC DMA1_Channel1_IRQn */
#define MX_DMA1_Channel1_IRQn_interruptPremptionPriority 8
#define MX_DMA1_Channel1_IRQn_PriorityGroup     NVIC_PRIORITYGROUP_4
#define MX_DMA1_Channel1_IRQn_Subriority        0

/* NVIC DMA1_Channel2_IRQn */
#define MX_DMA1_Channel2_IRQn_interruptPremptionPriority 8
#define MX_DMA1_Channel2_IRQn_PriorityGroup     NVIC_PRIORITYGROUP_4
#define MX_DMA1_Channel2_IRQn_Subriority        0

/*-------------------------------- DMA2D      --------------------------------*/

#define MX_DMA2D                                1

/* GPIO Configuration */

/*-------------------------------- DSIHOST    --------------------------------*/

#define MX_DSIHOST                              1

/* GPIO Configuration */

/* Pin DSIHOST_D0N */
#define MX_DSIHOST_D0N_Pin                      DSIHOST_D0N

/* Pin DSIHOST_D1N */
#define MX_DSIHOST_D1N_Pin                      DSIHOST_D1N

/* Pin DSIHOST_D0P */
#define MX_DSIHOST_D0P_Pin                      DSIHOST_D0P

/* Pin DSIHOST_D1P */
#define MX_DSIHOST_D1P_Pin                      DSIHOST_D1P

/* Pin DSIHOST_CKN */
#define MX_DSIHOST_CKN_Pin                      DSIHOST_CKN

/* Pin DSIHOST_CKP */
#define MX_DSIHOST_CKP_Pin                      DSIHOST_CKP

/* NVIC Configuration */

/* NVIC DSI_IRQn */
#define MX_DSI_IRQn_interruptPremptionPriority  0
#define MX_DSI_IRQn_PriorityGroup               NVIC_PRIORITYGROUP_4
#define MX_DSI_IRQn_Subriority                  0

/*-------------------------------- GFXMMU     --------------------------------*/

#define MX_GFXMMU                               1

/* GPIO Configuration */

/* NVIC Configuration */

/* NVIC GFXMMU_IRQn */
#define MX_GFXMMU_IRQn_interruptPremptionPriority 0
#define MX_GFXMMU_IRQn_PriorityGroup            NVIC_PRIORITYGROUP_4
#define MX_GFXMMU_IRQn_Subriority               0

/*-------------------------------- LPUART1    --------------------------------*/

#define MX_LPUART1                              1

/* GPIO Configuration */

/* Pin PC0 */
#define MX_LPUART1_RX_GPIO_Speed                GPIO_SPEED_FREQ_VERY_HIGH
#define MX_LPUART1_RX_Pin                       PC0
#define MX_LPUART1_RX_GPIOx                     GPIOC
#define MX_LPUART1_RX_GPIO_PuPd                 GPIO_NOPULL
#define MX_LPUART1_RX_GPIO_Pin                  GPIO_PIN_0
#define MX_LPUART1_RX_GPIO_AF                   GPIO_AF8_LPUART1
#define MX_LPUART1_RX_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PC1 */
#define MX_LPUART1_TX_GPIO_Speed                GPIO_SPEED_FREQ_VERY_HIGH
#define MX_LPUART1_TX_Pin                       PC1
#define MX_LPUART1_TX_GPIOx                     GPIOC
#define MX_LPUART1_TX_GPIO_PuPd                 GPIO_NOPULL
#define MX_LPUART1_TX_GPIO_Pin                  GPIO_PIN_1
#define MX_LPUART1_TX_GPIO_AF                   GPIO_AF8_LPUART1
#define MX_LPUART1_TX_GPIO_Mode                 GPIO_MODE_AF_PP

/* NVIC Configuration */

/* NVIC LPUART1_IRQn */
#define MX_LPUART1_IRQn_interruptPremptionPriority 8
#define MX_LPUART1_IRQn_PriorityGroup           NVIC_PRIORITYGROUP_4
#define MX_LPUART1_IRQn_Subriority              0

/*-------------------------------- USART2     --------------------------------*/

#define MX_USART2                               1

#define MX_USART2_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PA2 */
#define MX_USART2_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_TX_Pin                        PA2
#define MX_USART2_TX_GPIOx                      GPIOA
#define MX_USART2_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_TX_GPIO_Pin                   GPIO_PIN_2
#define MX_USART2_TX_GPIO_AF                    GPIO_AF7_USART2

/* Pin PA3 */
#define MX_USART2_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_RX_Pin                        PA3
#define MX_USART2_RX_GPIOx                      GPIOA
#define MX_USART2_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_RX_GPIO_Pin                   GPIO_PIN_3
#define MX_USART2_RX_GPIO_AF                    GPIO_AF7_USART2

/*-------------------------------- LTDC       --------------------------------*/

#define MX_LTDC                                 1

/* GPIO Configuration */

/* NVIC Configuration */

/* NVIC LTDC_IRQn */
#define MX_LTDC_IRQn_interruptPremptionPriority 0
#define MX_LTDC_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_LTDC_IRQn_Subriority                 0

/* NVIC LTDC_ER_IRQn */
#define MX_LTDC_ER_IRQn_interruptPremptionPriority 0
#define MX_LTDC_ER_IRQn_PriorityGroup           NVIC_PRIORITYGROUP_4
#define MX_LTDC_ER_IRQn_Subriority              0

/*-------------------------------- SDMMC1     --------------------------------*/

#define MX_SDMMC1                               1

/* GPIO Configuration */

/* Pin PD2 */
#define MX_SDMMC1_CMD_Pin                       PD2
#define MX_SDMMC1_CMD_GPIOx                     GPIOD
#define MX_SDMMC1_CMD_GPIO_PuPd                 GPIO_NOPULL
#define MX_SDMMC1_CMD_GPIO_Speed_High_Default   GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_CMD_GPIO_Pin                  GPIO_PIN_2
#define MX_SDMMC1_CMD_GPIO_AF                   GPIO_AF12_SDMMC1
#define MX_SDMMC1_CMD_GPIO_Mode                 GPIO_MODE_AF_PP

/* Pin PC8 */
#define MX_SDMMC1_D0_Pin                        PC8
#define MX_SDMMC1_D0_GPIOx                      GPIOC
#define MX_SDMMC1_D0_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D0_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D0_GPIO_Pin                   GPIO_PIN_8
#define MX_SDMMC1_D0_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D0_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC9 */
#define MX_SDMMC1_D1_Pin                        PC9
#define MX_SDMMC1_D1_GPIOx                      GPIOC
#define MX_SDMMC1_D1_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D1_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D1_GPIO_Pin                   GPIO_PIN_9
#define MX_SDMMC1_D1_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D1_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC10 */
#define MX_SDMMC1_D2_Pin                        PC10
#define MX_SDMMC1_D2_GPIOx                      GPIOC
#define MX_SDMMC1_D2_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D2_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D2_GPIO_Pin                   GPIO_PIN_10
#define MX_SDMMC1_D2_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D2_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC11 */
#define MX_SDMMC1_D3_Pin                        PC11
#define MX_SDMMC1_D3_GPIOx                      GPIOC
#define MX_SDMMC1_D3_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_D3_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_D3_GPIO_Pin                   GPIO_PIN_11
#define MX_SDMMC1_D3_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_D3_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PC12 */
#define MX_SDMMC1_CK_Pin                        PC12
#define MX_SDMMC1_CK_GPIOx                      GPIOC
#define MX_SDMMC1_CK_GPIO_PuPd                  GPIO_NOPULL
#define MX_SDMMC1_CK_GPIO_Speed_High_Default    GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SDMMC1_CK_GPIO_Pin                   GPIO_PIN_12
#define MX_SDMMC1_CK_GPIO_AF                    GPIO_AF12_SDMMC1
#define MX_SDMMC1_CK_GPIO_Mode                  GPIO_MODE_AF_PP

/* NVIC Configuration */

/* NVIC SDMMC1_IRQn */
#define MX_SDMMC1_IRQn_interruptPremptionPriority 8
#define MX_SDMMC1_IRQn_PriorityGroup            NVIC_PRIORITYGROUP_4
#define MX_SDMMC1_IRQn_Subriority               0

/*-------------------------------- SPI2       --------------------------------*/

#define MX_SPI2                                 1

/* GPIO Configuration */

/* Pin PB13 */
#define MX_SPI2_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_SCK_Pin                         PB13
#define MX_SPI2_SCK_GPIOx                       GPIOB
#define MX_SPI2_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI2_SCK_GPIO_Pin                    GPIO_PIN_13
#define MX_SPI2_SCK_GPIO_AF                     GPIO_AF5_SPI2
#define MX_SPI2_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/* Pin PB15 */
#define MX_SPI2_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MOSI_Pin                        PB15
#define MX_SPI2_MOSI_GPIOx                      GPIOB
#define MX_SPI2_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MOSI_GPIO_Pin                   GPIO_PIN_15
#define MX_SPI2_MOSI_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB14 */
#define MX_SPI2_MISO_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI2_MISO_Pin                        PB14
#define MX_SPI2_MISO_GPIOx                      GPIOB
#define MX_SPI2_MISO_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI2_MISO_GPIO_Pin                   GPIO_PIN_14
#define MX_SPI2_MISO_GPIO_AF                    GPIO_AF5_SPI2
#define MX_SPI2_MISO_GPIO_Mode                  GPIO_MODE_AF_PP

/* DMA Configuration */

/* DMA SPI2_TX */
#define MX_SPI2_TX_DMA_Instance                 DMA1_Channel2
#define MX_SPI2_TX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI2_TX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_Mode                     DMA_NORMAL
#define MX_SPI2_TX_DMA_SyncRequestNumber        1
#define MX_SPI2_TX_DMA_Request                  DMA_REQUEST_SPI2_TX
#define MX_SPI2_TX_DMA_SyncPolarity             HAL_DMAMUX_SYNC_NO_EVENT
#define MX_SPI2_TX_DMA_Direction                DMA_MEMORY_TO_PERIPH
#define MX_SPI2_TX_DMA_SignalID                 NONE
#define MX_SPI2_TX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI2_TX_DMA_IpInstance
#define MX_SPI2_TX_DMA_RequestNumber            1
#define MX_SPI2_TX_DMA_EventEnable              DISABLE
#define MX_SPI2_TX_DMA_SyncEnable               DISABLE
#define MX_SPI2_TX_DMA_DMA_Handle
#define MX_SPI2_TX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI2_TX_DMA_Polarity                 HAL_DMAMUX_REQUEST_GEN_RISING
#define MX_SPI2_TX_DMA_SyncSignalID             NONE
#define MX_SPI2_TX_DMA_PeriphInc                DMA_PINC_DISABLE

/* DMA SPI2_RX */
#define MX_SPI2_RX_DMA_Instance                 DMA1_Channel1
#define MX_SPI2_RX_DMA_Priority                 DMA_PRIORITY_LOW
#define MX_SPI2_RX_DMA_MemDataAlignment         DMA_MDATAALIGN_BYTE
#define MX_SPI2_RX_DMA_Mode                     DMA_NORMAL
#define MX_SPI2_RX_DMA_SyncRequestNumber        1
#define MX_SPI2_RX_DMA_Request                  DMA_REQUEST_SPI2_RX
#define MX_SPI2_RX_DMA_SyncPolarity             HAL_DMAMUX_SYNC_NO_EVENT
#define MX_SPI2_RX_DMA_Direction                DMA_PERIPH_TO_MEMORY
#define MX_SPI2_RX_DMA_SignalID                 NONE
#define MX_SPI2_RX_DMA_MemInc                   DMA_MINC_ENABLE
#define MX_SPI2_RX_DMA_IpInstance
#define MX_SPI2_RX_DMA_RequestNumber            1
#define MX_SPI2_RX_DMA_EventEnable              DISABLE
#define MX_SPI2_RX_DMA_SyncEnable               DISABLE
#define MX_SPI2_RX_DMA_DMA_Handle
#define MX_SPI2_RX_DMA_PeriphDataAlignment      DMA_PDATAALIGN_BYTE
#define MX_SPI2_RX_DMA_Polarity                 HAL_DMAMUX_REQUEST_GEN_RISING
#define MX_SPI2_RX_DMA_SyncSignalID             NONE
#define MX_SPI2_RX_DMA_PeriphInc                DMA_PINC_DISABLE

/* NVIC Configuration */

/* NVIC SPI2_IRQn */
#define MX_SPI2_IRQn_interruptPremptionPriority 9
#define MX_SPI2_IRQn_PriorityGroup              NVIC_PRIORITYGROUP_4
#define MX_SPI2_IRQn_Subriority                 0

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PI0 */
#define MX_PI0_GPIO_Speed                       GPIO_SPEED_FREQ_VERY_HIGH
#define MX_PI0_Pin                              PI0
#define MX_PI0_GPIOx                            GPIOI
#define MX_PI0_PinState                         GPIO_PIN_SET
#define MX_PI0_GPIO_PuPd                        GPIO_NOPULL
#define MX_ARDUINO_IO_D10                       PI0
#define MX_PI0_GPIO_Pin                         GPIO_PIN_0
#define MX_PI0_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PH13 */
#define MX_PH13_Pin                             PH13
#define MX_PH13_GPIOx                           GPIOH
#define MX_PH13_GPIO_PuPd                       GPIO_NOPULL
#define MX_ARDUINO_IO_D9                        PH13
#define MX_PH13_GPIO_Pin                        GPIO_PIN_13
#define MX_PH13_GPIO_Mode                       GPIO_MODE_INPUT

#endif  /* __MX_DEVICE_H */

