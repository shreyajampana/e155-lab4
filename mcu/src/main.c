// Shreya Jampana
// Date: 9/29/25
// Description:

//Includes for the libraries
#include "C:\Users\sjampana\e155-lab4-main\mcu\lib\STM32L432KC_TIM.h"
#include "C:\Users\sjampana\e155-lab4-main\mcu\lib\STM32L432KC_RCC.h"
#include "C:\Users\sjampana\e155-lab4-main\mcu\lib\STM32L432KC_GPIO.h"
#include "C:\Users\sjampana\e155-lab4-main\mcu\lib\STM32L432KC_FLASH.h"


//Fur Elise from starter code
//Pitch in Hz, duration in ms
const int notes[][2] = {
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	250},
{  0,	125},
{494,	125},
{523,	125},
{587,	125},
{659,	375},
{392,	125},
{699,	125},
{659,	125},
{587,	375},
{349,	125},
{659,	125},
{587,	125},
{523,	375},
{330,	125},
{587,	125},
{523,	125},
{494,	250},
{  0,	125},
{330,	125},
{659,	125},
{  0,	250},
{659,	125},
{1319,	125},
{  0,	250},
{623,	125},
{659,	125},
{  0,	250},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{416,	125},
{494,	125},
{523,	250},
{  0,	125},
{330,	125},
{659,	125},
{623,	125},
{659,	125},
{623,	125},
{659,	125},
{494,	125},
{587,	125},
{523,	125},
{440,	250},
{  0,	125},
{262,	125},
{330,	125},
{440,	125},
{494,	250},
{  0,	125},
{330,	125},
{523,	125},
{494,	125},
{440,	500},
{  0,	0}};

const float hedwig[][2] = {
{246.9,	250},
{329.6,	375},
{392,	125},
{370,	250},
{329.6,	500},
{493.9,	250},
{440,	750},
{370,	750},
{329.6,	375},
{392,	125},
{370,	250},
{311.1,	500},
{349.2,	250},
{246.9,	750},
{  0,	500},
{246.9,	250},
{329.6,	375},
{392,	125},
{370,	250},
{329.6,	500},
{987.77, 250},
{587.3,	500},
{554.4,	250},
{523.3,	125},
{415.3,	250},
{523.3,	375},
{493.9,	125},
{466.2,	250},
{233.08, 500},
{392,	250},
{329.6,	750},
{  0,	0}};

int main(void) {
	// Configure flash to add waitstates to avoid timing errors
    configureFlash();

    // Setup the PLL and switch clock source to the PLL
    configureClock();

    // Turn on clock to GPIOA
    RCC->AHB2ENR |= (1 << 0);

    // Enabling the timer bits
    RCC->APB2ENR |= (1 << 16);
    RCC->APB2ENR |= (1 << 17);

    // Configuring the GPIOA pin
    pinMode(6, GPIO_ALT);

    // Setting PA6 to be GPIOA 
    GPIO->AFRL &= ~(0b1111 << 24);
    GPIO->AFRL |= (0b1110 << 24);

    // Configure timers 15 and 16
    initTIM(TIM15);
    initPWM(TIM16);


    int length = sizeof(notes) / sizeof(notes[0]);
    int length_hedwig = sizeof(hedwig) / sizeof(hedwig[0]);

    // Writing the for loops
    for (int i = 0; i <= length; i++) {
        setFreq(TIM16, notes[i][0]);
        delay_millis(TIM15, notes[i][1]);
    }

    for (int i = 0; i <= length_hedwig; i++) {
        setFreq(TIM16, hedwig[i][0]);
        delay_millis(TIM15, hedwig[i][1]);
    }
	
} 
