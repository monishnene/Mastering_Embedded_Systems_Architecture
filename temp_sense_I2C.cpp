/**
 * @file main.cpp  
 * @brief This file is for the tasks in module2 task3 
 * Getting input from Temperaturer sensor IC using I2C
 * Displaing Temperature on LCD screen
 * @author Adrian Unkeles and Monish Nene
 * @date nov 3, 2017
 *
 * main.cpp
 */

#include "NHD_0216HZ.h"
#include "pindef.h"
#include "mbed.h"

//Define the LCD and the temperature sensor

NHD_0216HZ lcd(PB_6, PA_7, PA_5);
I2C temp_sensor(I2C_SDA, I2C_SCL);
Serial pc(USBTX, USBRX);

/**
 * @brief display_temp()
 * This function take the input from the I2C from the temperature sensor IC and displays it
 */
void display_temp(void)         //Note, we didn't use the DS1631 class.
{                               //We moved the read() here to main.cpp, and
                                //initialized an I2C temp_sensor object instead
   float temp;
   const int temp_addr = 0x90;
   char cmd1=0x51,cmd2=0xAA;
   char read_temp[2];
   temp_sensor.write(temp_addr, &cmd1, 1);
   wait(0.5);
   temp_sensor.write(temp_addr, &cmd2, 1);
   temp_sensor.read(temp_addr, read_temp, 2);
   temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
   
   lcd.set_cursor(0,1);
   lcd.printf("temp = %fC", temp);
   
   //pc.printf("temperature = %fC",temp);
   return;
}

/**
 * @brief main()
 * It initializes the LCD 
 * This function calls the display_temp() function 
 * It runs an inifite loop for the embedded system
 */
int main() {
    //Initialise the LCD
    lcd.init_lcd();
    
    lcd.set_cursor(0,0);
    lcd.printf("Hello World!");
    
    while(1)
    {
        display_temp();
        wait(0.5);    
    }
    
    return 0;
}
