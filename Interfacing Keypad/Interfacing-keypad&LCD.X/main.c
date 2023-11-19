/*
 * File:   main.c
 * Author: faizan
 *
 * Created on November 18, 2023, 2:49 PM
 */


#include <xc.h>
#include "Keypad.h"
#include "LED.h"

void ClearLCDScreen(void);
char GetKey(void);
void InitKeypad(void);
void InitLCD(void);
void clcd_write(unsigned char byte, unsigned char mode) ;
void clcd_print(const char *str, unsigned char addr);

#pragma config WDTE =OFF // watchdog timer disabled

static void init_config(void) {
    // write your initialization code here
    
    InitKeypad();
    InitLCD();
}

void main(void) {
    init_config(); // calling initializing function
    unsigned char key='n';
    CMCON =0x07;
    
    while (1) {
        // write application code here
        key=GetKey();
        ClearLCDScreen();
        clcd_putch(key,LINE1(5));
    }

}
void ClearLCDScreen(void)
{
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
    __delay_us(500);
}
