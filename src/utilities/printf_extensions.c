/*
 * printf_extensions.c
 *
 *  Created on: Dec 15, 2012
 *      Author: Michal Banasiak
 */

#include "printf_extensions.h"

/* http://www.jb.man.ac.uk/~slowe/cpp/itoa.html */
	char* itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }

		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;

		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
		} while ( value );

		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}

	/*http://www.microchip.com/forums/m183763.aspx */

/**************************************************
 *
 *    ftoa - converts float to string
 *
 ***************************************************
 *
 *    This is a simple implemetation with rigid
 *    parameters:
 *            - Buffer must be 8 chars long
 *            - 3 digits precision max
 *            - absolute range is -524,287 to 524,287
 *            - resolution (epsilon) is 0.125 and
 *              always rounds down
 **************************************************/
 void ftoa(float Value, char* Buffer)
 {
     union
     {
         float f;

         struct
         {
             unsigned int    mantissa_lo : 16;
             unsigned int    mantissa_hi : 7;
             unsigned int     exponent : 8;
             unsigned int     sign : 1;
         };
     } helper;

     unsigned long mantissa;
     signed char exponent;
     unsigned int int_part;
     char frac_part[3];
     int i, count = 0;

     helper.f = Value;
     //mantissa is LS 23 bits
     mantissa = helper.mantissa_lo;
     mantissa += ((unsigned long) helper.mantissa_hi << 16);
     //add the 24th bit to get 1.mmmm^eeee format
     mantissa += 0x00800000;
     //exponent is biased by 127
     exponent = (signed char) helper.exponent - 127;

     //too big to shove into 8 chars
     if (exponent > 18)
     {
         Buffer[0] = 'I';
         Buffer[1] = 'n';
         Buffer[2] = 'f';
         Buffer[3] = '\0';
         return;
     }

     //too small to resolve (resolution of 1/8)
     if (exponent < -3)
     {
         Buffer[0] = '0';
         Buffer[1] = '\0';
         return;
     }

     count = 0;

     //add negative sign (if applicable)
     if (helper.sign)
     {
         Buffer[0] = '-';
         count++;
     }

     //get the integer part
     int_part = mantissa >> (23 - exponent);
     //convert to string
     itoa(int_part,&Buffer[count], 10);

     //find the end of the integer
     for (i = 0; i < 8; i++)
         if (Buffer[i] == '\0')
         {
             count = i;
             break;
         }

     //not enough room in the buffer for the frac part
     if (count > 5)
         return;

     //add the decimal point
     Buffer[count++] = '.';

     //use switch to resolve the fractional part
     switch (0x7 & (mantissa  >> (20 - exponent)))
     {
         case 0:
             frac_part[0] = '0';
             frac_part[1] = '0';
             frac_part[2] = '0';
             break;
         case 1:
             frac_part[0] = '1';
             frac_part[1] = '2';
             frac_part[2] = '5';
             break;
         case 2:
             frac_part[0] = '2';
             frac_part[1] = '5';
             frac_part[2] = '0';
             break;
         case 3:
             frac_part[0] = '3';
             frac_part[1] = '7';
             frac_part[2] = '5';
             break;
         case 4:
             frac_part[0] = '5';
             frac_part[1] = '0';
             frac_part[2] = '0';
             break;
         case 5:
             frac_part[0] = '6';
             frac_part[1] = '2';
             frac_part[2] = '5';
             break;
         case 6:
             frac_part[0] = '7';
             frac_part[1] = '5';
             frac_part[2] = '0';
             break;
         case 7:
             frac_part[0] = '8';
             frac_part[1] = '7';
             frac_part[2] = '5';
             break;
     }

     //add the fractional part to the output string
     for (i = 0; i < 3; i++)
         if (count < 7)
             Buffer[count++] = frac_part[i];

     //make sure the output is terminated
     Buffer[count] = '\0';
 }
