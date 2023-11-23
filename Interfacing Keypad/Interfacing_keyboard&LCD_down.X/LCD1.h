
// Function Declarations for Generic Functions.c

#ifndef __LCD1_H
#define __LCD1_H

// Define Pins
#define LCD_E    			RA7     // Enable pin for LCD
#define LCD_RS	 			RA6     // RS pin for LCD
#define LCD_Data_Bus_D4		RA0		// Data bus bit 4
#define LCD_Data_Bus_D5		RA1		// Data bus bit 5
#define LCD_Data_Bus_D6		RA2		// Data bus bit 6
#define LCD_Data_Bus_D7		RA3		// Data bus bit 7

// Define Pins direction registrers

#define LCD_E_Dir     			TRISA7
#define LCD_RS_Dir   	 		TRISA6
#define LCD_Data_Bus_Dir_D4   	TRISA0
#define LCD_Data_Bus_Dir_D5     TRISA1
#define LCD_Data_Bus_Dir_D6  	TRISA2
#define LCD_Data_Bus_Dir_D7 	TRISA3

// Define Data port
#define Data_Port	PORTA

// Constants
#define E_Delay       500  


// Function Declarations
void WriteCommandToLCD(unsigned char);
void WriteDataToLCD(char);
void InitLCD(void);
void WriteStringToLCD(const char*);
void ClearLCDScreen(void);


#endif