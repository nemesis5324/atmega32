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
int i=0;
// Declare your global variables here
const unsigned int col_select[8] = {// Chon cot
  0b11111110,
  0b11111101,
  0b11111011,
  0b11110111,
  0b11101111,
  0b11011111,
  0b10111111,
  0b01111111  
}; 

struct Digit{
  unsigned int col_value[8];   // Cot
};
typedef const struct Digit Digit_type;
Digit_type my_digit[10] = {
  {{0x00,0x3C,0x42,0x81,0x81,0x42,0x3C,0x00}},
  {{0x00,0x00,0x04,0x02,0xFF,0x00,0x00,0x00}},
  {{0x00,0x82,0xC1,0xA1,0x91,0x8E,0x00,0x00}},
  {{0x00,0x00,0x42,0x81,0x89,0x76,0x00,0x00}},
  {{0x00,0x10,0x18,0x14,0x12,0xFF,0x10,0x00}},
  {{0x00,0x00,0x47,0x89,0x89,0x49,0x31,0x00}},
  {{0x00,0x3C,0x4A,0x89,0x89,0x72,0x00,0x00}},
  {{0x00,0x00,0x01,0x01,0x01,0x01,0xFF,0x00}},
  {{0x00,0x76,0x89,0x89,0x89,0x89,0x76,0x00}},
  {{0x00,0x00,0x4E,0x89,0x89,0x89,0x7E,0x00}}    
};

void write_digit(unsigned int a_digit){
  for(i=0; i<8; i++){
    PORTC = my_digit[a_digit].col_value[i];
    PORTD = col_select[i];
    delay_us(50);
    PORTD = 0xFF;
  }
}
void main(void){
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTA=0x00;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTC=0x00;
DDRC=0xFF;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
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
    write_digit(1);
  }
}
