/***************************************************************************************************
                                   ExploreEmbedded
****************************************************************************************************
 * File:   main.c
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: This file contains the program to demonstrate the LED blinking. 

The libraries have been tested on ExploreEmbedded development boards. We strongly believe that the
library works on any of development boards for respective controllers. However, ExploreEmbedded
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information
related to updates.


GNU GENERAL PUBLIC LICENSE:
    Copyright (C) 2012  ExploreEmbedded

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


Errors and omissions should be reported to codelibraries@exploreembedded.com
**************************************************************************************************/


#include <lpc17xx.h>

void delay_ms(unsigned int count)
{
  unsigned int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    DELAY of 10 us */
    for(i=0;i<30000;i++);
  }
}


/* start the main program */
int main() 
{
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL4 = 0x000000; //Configure the Pins for GPIO;
    LPC_GPIO2->FIODIR = 0xffffffff;  //Configure the PORT pins as OUTPUT;

  while(1)
    {

     /* Turn ON all the leds and wait for one second */ 
       LPC_GPIO2->FIOSET = 0xffffffff;     // Make all the Port pins as high  
       delay_ms(50);

     /* Turn OFF all the LEDs and wait for one second */ 
       LPC_GPIO2->FIOCLR = 0xffffffff;     // Make all the Port pins as low  
       delay_ms(50);
    }

							  
}

