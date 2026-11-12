
// PIC16F18857 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FEXTOSC = LP     // External Oscillator mode selection bits (LP (crystal oscillator) optimized for 32.768kHz; PFM set to low power)
#pragma config RSTOSC = HFINT32 // Power-up default value for COSC bits (HFINTOSC with OSCFRQ= 32 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = ON    // Clock Out Enable bit (CLKOUT function is enabled; FOSC/4 clock appears at OSC2)
#pragma config CSWEN = OFF      // Clock Switch Enable bit (The NOSC and NDIV bits cannot be changed by user software)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (FSCM timer disabled)

// CONFIG2
#pragma config MCLRE = OFF      // Master Clear Enable bit (MCLR pin function is port defined function)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config LPBOREN = ON     // Low-Power BOR enable bit (ULPBOR enabled)
#pragma config BOREN = OFF      // Brown-out reset enable bits (Brown-out reset disabled)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (VBOR) is set to 2.7V)
#pragma config ZCD = ON         // Zero-cross detect disable (Zero-cross detect circuit is always enabled)
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control (The PPSLOCK bit can be set and cleared repeatedly by software)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable bit (Stack Overflow or Underflow will not cause a reset)

// CONFIG3
#pragma config WDTCPS = WDTCPS_0// WDT Period Select bits (Divider ratio 1:32)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled, SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_0// WDT Window Select bits (window delay = 87.5 percent of time; no software control; keyed access required)
#pragma config WDTCCS = LFINTOSC// WDT input clock selector (WDT reference clock is the 31.0kHz LFINTOSC output)

// CONFIG4
#pragma config WRT = ON         // UserNVM self-write protection bits (0x0000 to 0x7FFF write protected)
#pragma config SCANE = not_available// Scanner Enable bit (Scanner module is not available for use)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (High Voltage on MCLR/Vpp must be used for programming)

// CONFIG5
#pragma config CP = ON          // UserNVM Program memory code protection bit (Program Memory code protection enabled)
#pragma config CPD = ON         // DataNVM code protection bit (Data EEPROM code protection enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>



#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define _XTAL_FREQ 8000000
#define RAND_MAX 0x7ffffffff
void PICinit(){
      OSCCON1 = 0x60;
      ANSELA = 0b00000000;
      ANSELB = 0b00000000;
      TRISA  = 0b11111111;
      TRISB  = 0b00000000;
      TRISC  = 0b00000000;
      PORTA  = 0b00000000;    
      PORTB  = 0b11111111;         
      PORTC  = 0b00000000;            
}
void practice(){
    tiMe++;
    for(char i=0;i<8;i++){
        for(char j=0;j<8;j++){
            if(test[i][j]==1){
                PORTC=1<<i;
                PORTB=255^0b10000000>>j;
            }else if(test[i][j]==2&&tiMe==3){
                PORTC=1<<i;
                PORTB=255^0b10000000>>j;
            }else{
                PORTB=0b11111111;
                PORTC=0b00000000;
            }
        }
            
    }
    tiMe=(tiMe==3)?0:tiMe;
    PORTB=0b11111111;
    PORTC=0b00000000;
}
