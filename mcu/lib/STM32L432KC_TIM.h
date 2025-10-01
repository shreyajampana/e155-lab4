// STM32L432KC_TIM.h
// Header for TIM functions

#ifndef STM32L4_TIM_H
#define STM32L4_TIM_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM15_BASE (0x40014000UL) // base address of TIM15
#define TIM16_BASE (0x40014400UL) // base address of TIM16

#define TICKS_PER_MS_DELAY    10
#define TICKS_PER_MS_FREQ     10000


typedef struct
{
  __IO uint32_t CR1;          /*!< Control register 1,                                  Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< Control register 2,                                  Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< Slave mode control register,                         Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< Status register,                                     Address offset: 0x0C */
  __IO uint32_t SR;           /*!< RCC PLL SAI1 configuration register,                 Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< Event generation register,                           Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< Capture/compare mode register 1,                     Address offset: 0x18 */
  uint32_t      RESERVED0;    /*!< Reserved,                                            Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< Capture/compare enable register,                     Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< Counter,                                             Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< Prescaler,                                           Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< Auto-reload register,                                Address offset: 0x2C */
  __IO uint32_t RCR;          /*!< Repetition counter register,                         Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< Capture/compare register 1,                          Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< Capture/compare register 2,                          Address offset: 0x38 */
  uint32_t      RESERVED1;    /*!< Reserved,                                            Address offset: 0x3C */
  uint32_t      RESERVED2;    /*!< Reserved,                                            Address offset: 0x40 */
  __IO uint32_t BDTR;         /*!< Break and dead-time register,                        Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< DMA control register,                                Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< DMA address for full transfer,                       Address offset: 0x4C */
  __IO uint32_t OR1;          /*!< Option register 1,                                   Address offset: 0x50 */
  uint32_t      RESERVED3;    /*!< Reserved,                                            Address offset: 0x54 */
  uint32_t      RESERVED4;    /*!< Reserved,                                            Address offset: 0x58 */
  uint32_t      RESERVED5;    /*!< Reserved,                                            Address offset: 0x5C */
  __IO uint32_t OR2;          /*!< Option register 2,                                   Address offset: 0x60 */
} TIM_TypeDef;

#define TIM15 ((TIM_TypeDef *) TIM15_BASE)
#define TIM16 ((TIM_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initTIM(TIM_TypeDef * TIMx);
void delay_millis(TIM_TypeDef * TIMx, uint32_t ms);
void initPWM(TIM_TypeDef * TIMx);
void setFreq(TIM_TypeDef * TIMx, uint32_t freq);

#endif
