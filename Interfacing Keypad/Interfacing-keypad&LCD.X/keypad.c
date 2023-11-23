/*
 * File:   keypad.c
 * Author: abamishu
 *
 * Created on November 18, 2023, 2:53 PM
 */


#include <xc.h>
#include "Keypad.h"

#pragma config WDTE =OFF // watchdog timer disabled

void InitKeypad(void) {
    // write your initialization code here

    
    Keypad_PORT_Dir=0x0F;//setting RB0-RB3 as a input & RB4-RB7 as a output
    
    OPTION_REGbits.nRBPU = 0; // Enable internal pull-ups
   
    ROW1=HI;
    ROW2=HI;
    ROW3=HI;
    ROW4=HI;
    
}

static unsigned char scan_keypad(void){
 
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


unsigned char GetKey(void)
{
   unsigned char key;
    while(1){
        key=scan_keypad();
        return key;
    }
}   