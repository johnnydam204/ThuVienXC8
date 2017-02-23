
#include <pic18f4520.h>

#include <xc.h>
#include "myUart.h"

void uartIntMode(char txMode, char rxMode)
{
    PIR1bits.TXIF = txMode;
    PIR1bits.RCIF = rxMode;
}

void uartBaudrateMode(char mode)
{
    TXSTAbits.BRGH = mode;
}

void uartSetBaudrate(char spbrg)
{
    SPBRG = spbrg;
}
void uartRxMode(char mode)
{
    RCSTAbits.CREN = mode;
}

void uartSyncMode(char mode)
{
    TXSTAbits.SYNC = mode;
}

void uartBitMode(char mode)
{
    TXSTAbits.TX9 = mode;  
    RCSTAbits.RX9 = mode;    
}

void uartSynchMode(char mode)
{
    TXSTAbits.CSRC = mode;
}

void uartStart(void)
{
    TXSTAbits.TXEN = 1;  // Enable transmitter
    RCSTAbits.SPEN = 1;  // Enable receiver
}

void uartStop(void)
{
    TXSTAbits.TXEN = 0;  // Disable transmitter
    RCSTAbits.SPEN = 0;  // Disable receiver
}

void uartOpen(void)
{
    // Clear USART Control Register
    TXSTA = 0;           
    RCSTA = 0;
    
    uartSyncMode(ASYNCH);
    
    // Hàm dưới chỉ có tác dụng khi sử dụng ở chế độ đồng bộ <uartSyncMode(SYNCH)>
    uartSynchMode(SLAVE);
    
    uartBitMode(EIGHT_BIT);
    uartRxMode(CONT_RX);
    uartBaudrateMode(BRGH_LOW);
    uartIntMode(TX_INT_OFF, RX_INT_ON);
    uartSetBaudrate(17);
    uartStart();
}

char uartRead(void)
{
    return RCREG;
}
void uartWrite(char data)
{
    TXREG = data;
}

void uartGets(char *buffer,  unsigned char len)
{
    char i;    // Length counter
    unsigned char data;

    for(i=0;i<len;i++)  // Only retrieve len characters
    {
        while(!uartDataRdy());// Wait for data to be received
        data = uartRead();     // Get a character from the USART                                
        *buffer = data;         // and save in the string
        buffer++;               // Increment the string pointer
    }
}

void uartPuts(char *str)
{
    do
    {  
        // Transmit a byte
        while(uartBusy());
        uartWrite(*str);
    } 
    while( *str++ );
}

char uartDataRdy(void)
{
    if(PIR1bits.RCIF)
        return 1;   //The EUSART receive buffer is full (cleared by reading RCREG)
    else
        return 0;   //The EUSART receive buffer is not full
}

char uartBusy(void)
{
    if(!TXSTAbits.TRMT)
        return 1; // The EUSART transmit buffer is empty (cleared by writing to TXREG)
    else
        return 0; // The EUSART transmit buffer is full
}
