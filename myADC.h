/* 
 * File:   myADC.h
 * Author: duand
 *
 * Created on 27 February 2017, 19:59
 */

#ifndef MYADC_H
#define	MYADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
#define INT_ON       1 // A/D interrupt enabled 
#define INT_OFF      0 // A/D interrupt disabled 
    
/* ***** clock source ***** */
#define FOSC_2       0b000 // A/D clock source Fosc/2
#define FOSC_4       0b100 // A/D clock source Fosc/4
#define FOSC_8       0b001 // A/D clock source Fosc/8
#define FOSC_16      0b101 // A/D clock source Fosc/16
#define FOSC_32      0b010 // A/D clock source Fosc/32
#define FOSC_64      0b110 // A/D clock source Fosc/64
#define FOSC_RC      0b111 // A/D clock source Internal RC OSC
    
/* ***** acquisition time ***** */    
#define TAD_0        0b000
#define TAD_2        0b001
#define TAD_4        0b010
#define TAD_6        0b011
#define TAD_8        0b100
#define TAD_12       0b101
#define TAD_16       0b110
#define TAD_20       0b111

/* ***** result justification ***** */    
#define RIGHT   1 // Right justify A/D result
#define LEFT    0 // Left justify A/D result

/* ***** voltage reference ***** */    
#define VDD_VSS     0b00 // AVDD(VREF+) -   VSS(VREF-)
#define VDD_EXT     0b01 // AVDD(VREF+) -   EXT(VREF-)
#define EXT_VSS     0b10 // EXT(VREF+) -    VSS(VREF-)
#define EXR_EXT     0b11 // EXT(VREF+) -    EXT(VREF-)
    
/* ***** channel selection ***** */
#define ADC_CH0          0b10000111  // Channel 0
#define ADC_CH1          0b10001111  // Channel 1
#define ADC_CH2          0b10010111  // Channel 2
#define ADC_CH3          0b10011111  // Channel 3
#define ADC_CH4          0b10100111  // Channel 4
#define ADC_CH5          0b10101111  // Channel 5
#define ADC_CH6          0b10110111  // Channel 6
#define ADC_CH7          0b10111111  // Channel 7
#define ADC_CH8          0b11000111  // Channel 8
#define ADC_CH9          0b11001111  // Channel 9
#define ADC_CH10         0b11010111  // Channel 10
#define ADC_CH11         0b11011111  // Channel 11
#define ADC_CH12         0b11100111  // Channel 12
#define ADC_CH13         0b11101111  // Channel 13
#define ADC_CH14         0b11110111  // Channel 14
#define ADC_CH15         0b11111111  // Channel 15
    
#define AN_NONE     0b1111 // All digital
#define AN0         0b1110 // analog: AN0      digital: AN1->15
#define AN0_TO_1    0b1101 // analog: AN0->1   digital: AN2->15
#define AN0_TO_2    0b1100 // analog: AN0->2   digital: AN3->15
#define AN0_TO_3    0b1011 // analog: AN0->3   digital: AN4->15
#define AN0_TO_4    0b1010 // analog: AN0->4   digital: AN5->15
#define AN0_TO_5    0b1001 // analog: AN0->5   digital: AN6->15
#define AN0_TO_6    0b1000 // analog: AN0->6   digital: AN7->15
#define AN0_TO_7    0b0111 // analog: AN0->7   digital: AN8->15
#define AN0_TO_8    0b0110 // analog: AN0->8   digital: AN9->15
#define AN0_TO_9    0b0101 // analog: AN0->9   digital: AN10->15
#define AN0_TO_10   0b0100 // analog: AN0->10  digital: AN11->15
#define AN0_TO_11   0b0011 // analog: AN0->11  digital: AN12->15
#define AN0_TO_12   0b0010 // analog: AN0->12  digital: AN13->15
#define AN0_TO_13   0b0001 // analog: AN0->13  digital: AN14->15
#define AN_ALL      0b0000 // All analog
    
void adcClock(char clk);
void adcAcqTime(char tad);
void adcResultJust(char just);
void acdVoltRef(char vref);
void adcInterrupt(char config);
void adcPortConfig(char config);
void adcInit(void);
void adcStart(void);
void adcStop(void);
void adcSetChannel(char channel);
unsigned int adcRead (char ch);
void adcClose (void);
char adcBusy (void);

#ifdef	__cplusplus
}
#endif

#endif	/* MYADC_H */

