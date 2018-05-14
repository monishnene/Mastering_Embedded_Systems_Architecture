/**
 * @file main.cpp  
 * @brief This file is for the tasks in module2 task1  
 * Control LED using Buttons with interrupts
 * @author Adrian Unkeles and Monish Nene
 * @date nov 1, 2017
 *
 * main.cpp
 */
#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(PA_9);

InterruptIn button11(PB_4);
InterruptIn button22(PB_5);
InterruptIn button33(PB_3);
InterruptIn button44(PA_10);

void button11_ISR()
{
    led1 = 1;   
}

void button22_ISR()
{
    led1 = 0;   
}

void button33_ISR()
{
    led2 = 1;   
}

void button44_ISR()
{
    led2 = 0;   
}



/**
 * @brief main()
 * This function check the buttons with hardware interrupts and according to their status turns LEDS ON and OFF
 * It runs an inifite loop for the embedded system which puts the CPU to sleep and waits for interrupts
 */
// main() runs in its own thread in the OS
int main() {
    
    led1 = 1;       //LED-testing initialization
    led2 = 1;
    wait(0.5);
    led1 = 0;
    led2 = 0;
    wait(0.5);
    
    button11.rise(&button11_ISR);
    button22.rise(&button22_ISR);
    button33.rise(&button33_ISR);
    button44.rise(&button44_ISR);
    
    while(1)
    {
        sleep();    
    }
}

