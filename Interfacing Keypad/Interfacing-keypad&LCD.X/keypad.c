/*
 * File:   keypad.c
 * Author: faizan
 *
 * Created on November 18, 2023, 2:53 PM
 */


#include <xc.h>
#include "Keypad.h"
#define _XTAL_FREQ      20000000
#pragma config WDTE =OFF // watchdog timer disabled

void InitKeypad(void) {
    // write your initialization code here

    Keypad_PORT=0x00;
    Keypad_PORT_Dir=0xF0;
    nRBPU=0;
    //Option_REG &= 0x7F;
    ROW1=HI;
    ROW2=HI;
    ROW3=HI;
    ROW4=HI;
    
    
    
    
}

static unsigned char scan_keypad(void){
    int i;
    ROW1=LOW;
    ROW2=HI;
    ROW3=HI;
    ROW4=HI;
    
    __delay_ms(250);
    
    if(COL1==LOW){
        return 7;
    }
    
    else if(COL2==LOW){
        return 8;
    }
    
    else if(COL3==LOW){
        return 9;
    }
    else if(COL4==LOW){
        return '/';
    }
    ROW1=HI;
    ROW2=LOW;
    ROW3=HI;
    ROW4=HI;
    
     __delay_ms(250);
    
    if(COL1==LOW){
        return 4;
    }
    
    else if(COL2==LOW){
        return 5;
    }
    
    else if(COL3==LOW){
        return 6;
    }
    else if(COL4==LOW){
        return 'X';
    }
            
    ROW1=HI;
    ROW2=HI;
    ROW3=LOW;
    ROW4=HI;
    
    __delay_ms(250);
    
    if(COL1==LOW){
        return 1;
    }
    
    else if(COL2==LOW){
        return 2;
    }
    
    else if(COL3==LOW){
        return 3;
    }
    else if(COL4==LOW){
        return '-';
    }
    
    ROW1=HI;
    ROW2=HI;
    ROW3=HI;
    ROW4=LOW;
    
    __delay_ms(250);
    
    if(COL1==LOW){
        return 'C';
    }
    
    else if(COL2==LOW){
        return '0';
    }
    
    else if(COL3==LOW){
        return '=';
    }
    else if(COL4==LOW){
        return '+';
    }
    return ALL_RELEASED;
    
}


char GetKey()
{
   unsigned char key= ALL_RELEASED;
    while(key==ALL_RELEASED){
        key=scan_keypad();
        return key;
    }
}   