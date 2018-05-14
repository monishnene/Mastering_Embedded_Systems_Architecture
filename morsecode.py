/**
 * @file morsecode.py
 * @brief This code is for the extra crdit task Morse code
 * This file decodes input from GPIO which is morse code on BBB and displays result on  Terminal
 * @author Monish Nene
 * @date dec 2, 2017
 *
 * morsecode.py
 */

import Adafruit_BBIO.GPIO as GPIO
button="P9_15"
from time import sleep
GPIO.setup(button,GPIO.IN)
x=0
symbol='1'
count=0

while(1):
sleep(0.2)
x=0
 	state=GPIO.input(button)
if(symbol=='._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'A'
							symbol='1'
elif(symbol=='_...1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'B' 
							symbol='1'

elif(symbol=='_._.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'C'
							symbol='1'

elif(symbol=='_..1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'D'
							symbol='1'

elif(symbol=='.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'E'
							symbol='1'

elif(symbol=='.._.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'F'
							symbol='1'

elif(symbol=='__.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'G'
							symbol='1'

elif(symbol=='....1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'H' 
							symbol='1'

elif(symbol=='..1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'I' 
							symbol='1'

elif(symbol=='.___1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'J' 
							symbol='1'

elif(symbol=='_._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'K' 
							symbol='1'

elif(symbol=='._..1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'L' 
							symbol='1'

elif(symbol=='__1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'M' 
							symbol='1'

elif(symbol=='_.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'N' 
							symbol='1'

elif(symbol=='___1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'O'
							symbol='1'
 
elif(symbol=='.__.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'P'
							symbol='1'


elif(symbol=='___._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'Q' 
							symbol='1'

elif(symbol=='._.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'R' 
							symbol='1'

elif(symbol=='...1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'S' 
							symbol='1'
elif(symbol=='_1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'T' 
							symbol='1'

elif(symbol=='.._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'U' 
							symbol='1'

elif(symbol=='..._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'V' 
							symbol='1'

elif(symbol=='.__1' and state!=0):	
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'W' 
							symbol='1'

elif(symbol=='_.._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'X' 
							symbol='1'

elif(symbol=='_.__1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'Y' 
							symbol='1'
	
elif(symbol=='__..1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'Z' 
							symbol='1'

elif(symbol=='._____1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'1' 
							symbol='1'

elif(symbol=='..____1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'2' 
							symbol='1'

elif(symbol=='...__1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'3' 
							symbol='1'

elif(symbol=='...._1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'4' 
							symbol='1'

elif(symbol=='.....1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'5' 
							symbol='1'

elif(symbol=='_....1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'6' 
							symbol='1'

elif(symbol=='__...1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'7' 
							symbol='1'

elif(symbol=='___..1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'8' 
							symbol='1'

elif(symbol=='____.1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'9' 
							symbol='1'

elif(symbol=='_____1' and state!=0):
                                        state=GPIO.input(button)
                                        sleep(0.25)
                                        state=GPIO.input(button)
                                        if(state!=0):
                                        	print'0'
							symbol='1'

state=GPIO.input(button)
while(state==0):
                if(state==0):
                                x=x+1
                sleep(0.2)
                state=GPIO.input(button)
                if(state==0):
                                x=x+1
                if(x==1):
                        print'.'
                        symbol='.'+ symbol
                        print "sym= ",symbol
                        count=count+1
                if(x==2):
                        print'_'
                        symbol='_'+symbol
                        print"sym= ",symbol
                        count=count+1


GPIO.cleanup()

