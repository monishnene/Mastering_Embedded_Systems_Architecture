/**
 * @file main.cpp 
 * @brief This file is for the tasks in module4 
 * Reading sine values for 1004 Hz Frequency from a .txt file.
 * Adjusting the Brightness of LED according to the values in sine_data.
 * @author Adrian Unkeles and Monish Nene
 * @date nov 5, 2017
 *
 * main.cpp
 */

#include "mbed.h"
#include "sine_data.h"
#include "pindef.h"

PwmOut led2(PB_10);

/**
 * @brief main()
 * This function read a value from the sine_array and adjusts the brightness of the LED according to it.
 * It runs an inifite loop for the embedded system.
 */

int main()
{
float brightness = 0,i=0;
unsigned int count=0;
float* sine_ptr;
sine_ptr = &sine_array;
while(1)
{
    brightness = sine_array[count];
    led2.period(0.001);   //.period() uses float
    led2.write(1-0.2*(brightness));
    pc.printf("brightness=%f\n\r",brightness);
    if(count+1==99)
    {
        count=0;    
    }
    else
    {
        count++;
    }
}  
return 1;
}    

