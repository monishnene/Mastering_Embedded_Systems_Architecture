/**
 * @file main.cpp  
 * @brief This file is for the tasks in module2 task1  
 * Control LED using Buttons
 * @author Adrian Unkeles and Monish Nene
 * @date nov 1, 2017
 *
 * main.cpp
 */

#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(PA_9);

DigitalIn button1(PB_4);
DigitalIn button2(PB_5);
DigitalIn button3(PB_3);
DigitalIn button4(PA_10);

BusIn My_Bus_In(PB_4, PB_5, PB_3, PA_10);
BusOut My_Bus_Out(LED1, PA_9);

/**
 * @brief main()
 * This function checks the buttons and according to their status turns LEDS ON and OFF
 * It runs an inifite loop for the embedded system
*/
// main() runs in its own thread in the OS
int main() {
    
    led1 = 0;       //LED-testing initialization
    led2 = 1;
    wait(0.5);
    led1 = 1;
    led2 = 0;
    wait(0.5);
    led2 = 0;
    wait(0.5);
    
    while(true)
    {                                      //Button default state is 1, pressed is 0 
        if((My_Bus_In | 0xE) == 0xE)
            My_Bus_Out = 0x1;
        else if ((My_Bus_In | 0xD) == 0xD)
            My_Bus_Out = 0x0;
                                            //Separate if-statements to control separate LEDs
       if((My_Bus_In | 0xB) == 0xB)
            My_Bus_Out = 0x2;
        else if ((My_Bus_In | 0x7) == 0x7)
            My_Bus_Out = 0x0;   
            
            
       /* if(button1 == 0)                  //Initial tests using DigitalIn and DigitalOut objects directly
            led1 = 1;       
        else if (button2 == 0)
            led1 = 0;*/
                                    
        /*if (button3 == 0)
            led2 = 1;
        else if (button4 == 0)
            led2 = 0; */
    }
}

