#include <pic16f630.h>
#include <xc.h>
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High speed crystal/resonator on RA4/OSC2/CLKOUT and RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA3/MCLR pin function select (RA3/MCLR pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#define _XTAL_FREQ 20000000
#define latch_SR PORTCbits.RC2
#define clock_SR PORTCbits.RC0
#define data_SR PORTCbits.RC1
void main()
{
    TRISC = 0x00;
    int i, j, k;
    clock_SR = 0;
    data_SR = 0;
    latch_SR = 0;
    while (1)
    {

        for(i=0; i<=7; i++)
        {
            clock_SR = 0;
            if(i==1 || i==2)data_SR = 1; // O PINO DATA, QUANDO SETADO CORRETAMENTE EM
            else data_SR = 0;            // CONJUNTO COM O CLOCK, INDICA AONDE O BIT
            __delay_ms(10);              // SERÁ ARMAZENADO ENTRE AS POSIÇÕES 0 E 7
            clock_SR = 1;
        /*
         DURANTE A BORDA DE SUBIDA DO CLOCK, O SHIFT REGISTER VERIFICA O ESTADO DO PINO DATA,
         SE ELE ESTIVER EM NÍVEL ALTO DURANTE A BORDA DE SUBIDA, É ARMAZENADO O VALOR 1 NO RE-
         GISTRADOR SERIAL, SE O PINO DATA ESTIVER EM NÍVEL BAIXO, SERÁ ARMAZENADO O VALOR 0.
         SE CONSIDERARMOS
        */
        }
    latch_SR = 1; // A BORDA DE SUBIDA DO LATCH ENVIA OS DADOS PARA A PORTA PARALELA
    __delay_ms(10);
    latch_SR = 0;
    }



}