// STM32L432KC_TIM.c
// Source code for TIM functions

#include "STM32L432KC_TIM.h"


void initTIM(TIM_TypeDef * TIMx) {
    //Set the prescaler
    TIMx->PSC = 7999;

    //Setting the auto-reload register to buffer
    TIMx->CR1 |= (1 << 7);

    //Set the UG
    TIMx->EGR |= (1 << 0);

    //Set the CEN in CR1 - turn on the timer at the end
    TIMx->CR1 |= (1 << 0);
}


void delay_millis(TIM_TypeDef * TIMx, uint32_t ms) {
    //Set the ARR
    TIMx->ARR = (TICKS_PER_MS_DELAY * ms);

    //Setting the UG to start the counter and upload the ARR value
    TIMx->EGR |= (1 << 0); 

    //Setting the counter to 0 to begin with
    TIMx->CNT = 0;
    
    //Clear the update interrupt flag once the counter is reset
    TIMx->SR &= ~(1 << 0);

    //Wait until the interrupt flag goes high again
    while (!(TIMx->SR & (1<<0)));

    //Clear the update interrupt flag
    TIMx->SR &= ~(1 << 0);
}


void initPWM(TIM_TypeDef * TIMx) {
    //Set the prescaler
    TIMx->PSC = 7;
    
    //Selecting the PWM mode 1
    TIMx->CCMR1 |= (0b110 << 4);
    
    //Enabling the preload register
    TIMx->CCMR1 |= (1 << 3);

    //Setting OC1 polarity
    TIMx->CCER &= ~(1 << 1);

    //Set the auto reload preload register
    TIMx->CR1 |= (1 << 7);

    //Enabling OCx output with a combination of bits found in two different registers
    TIMx->CCER |= (1 << 0); //CC1E set to 1
    //TIM16->CCER |= (1 << 2); //CC1NE set to 1
    //TIM16->BDTR |= (1 << 11); //OSSR set to 1
    TIMx->BDTR |= (1 << 15); //MOE set to 1

    //Setting the UG but to upload shadow registers
    TIMx->EGR |= (1 << 0);

    //Set the CEN in CR1 - turn on the timer at the end
    TIMx->CR1 |= (1 << 0);
}



void setFreq(TIM_TypeDef * TIMx, uint32_t freq){
    //Calculating the arr and ccr values
    uint32_t arr = (1000)*TICKS_PER_MS_FREQ/freq;
    uint32_t ccr = arr/2;

    //Setting ARR and CCR1
    if(freq != 0) {
        //Set the CEN in CR1 - turn on the timer at the end
        //TIMx->CR1 |= (1 << 0);

        TIMx->ARR = arr;
        TIMx->CCR1 = ccr;

    } else {
        TIMx->ARR = 0;
        TIMx->CCR1 = 0;
        //TIMx->CR1 &= ~(1 << 0);
    }

    //Setting the UG but to upload shadow registers
    TIMx->EGR |= (1 << 0);

}
