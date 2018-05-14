 /**
 * @file main.cpp 
 * @brief This file is for the tasks in module4 
 * Generating sine values and printong them on the terminal
 * @author Adrian Unkeles and Monish Nene
 * @date nov 5, 2017
 *
 * main.cpp
 */
#include "mbed.h"
#include "rtos.h"
#include <math.h>
#define pi 3.14159
//PwmOut my_speaker(PB_10);
Serial pc(USBTX, USBRX);    //terminal handler

unsigned int count;



/**
 * @brief display_sine()
 * This Function calculates the values of the sine wave and print them on the terminal.
 */
void display_sine(void)
{
    float x=0,y=0;
    if(count+1==20)
    {
        count=0;    
    }
    else
    {
        count++;
    }
    x=sin((2*pi*count)/20);
    y=(0.5*x)+0.5;
    pc.printf("%f,",y);
}


/**
 * @brief main()
 * This function calls the display_sine() function.
 * It runs an inifite loop for the embedded system.
 */
int main() 
{
    while(1)
     {
        display_sine();
     }
    return 1; 
}