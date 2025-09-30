// STM32L432KC_TIM.c
// Source code for TIM functions

#include STM32L432KC_TIM.h


void initTIM(TIM_TypeDef * TIM15) {
    //Set the prescaler
    TIM15->PSC = 800;

    //Setting the auto-reload register to buffer
    TIM15->CR1 |= (1 << 7);

    //Set the UG
    TIM15->EGR |= (1 << 0);

    //Set the CEN in CR1 - turn on the timer at the end
    TIM15->CR1 |= (1 << 0);
}


void delay_millis(TIM_TypeDef * TIM15, uint32_2 ms) {
    //Set the ARR
    TIM15->ARR = (TICKS_PER_MS * ms);

    //Setting the counter to 0 to begin with
    TIM15->CNT = 0;
    
    //Clear the update interrupt flag once the counter is reset
    TIM15->SR &= ~(1 << 0);

    //Setting the UG to start the counter and upload the ARR value
    TIM15->EGR |= (1 << 0); 

    //Wait until the interrupt flag goes high again
    while (!(TIM15->SR & (1<<0)));

    //Clear the update interrupt flag
    TIM15->SR &= ~(1 << 0);
}


void initPWM(TIM_TypeDef * TIM16) {
    //Set the prescaler
    TIM16->PSC = 7;
    
    //Selecting the PWM mode 1
    TIM16->CCMR1 |= (0b110 << 4);
    
    //Enabling the preload register
    TIM16->CCMR1 |= (1 << 3);

    //Set the auto reload preload register
    TIM16->CR1 |= (1 << 7);

    //Setting OC1 polarity
    TIM16->CCER &= ~(1 << 1);

    //Enabling OCx output with a combination of bits found in two different registers
    TIM16->CCER |= (1 << 0); //CC1E set to 1
    //TIM16->CCER |= (1 << 2); //CC1NE set to 1
    //TIM16->BDTR |= (1 << 11); //OSSR set to 1
    TIM16->BDTR |= (1 << 15); //MOE set to 1

    //Setting the UG but to upload shadow registers
    TIM16->EGR |= (1 << 0);

    //Set the CEN in CR1 - turn on the timer at the end
    TIM16->CR1 |= (1 << 0);
}



void setFreq(TIM_TypeDef * TIM16, uint32_2 freq){
    //Calculating the arr and ccr values
    uint32_t arr = (1/freq)*(1000)*TICKS_PER_MS;
    uint32_t ccr = arr/2;

    //Setting ARR and CCR1
    if(freq != 0) {
        TIM16->ARR = arr;
        TIM16->CCR1 = ccr;

        //Setting the UG but to upload shadow registers
        TIM16->EGR |= (1 << 0);

        //Set the CEN in CR1 - turn on the timer at the end
        TIM16->CR1 |= (1 << 0);
    } else {
        TIM16->ARR = 0;
        TIM16->CCR1 = 0;
        TIM16->CR1 &= ~(1 << 0);
    }

}