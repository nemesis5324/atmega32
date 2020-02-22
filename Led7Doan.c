/*****************************************************
Chip type               : ATmega32A
Program type            : Application
AVR Core Clock frequency: 8.003000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32a.h>
#include <delay.h>
// Declare your global variables here
void WriteDigit(unsigned int number){
  switch (number){
    case 0: PORTB = 0b00111111;break;
    case 1: PORTB = 0b00000110;break;
    case 2: PORTB = 0b01011011;break;
    case 3: PORTB = 0b01001111;break;
    case 4: PORTB = 0b01100110;break;
    case 5: PORTB = 0b01101101;break;
    case 6: PORTB = 0b01111101;break;
    case 7: PORTB = 0b00000111;break;
    case 8: PORTB = 0b01111111;break;
    case 9: PORTB = 0b01101111;break;    
  }
  
}
void WriteNumber(unsigned int number){
  // The number in the format abcd
  int a,b,c,d;
  a = number/1000;
  b = (number-a*1000)/100;
  c = (number - a*1000 - b*100)/10;
  d = number - a*1000 - b*100 - c*10; 
  // Hang don vi
  PORTD = 0b11111110;
  WriteDigit(d);
  delay_us(50);
  PORTB = 0x00;
  
  // Hang chuc
  PORTD = 0b11111101;
  WriteDigit(c);
  delay_us(50);
  PORTB = 0x00;
  
  // Hang tram
  PORTD = 0b11111011;
  WriteDigit(b);
  delay_us(50);
  PORTB = 0x00;
  
  // Hang nghin
  PORTD = 0b11110111;
  WriteDigit(a);
  delay_us(50);
  PORTB = 0x00;
}
void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTB=0x00;
DDRB=0xFF;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

  while (1){
  /* PORTB dk hien thi gia tri tu 0-9    
     PB0 - A
     PB1 - B
     ...
     PORTD dk vi tri hang don vi, chuc, tram,...
     PD0 - Y0
     PD1 - Y1
     ...
  */
    //PORTB = 0x3F;
    //PORTD = 0b11111110;   
    WriteNumber(89); 
  }
}