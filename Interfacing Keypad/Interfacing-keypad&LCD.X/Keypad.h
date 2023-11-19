/* 
 * File:   Keypad.h
 * Author: faizan
 *
 * Created on November 18, 2023, 3:19 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define Keypad_PORT         PORTB
#define Keypad_PORT_Dir     TRISB

#define ROW1                RB0
#define ROW2                RB1
#define ROW3                RB2
#define ROW4                RB3
#define COL1                RB4
#define COL2                RB5
#define COL3                RB6
#define COL4                RB7

#define HI                                  1
#define LOW                                 0

#define STATE                               1
#define LEVEL                               0

#define ALL_RELEASED                        0xFF 

char GetKey(void);


#endif	/* KEYPAD_H */

