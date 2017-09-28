/***************************************************************************************************
                                   ExploreEmbedded
****************************************************************************************************
 * File:   main.c
 * Version: 16.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: This file contains the program to receive and transmit string through UART and display same on LCD.  

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
#include "LPC17xx.h"
#include "lcd.h"
#include "uart.h"
#include "delay.h" 


int main() 
{

    
    char str[50];  
	int len = 0;  
	SystemInit();

	
    /*Connect RS, RW, EN and data bus to PORT0.4 to PORT0.7*/
    LCD_SetUp(P2_0,P2_1,P2_2,P_NC,P_NC,P_NC,P_NC,P1_24,P1_25,P1_26,P1_27);
    LCD_Init(2,16);
    UART0_Init(9600);
    LCD_DisplayString("send data from  serial terminal");
    while(1)
    {
        len = UART0_RxString(str);
        UART0_Printf("Received String:%s   size=%2d\n\r",str,len);
        LCD_Clear();
        LCD_Printf("str:%s size=%2d",str,len);	 
    }
    
    
}

