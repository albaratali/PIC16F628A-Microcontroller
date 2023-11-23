/*
 * File:   main.c
 * Author: abamishu
 *
 * Created on November 18, 2023, 2:49 PM
 */


#include <xc.h>
#include "Keypad.h"
#include "LED.h"

void ClearLCDScreen(void);
void InitKeypad(void);
void InitLCD(void);

#pragma config WDTE =OFF // watchdog timer disabled

static void init_config(void) {
    // write your initialization code here
    
    InitKeypad();
    InitLCD();
}

void main(void) {
    init_config(); // calling initializing function
    unsigned char key;
   // CMCON =0x07;
    
    while (1) {
        // write application code here
        key=GetKey();
        ClearLCDScreen();
        clcd_putch(key,LINE1(5));
    }

}

