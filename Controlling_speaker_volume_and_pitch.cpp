/**
 * @file main.cpp  
 * @brief This file is for the tasks in module2 task2  
 * Controlling speaker volume and frequency with potentiometers
 * @author Adrian Unkeles and Monish Nene
 * @date nov 2, 2017
 *
 * main.cpp
 */
#include "mbed.h"

PwmOut my_speaker(PB_10);
AnalogIn pot1(PA_0);        //pitch-controlling potentiometer
AnalogIn pot2(PA_1);        //volume-controlling potentiometer

Serial pc(USBTX, USBRX);    //terminal handler

DigitalOut led1(LED1);


/**
 * @brief main()
 * It initializes the speaker setup
 * This function checks the potentiometers and accordingly adjusts the volume and frequency of the speaker
 * It runs an inifite loop for the embedded system
 */
int main() {
    
    float delay;
    float volume_MAX;
    float volume_inc;
    float pot1Val;
    float pot2Val;
    
    // Print the initial banner
    pc.printf("\r\nHello World!\n\n\r");
    
    
    //delay lower limit, 3.125 ms
    //delay upper limit, 0.125 ms
    
    my_speaker.period_ms(10);
    my_speaker.pulsewidth_ms(1);
  
    printf("pwm set to %.2f %%\n", my_speaker.read() * 100);
    
    led1 = !led1;
    
    wait(0.5);
    
    led1 = !led1;
    
    while(1) {
                                //float return represents voltage [0.0 - 1.0]
        pot1Val = pot1.read();  // pitch control
        pot2Val = pot2.read();  // volume control
        
        delay = ((1-pot1Val) * 3000) + 125; //turn pot1 reading into un-scaled period
        
        my_speaker.period(delay/(1000000*20));   //.period() uses float
        
        volume_inc = 0.05*pot2Val;
        volume_MAX = 20*volume_inc;
        
        for(float i = 0; i < volume_MAX; i+= volume_inc)
        {
               my_speaker.write(volume_inc);
               wait(delay/(1000000*20));
        }
        
        led1 = !led1;
    }
}
