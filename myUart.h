/* 
 * File:   myUart.h
 * Author: duandh
 *
 * Run on xc8
 */

#ifndef MYUART_H
#define	MYUART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
#define TX_INT_ON   1  // Transmit interrupt on
#define TX_INT_OFF  0  // Transmit interrupt off
#define RX_INT_ON   1  // Receive interrupt on
#define RX_INT_OFF  0  // Receive interrupt off
#define BRGH_HIGH   1  // High baud rate
#define BRGH_LOW    0  // Low baud rate
#define CONT_RX     1  // Continuous reception
#define SINGLE_RX   0  // Single reception
#define MASTER      1 // Synchrounous master mode
#define SLAVE       0  // Synchrounous slave mode
#define NINE_BIT    1  // 9-bit data
#define EIGHT_BIT   0  // 8-bit data
#define SYNCH       1  // Synchronous mode
#define ASYNCH      0  // Asynchronous mode

void uartIntMode(char txMode, char rxMode);
void uartBaudrateMode(char mode);
void uartSetBaudrate(char spbrg);
void uartRxMode(char mode);
void uartSyncMode(char mode);
void uartBitMode(char mode);
void uartSynchMode(char mode);
void uartStart();
void uartStop();
void uartOpen(void);
char uartRead(void);
void uartWrite(char data);
void uartGets(char *buffer,  unsigned char len);
void uartPuts(char* str);
char uartDataRdy(void);
char uartBusy(void);
    
    



#ifdef	__cplusplus
}
#endif

#endif	/* MYUART_H */

