#include <xc.h>
#include "myADC.h"

void adcClock(char clk)
{
    ADCON2bits.ADCS = clk;
}

void adcAcqTime(char tad)
{
    ADCON2bits.ACQT = tad;
}

void adcResultJust(char just)
{
    ADCON2bits.ADFM = just;
}

void acdVoltRef(char vref)
{
    ADCON1bits.VCFG = vref;
}

void adcInterrupt(char config)
{
    PIE1bits.ADIE = config;
    INTCONbits.PEIE = 1;
}

void adcPortConfig(char config)
{
    ADCON1bits.PCFG = config;
}

void adcInit(void)
{
    // Reset A/D Registers to POR state
    ADCON0 = 0;
    ADCON1 = 0;
    ADCON2 = 0;
    
    adcClock(FOSC_16);
    adcAcqTime(TAD_2);
    adcResultJust(RIGHT);
    acdVoltRef(VDD_VSS);
    adcInterrupt(INT_OFF);
    adcPortConfig(AN0);
}

void adcStart(void)
{
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;  // Set the GO bit to start a conversion
}

void adcStop(void)
{
    ADCON0bits.ADON = 0;
    ADCON0bits.GO = 0;  // Set the GO bit to start a conversion
}

void adcSetChannel(char channel)
{
    ADCON0bits.CHS = channel;
}
unsigned int adcRead(char ch)
{
    unsigned int adcResultMSB, adcResultLSB, adcResult;
    adcSetChannel(ch);
    adcStart(); 
    while(adcBusy());
    
    adcResultMSB = ADRESH;
    adcResultLSB = ADRESL;
    adcResult = (adcResultMSB << 8) + adcResultLSB;    
    adcStop();
    return adcResult;
}

void adcClose (void)
{
    ADCON0bits.ADON = 0;
    PIE1bits.ADIE = 0;
}
char adcBusy(void)
{
    return(ADCON0bits.DONE);
}
