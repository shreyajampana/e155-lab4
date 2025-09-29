// STM32L432KC_TIM.c
// Source code for TIM functions

#include STM32L432KC_TIM.h

void initTIM(TIM_TypeDef * TIM15)

//Set the prescaler
TIM16->PSC = 0;
TIM16->PSC = ;

//Auto-reload register


//Set the UG


//Set the CEN in CR1 - turn on the timer at the end


void delay_millis(TIM_TypeDef * TIM15, uint32_2 ms)




void initPWM(TIM_TypeDef * TIM16)




void setFreq(TIM_TypeDef * TIM16, uint32_2 freq)
//Set to PWM mode



