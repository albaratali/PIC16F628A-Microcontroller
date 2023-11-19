/* 
 * File:   LED.h
 * Author: faizan
 *
 * Created on November 19, 2023, 10:36 AM
 */

#ifndef LED_H
#define	LED_H

#define _XTAL_FREQ                  20000000

#define LCD_E                       RA7
#define LCD_RS                      RA6

#define LCD_E_DIR                   TRISA7
#define LCD_RS_DIR                  TRISA6

#define LCD_DATA_BUS                PORTA

#define LCD_DATA_BUS_DIR            TRISA



#define INST_MODE                   0
#define DATA_MODE                   1

#define HI                          1
#define LOW                         0

#define LINE1(x)                    (0x80 + x)//0x80 0x81 
#define LINE2(x)                    (0xC0 + x)// 0xC0
//#define LINE3(x)                    (0x90 + x)
//#define LINE4(x)                    (0xD0 + x)


#define EIGHT_BIT_MODE              0x33
#define FOUR_BIT_MODE               0x02
#define TWO_LINES_5x8_4_BIT_MODE    0x28
#define CLEAR_DISP_SCREEN           0x01
#define DISP_ON_AND_CURSOR_OFF      0x0C


static void init_display_controller(void);
void clcd_print(const char *str, unsigned char addr);
void clcd_putch(const char data, unsigned char addr);
void clcd_write(unsigned char byte, unsigned char mode) ;
#endif	/* LED_H */

