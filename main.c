

#define FCY 4000000
#include <libpic30.h>
#include "config.h"
#include "lcd.h"
#include <string.h>

void system_init(){
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x001F;
    TRISB = 0x0000;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPU1 = 0x0000;
    CNPU2 = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    //AD1PCFG = 0x0E3C;
     AD1PCFG = 0xFFFF;
  
}


void main(){
    //Declaracion de variables
    int LCD_AUXILIAR=0,i=0;
    char NUM='0';
    char numero[]="              ";
    
    
    system_init();
    /*CONFIGURACION INICIAL DE LCD*/
    LCD_Initialize(); //Preder, configurar a 4 bits
    DisplayClr();  // borrar lo que tenga la pantalla
    LCDGoto(0,0); //poner el cursor en la posicion inicial
    
    while(1){
        LCD_PORT=LCD_AUXILIAR;
        

        NUM='&';
        //Rutina del display
         LCDPutStr(numero);
        __delay_ms(30);
         LCDGoto(0,0);
         
         LCD_AUXILIAR=LCD_PORT;
         //Rutina de salida del teclado
         PORTB=0x100;
            if(PORTAbits.RA3==1) NUM='7';
            if(PORTAbits.RA2==1) NUM='8';
            if(PORTAbits.RA1==1) NUM='9';
            if(PORTAbits.RA0==1) NUM='/';
         __delay_ms(3);
         PORTB=PORTB<<1;
            if(PORTAbits.RA3==1) NUM='4';
            if(PORTAbits.RA2==1) NUM='5';
            if(PORTAbits.RA1==1) NUM='6';
            if(PORTAbits.RA0==1) NUM='x';
         __delay_ms(3);
         PORTB=PORTB<<1;
            if(PORTAbits.RA3==1) NUM='1';
            if(PORTAbits.RA2==1) NUM='2';
            if(PORTAbits.RA1==1) NUM='3';
            if(PORTAbits.RA0==1) NUM='-';
         __delay_ms(3);
         PORTB=PORTB<<1;
            //if(PORTAbits.RA3==1) NUM='1';
            if(PORTAbits.RA2==1) NUM='0';
            if(PORTAbits.RA1==1) NUM='=';
            if(PORTAbits.RA0==1) NUM='+';
         __delay_ms(3);
         
        if(NUM!='&'){
            if(NUM=='/' || NUM=='+' || NUM=='-' || NUM=='x'){
                 DisplayClr();
                 numero[0]=' ';
                 numero[1]=' ';
                 numero[2]=' ';
                 numero[3]=' ';
                 LCDPutChar(NUM);
                 i=0;
            }
            else{
                numero[i]=NUM;
                i++;  
            }

        }

         //NUM='1';
         
         
         
    }
}

