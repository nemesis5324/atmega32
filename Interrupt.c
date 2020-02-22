/*****************************************************
Chip type               : ATmega32A
Program type            : Application
AVR Core Clock frequency: 8.003000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/

#include <mega32a.h>
#include <stdlib.h>
// Alphanumeric LCD Module functions
#include <alcd.h>
#include <delay.h>
// Declare your global variables here
unsigned char str[]="123";
volatile unsigned int itemp2;
const unsigned char scan_code[4] = {0b00001110, 0b00001101, 0b00001011, 0b00000111};
const unsigned char ascii_code[4][4] = {{'1','2','3','4'}, // i=0, PA4=0
                                        {'5','6','7','8'}, // i=1, PA5=0
                                        {'9','0','A','B'}, // i=2, PA6=0
                                        {'C','D','E','F'}  // i=3, PA7=0
                                        };
                                       //PD0 PD1 PD2 PD3

unsigned char key;
// External Interrupt 0 service routine
interrupt [EXT_INT0] void ext_int0_isr(void){   
   itemp2 = itemp2+1;
   GIFR &= 0b10111111;
}

// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void){
// Place your code here    
    itemp2 = itemp2+2;
    GIFR &= 0b01111111;
}

void read_pad(){
  unsigned char i,j,keyin;
  unsigned found = 0;
  for(i=0;i<4;i++){ 
    if(found == 1){break;}
    PORTD &= ~(1<<(4+i));
    delay_ms(1);
    keyin = PIND&0x0F;
    PORTD  = 0xFF;
    if(keyin != 0x0F)
      for(j=0;j<4;j++){
        if(keyin == scan_code[j])
          key = ascii_code[i][j];          
          found = 1;
      }
  }
    
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
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTD=0x00;
DDRD=0x00;

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
// INT0: ON, falling
// INT1: ON, falling
// INT2: Off
MCUCR=0b00001010;
MCUCSR=0x00;
GICR = 0b11000000;

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

// Alphanumeric LCD initialization
// Connections specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 4
// RD - PORTA Bit 5
// EN - PORTA Bit 6
// D4 - PORTB Bit 4
// D5 - PORTB Bit 5
// D6 - PORTB Bit 6
// D7 - PORTB Bit 7
// Characters/line: 16
PORTC = 0x00;
DDRC = 0x40;
lcd_init(16);
DDRD &= 0b11110011; // Set PD2, PD3 as input
PORTD |= 0b00001100;// Set pullup on PD2,PD3

SREG |= 0b10000000; // Enable global interrupt
//#asm("sei")
  while (1){
      // Place your code here  
    itoa(itemp2,str);
    lcd_gotoxy(0,0);
    lcd_puts(str);    
  }
}
