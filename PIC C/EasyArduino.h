#include <lcd.c>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h> 
#define voidloop() while(TRUE)
#define setup() main()
#define max(x,y)  ((x > y) ? x : y)
#define min(x,y)  ((x < y) ? x : y)
#define A0 AN0
#define A1 AN1
#define A2 AN2
#define A3 AN3
#define A4 AN4
#define A5 AN5
#define A6 AN6
#define A7 AN7
#define D0 PIN_D0
#define D1 PIN_D1
#define D2 PIN_D2
#define D3 PIN_D3
#define D4 PIN_D4
#define D5 PIN_D5
#define D6 PIN_D6
#define D7 PIN_D7
#define D8 PIN_B0
#define D9 PIN_B1
#define D10 PIN_B2
#define D11 PIN_B3
#define D12 PIN_B4
#define D13 PIN_B5
#define D14 PIN_B6
#define D15 PIN_B7
#define High 1
#define LOW 0
///////////////////////////////////////////////////////////
float map(float v , float x , float y , float z, float zz)
{

float a = ((v)/y)*zz ;
return a;

}
///////////////////////////////////////////////////////////////
void digitalWrite(pin,state)
{

if(state== 1)
{
output_high(pin);
}
else
{
output_low(pin);
}

}

/////////////////////////////////
int digitalRead(pin)
{
int x = input(pin);
return x;
}

/////////////////////////
float analogRead(pin2){

                   // Initialize LCD module
  setup_adc(ADC_CLOCK_DIV_32);      // Set ADC conversion time to 32Tosc
  setup_adc_ports(pin2);             // Configure AN0 as analog
  set_adc_channel(0);
  float i = read_adc();// Select channel 0 input
  i = (i/255*5);
  i = map(i,0,5,0,1024);
  return i;


}


/////////////////////////////////////////
////////////////////////////////////////

///////////////////////////////////
int constrain(float v , float x , float y )
{
if(v>=y)
{
return y;
}
if(v<=x)
{
return x;
}
else
{
return v;
}


}
///////////////////////////////////
void delay(int ms)
{
delay_ms(ms);
}
//////////////////////////////////////
//#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS)
void Serial_print1(float x44)
{printf("%f\n",x44);}

void Serial_print2(int x45)
{printf("%d\n",x45);}

void Serial_print3(char x459)
{printf("%s\n",x459);}
/////////////////////////////////////////////////
void lcd_print1(float i)
{
 printf(lcd_putc,"\f%f",i);
}
void lcd_print2(int i)
{
 printf(lcd_putc,"\f%d",i);
}
void lcd_print3(char i)
{
 printf(lcd_putc,"\f%s",i);
}
////////////////////////////////////////////
void analogWrite(pin,float value)
{
float x99 = map(value,0,255,0,10);
//x99 = constrain(x99,0,10);
int ce = ceil( x99 );
int on = constrain(ce,0,10);
int of = 10 - ce;
of = constrain(of,0,10);

digitalWrite(pin,HIGH);
delay(on);
digitalWrite(pin,LOW);
delay(of);
}
///////////////////////////
