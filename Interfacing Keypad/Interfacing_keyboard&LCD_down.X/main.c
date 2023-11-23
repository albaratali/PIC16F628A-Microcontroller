
#include "main.h"
// PIC16F628A Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


// Main function
void main()
{	
	char Key = 'n';		 // Variable to store pressed key value
    
	CMCON = 0x07;		 // Turn off comparator

	InitKeypad();		 // Initialize Keypad pins
	InitLCD();			 // Initialize LCD in 8bit mode
	
	while(1)
	{
		Key = GetKey();		 // Get pressed key from keypad
		ClearLCDScreen();	 // Clear LCD screen
		WriteDataToLCD(Key); //	Update LCD with current key value
	}
}


