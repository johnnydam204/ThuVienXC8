/* 
 * File:   myLCD.h
 * Author: duand
 *
 * Created on 05 January 2017, 10:47
 */

#ifndef MYLCD_H
#define	MYLCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
// Dinh danh phan cung
#define LCD_RS  LATDbits.LATD0
#define LCD_RW  LATDbits.LATD1
#define LCD_EN  LATDbits.LATD2
    
#define LCD_D4  LATDbits.LATD3
#define LCD_D5  LATDbits.LATD4
#define LCD_D6  LATDbits.LATD5
#define LCD_D7  LATDbits.LATD6
    
// Dinh danh thanh ghi huong du lieu TRIS
#define LCD_RS_TRIS     TRISDbits.TRISD0
#define LCD_RW_TRIS     TRISDbits.TRISD1
#define LCD_EN_TRIS     TRISDbits.TRISD2
    
#define LCD_D4_TRIS     TRISDbits.TRISD3
#define LCD_D5_TRIS     TRISDbits.TRISD4
#define LCD_D6_TRIS     TRISDbits.TRISD5
#define LCD_D7_TRIS     TRISDbits.TRISD6
    
// Khai bao danh sach ham can dung (khai bao nguyen mau cua ham)
    // Ham truyen di nua byte
    void lcdNible(char nible);
    
    // Ham truyen di ca byte
    void lcdByte(char byte);
    
    // Ham truyen di ma lenh
    void lcdCmd(char cmd);
    
    // Ham truyen di ky tu
    void lcdPutc(char chr);
    
    // Ham truyen di chuoi ky tu
    void lcdPuts(char *str);
    
    // Ham xac dinh toa do hien thi (toa do con tro)
    void lcdGotoxy(char col, char row);
    
    // Ham khoi tao LCD
    void lcdInit(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MYLCD_H */

