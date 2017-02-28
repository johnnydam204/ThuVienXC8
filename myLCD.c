#include <xc.h>
#include "myLCD.h"
#include "main.h"

// Ham truyen di nua byte
void lcdNible(char nible)
{
    LCD_D4 = (nible >> 4) & 0x01;
    LCD_D5 = (nible >> 5) & 0x01;
    LCD_D6 = (nible >> 6) & 0x01;
    LCD_D7 = (nible >> 7) & 0x01;
    
    LCD_EN = 1;
    __delay_us(10);
    LCD_EN = 0;
    __delay_us(50);
}

// Ham truyen di ca byte
void lcdByte(char byte)
{
    lcdNible(byte);
    lcdNible(byte << 4);
    __delay_us(10);
}

// Ham truyen di ma lenh
void lcdCmd(char cmd)
{
    LCD_RS = 0; // Thanh ghi lenh
    LCD_RW = 0;
    lcdByte(cmd);
}

// Ham truyen di ky tu
void lcdPutc(char chr)
{
    LCD_RS = 1; // Thanh ghi du lieu
    LCD_RW = 0;
    lcdByte(chr);
}

// Ham truyen di chuoi ky tu
void lcdPuts(char *str)
{
    while(*str)
    {
        lcdPutc(*str);
        str++;
    }
}

// Ham xac dinh toa do hien thi (toa do con tro)
void lcdGotoxy(char col, char row)
{
    if(row == 1) lcdCmd(0x80 + col);
    if(row == 2) lcdCmd(0xC0 + col);
    if(row == 3) lcdCmd(0x94 + col);
    if(row == 4) lcdCmd(0xD4 + col);
}

// Ham khoi tao LCD
void lcdInit(void)
{
    // Thiet lap chan dieu khien LCD la dau ra
    LCD_D4_TRIS = 0;
    LCD_D5_TRIS = 0;
    LCD_D6_TRIS = 0;
    LCD_D7_TRIS = 0;
    
    LCD_RS_TRIS = 0;
    LCD_RW_TRIS = 0;
    LCD_EN_TRIS = 0;
    
    // Lam thieo luu do thuat toan LCD-4bit Interfaces
    __delay_ms(20); 
    lcdNible(0x30);
            
    __delay_ms(20); 
    lcdNible(0x30);
    
    __delay_ms(20); 
    lcdNible(0x30);
    
    __delay_ms(20); 
    lcdNible(0x20); // Thiet lap giao thuc la 4bit
    
    lcdCmd(0x28); // lcd tu 2 dong tro len, font 5x8  
    lcdCmd(0x0C); // bat hien thi, tat con tro
    lcdCmd(0x06); // Hien thi tang len mot don vi
    lcdCmd(0x01); // Xoa hien thi
    lcdCmd(0x02); // Dua con tro ve dau dong
    
    __delay_ms(50); 
}
