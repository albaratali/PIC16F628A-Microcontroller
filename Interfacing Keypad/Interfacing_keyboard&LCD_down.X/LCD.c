#include "main.h"


void ToggleEpinOfLCD(void)
{
	LCD_E = 1;                // Give a pulse on E pin
	__delay_us(E_Delay);      // so that LCD can latch the
	LCD_E = 0;                // data from data bus
	__delay_us(E_Delay); 	
}


void WriteCommandToLCD(unsigned char Command)  
{
	LCD_RS = 0;				  			// It is a command
	
	Data_Port &= 0xF0;			  		// Make Data pins zero
	Data_Port |= ((Command&0xF0)>>4);   // Write Upper nibble of data
	ToggleEpinOfLCD();		  			// Give pulse on E pin	
	
	Data_Port &= 0xF0;			  		// Make Data pins zero
	Data_Port |= (Command&0x0F); 		// Write Lower nibble of data
	ToggleEpinOfLCD();		  			// Give pulse on E pin
}


void WriteDataToLCD(char LCDChar)  
{
	LCD_RS = 1;				  // It is data
	
	Data_Port &= 0xF0;			  		// Make Data pins zero
	Data_Port |= ((LCDChar&0xF0)>>4);   // Write Upper nibble of data
	ToggleEpinOfLCD();		  			// Give pulse on E pin	
	
	Data_Port &= 0xF0;			  		// Make Data pins zero
	Data_Port |= (LCDChar&0x0F); 		// Write Lower nibble of data
	ToggleEpinOfLCD();		  			// Give pulse on E pin
}


void InitLCD(void)
{ 
	// Firstly make all pins output
	LCD_E  		 		 = 0;   // E  = 0
	LCD_RS  	 		 = 0;   // RS = 0
	LCD_Data_Bus_D4		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D5		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D6		 = 0;  	// Data bus = 0
	LCD_Data_Bus_D7		 = 0;  	// Data bus = 0
	LCD_E_Dir    		 = 0;   // Make Output
	LCD_RS_Dir    	 	 = 0;   // Make Output
	LCD_Data_Bus_Dir_D4  = 0;   // Make Output
	LCD_Data_Bus_Dir_D5  = 0;   // Make Output
	LCD_Data_Bus_Dir_D6  = 0;   // Make Output
	LCD_Data_Bus_Dir_D7  = 0;   // Make Output

  ///////////////// Reset process from datasheet //////////////
   __delay_ms(40);
   
	Data_Port &= 0xF0;		  // Make Data pins zero
	Data_Port |= 0x03;		  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

   __delay_ms(6);
   
	Data_Port &= 0xF0;		  // Make Data pins zero
	Data_Port |= 0x03;		  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

   __delay_us(300);
   
	Data_Port &= 0xF0;		  // Make Data pins zero
	Data_Port |= 0x03;		  // Write 0x3 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin

   __delay_ms(2);
   
	Data_Port &= 0xF0;		  // Make Data pins zero
	Data_Port |= 0x02;		  // Write 0x2 value on data bus
	ToggleEpinOfLCD();		  // Give pulse on E pin
	
	__delay_ms(2);
  /////////////// Reset Process End ////////////////
	WriteCommandToLCD(0x28);    //function set
	WriteCommandToLCD(0x0c);    //display on,cursor off,blink off
	WriteCommandToLCD(0x01);    //clear display
	WriteCommandToLCD(0x06);    //entry mode, set increment
}


void WriteStringToLCD(const char *s)
{
	while(*s)
		WriteDataToLCD(*s++);   // print first character on LCD 
}


void ClearLCDScreen(void)       // Clear the Screen and return cursor to zero position
{
	WriteCommandToLCD(0x01);    // Clear the screen
	__delay_ms(2);              // Delay for cursor to return at zero position
}