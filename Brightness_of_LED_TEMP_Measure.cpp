/**
 * @file main.cpp 
 * @brief This file is for the tasks in module3 
 * Blinking LED, Brightness of LED, Display Temperature on LCD and Display an incrementing count on LCD.
 * @author Adrian Unkeles and Monish Nene
 * @date nov 4, 2017
 *
 * main.cpp
 */
#include "mbed.h"
#include "NHD_0216HZ.h"
#include "pindef.h"
#include "rtos.h"

//#include "Mutex.h"
Serial pc(USBTX, USBRX);            //terminal handler
AnalogIn pot1(PA_1);                //brightness
DigitalOut led1(LED1);
PwmOut led2(PB_10);                 //external LED
I2C temp_sensor(I2C_SDA, I2C_SCL);
NHD_0216HZ lcd(SPI_CS, SPI_MOSI, SPI_SCLK);
unsigned char countx=0;

Mutex lcd_mutex;                   //protection for shared resource
Mutex pc_mutex;

/**
 * @brief display_count()
 * This function prints and increments a count.
 * mutex is used to lock and unlock the LCD to avoid printing wrong information.
 */

void display_count(void)
{
   pc_mutex.lock();
   pc.printf("count = %d",countx);
   pc_mutex.unlock();
   
   lcd.set_cursor(0,0);
   
   lcd_mutex.lock();
   lcd.printf("count = %d", countx);
   lcd_mutex.unlock();
   
   countx++;
   
   return;
}

/**
 * @brief count_thread()
 * This function calls display_count() every 1000ms using RTOS Thread.
 * After completion of the task it sends the CPU to sleep.
 * argument pointer to be passed for the RTOS thread function.
 */

void count_thread(void const *argument)
{
    while(1)
    {
       Thread::wait(1000);
       display_count();    
       sleep();
    }    
}


/**
 * @brief display_temp()
 * This function take the input from the I2C from the temperature sensor IC and displays it.
 * mutex is used to lock and unlock the LCD to avoid printing wrong information.
 */
void display_temp(void)
{
   float temp;
   const int temp_addr = 0x90;
   char cmd1=0x51,cmd2=0xAA;
   char read_temp[2];
   temp_sensor.write(temp_addr, &cmd1, 1);
   wait(0.5);
   temp_sensor.write(temp_addr, &cmd2, 1);
   temp_sensor.read(temp_addr, read_temp, 2);
   temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
   
   pc_mutex.lock();
   pc.printf("temperature = %fC",temp);  
   pc_mutex.unlock();
   
   lcd.set_cursor(0,1);
   
   lcd_mutex.lock();
   lcd.printf("temp = %fC", temp);
   lcd_mutex.unlock();
   
   return;
}

/**
 * @brief temp_thread()
 * This function calls display_temp() every 500ms time using RTOS Thread.
 * After completion of the task it sends the CPU to sleep.
 * argument pointer to be passed for the RTOS thread function.
 *
void temp_thread(void const *argument)
{
    while(1)
    {
       Thread::wait(500);
       display_temp();   
       sleep(); 
    }    
}


/**
 * @brief LED_brightness()
 * This function senses the potentiometer value and adjusts brightness of LED accordingly.
 */

void LED_brightness(void)
{
    float brightness;
    brightness = pot1.read();
    pc.printf("brightness = %f",brightness);
    //led2.pulsewidth_ms(1);
    led2.period(0.001);   //.period() uses float
    led2.write(1-0.2*(brightness));
    return; 
}

/**
 * @brief brightness_thread()
 * This function calls LED_brightness() every 200ms using RTOS Thread.
 * After completion of the task it sends the CPU to sleep.
 * argument pointer to be passed for the RTOS thread function.
 */
void brightness_thread(void const *argument)
{
    while(1)
    {
       Thread::wait(200);
       LED_brightness(); 
       sleep();   
    }    
}


/**
 * @brief LED_blink()
 * This function toggles a LED.
 */
void LED_blink(void)
{
    led1 = !led1;
    return;
}


/**
 * @brief blink_thread()
 * This function calls LED_blink() every 500ms using RTOS Thread.
 * After completion of the task it sends the CPU to sleep.
 * argument pointer to be passed for the RTOS thread function.
 */
void blink_thread(void const *argument)
{
    while(1)
    {
       Thread::wait(500);
       LED_blink();    
       sleep();
    }    
}

/**
 * @brief main()
 * It initializes the LCD. 
 * This functions initializes RTOS threads. 
 * It runs an inifite loop for the embedded system.
 */

int main()
{
   lcd.init_lcd();
   Thread thread1(blink_thread,NULL,osPriorityNormal, DEFAULT_STACK_SIZE);
   Thread thread2(count_thread,NULL,osPriorityNormal, DEFAULT_STACK_SIZE);
   Thread thread3(brightness_thread,NULL,osPriorityNormal, DEFAULT_STACK_SIZE);
   Thread thread4(temp_thread,NULL,osPriorityNormal, DEFAULT_STACK_SIZE);
   while(1)
    {
        
    }
   return 1;
}