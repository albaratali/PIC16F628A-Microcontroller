/*
 * File:   LED.c
 * Author: faizan
 *
 * Created on November 19, 2023, 10:35 AM
 */


#include <xc.h>
#include "LED.h"

#pragma config WDTE =OFF // watchdog timer disabled

void InitLCD(void) {
    // write your initialization code here
     /* Setting the RS and EN lines as Output */
    LCD_E_DIR=0;
    LCD_RS_DIR =0;
    
      /* Setting the LCD Data Port as Output */
    LCD_DATA_BUS_DIR=LCD_DATA_BUS_DIR | 0xF0;
    
     init_display_controller();
}

static void init_display_controller(void)
{
    /* Startup Time for the CLCD controller */
    __delay_ms(30);
    
    /* The CLCD Startup Sequence */
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(4100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(100);
    clcd_write(EIGHT_BIT_MODE, INST_MODE);
    __delay_us(1); 
    
    clcd_write(FOUR_BIT_MODE, INST_MODE);
    __delay_us(100);
    clcd_write(TWO_LINES_5x8_4_BIT_MODE, INST_MODE);
    __delay_us(100);
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
    clcd_write(DISP_ON_AND_CURSOR_OFF, INST_MODE);
    __delay_us(100);
}

void clcd_putch(const char data, unsigned char addr)
{
    clcd_write(addr, INST_MODE);
    clcd_write(data, DATA_MODE);
}

void clcd_write(unsigned char byte, unsigned char mode)   // byte -> 'A', 1
{
    LCD_RS = (__bit)mode;
    
    LCD_DATA_BUS = byte & 0xF0;   // 0x41 & 0xF0 : 0x40 : 0100 0000 (RD7 to RD4)
    LCD_E = HI;
    __delay_us(100);
    LCD_E = LOW;

    LCD_DATA_BUS = (unsigned char)((byte & 0x0F) << 4); // 0x41 & 0x0F : 0000 0001 << 4 = PORTD 
    LCD_E = HI;
    __delay_us(100);
    LCD_E = LOW;
    
    __delay_us(4100); // 4.1msec
}