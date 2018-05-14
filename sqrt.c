................................../************************************************************************//**
* \file main.c
* \brief LAB EXERCISE 5.2 - SQUARE ROOT APPROXIMATION
*
* Write an assembly code subroutine to approximate the square root of an 
* argument using the bisection method. All math is done with integers, so the 
* resulting square root will also be an integer
******************************************************************************
* GOOD LUCK!
 ****************************************************************************/



 #include "stdint.h"
 
 
 /** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
/************************************************************************//**
* \file main.c
* \brief LAB EXERCISE 5.2 - SQUARE ROOT APPROXIMATION
*
* Write an assembly code subroutine to approximate the square root of an 
* argument using the bisection method. All math is done with integers, so the 
* resulting square root will also be an integer
******************************************************************************
* GOOD LUCK!
 ****************************************************************************/
 #include "stdint.h"
 /** @cond DO_NOT_INCLUDE_WITH_DOXYGEN */
 #include "string.h"
 /** @endcond */
 #include "mbed.h"
 /**
 * @brief 5863 Write a brief description of the function here
 *
 * Detailed description of the function after one line gap
 *..0.
 * @note You can also add a note this way
 *
 * @param[in] 
 *  You can also start writing on a new line. 
 *  And continue on the next line. This is how you describe an input parameter
 *
 * @return
 *  This is how you describe the return value
 * 
 */
 Serial pc(USBTX, USBRX); 
 
__asm int my_sqrt(int dst)
{           
            CMPS r0,#0
            //BEQ end    
            MOV r1, r0
            MOVS r0, #0
sqrtloop    ADDS r0,#1
            MOVS r2, #0 //counter for multiplication
            MOVS r3, #0 
multiply    ADDS r3, r3, r0 // add for multiplication
            ADDS r2,r2,#1 // increment counter
            CMPS r2,r0 // count no. of loops for square
            BNE multiply // branch if not equal 
            CMPS r3,r1
            BCC sqrtloop // branch if no carry till r3 is greater than r1
            BEQ end
            SUBS r0,#1 //decrement sqrt value by 1
end         BX lr// return sqrt value in r0*/
}
    
 int main(void)
{
int r0, j=0;
int i;       
pc.printf("\t squareroot \n"); 
r0=0;          
r0 = my_sqrt(r0);// should be 0
pc.printf("\t squareroot of 0 is %d \n",r0);
r0=25;
r0 = my_sqrt(r0);    // should be 5
pc.printf("\t squareroot of 25 is %d \n",r0);
r0=133;
r0 = my_sqrt(r0);   // should be 11
pc.printf("\t squareroot of 133 is %d \n",r0);
for (i=0; i<10000; i++)
{
r0 = my_sqrt(i);
j+=r0;
}
pc.printf("\n j= %d",j);
}