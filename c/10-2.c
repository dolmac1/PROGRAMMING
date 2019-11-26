#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#define ON 1
#define OFF 0
volatile int state=OFF;
volatile int count=0;
volatile int state2=0;
int data[8]={17,43,66,77,97,114,129,137};
ISR(TIMER0_OVF_vect){
	if(state2==1){
		if(state==ON){
			PORTB=0x00;
			state=OFF;
		}
		else{
			PORTB=0x10;
			state=ON;
		}
		TCNT0=data[count];
	}
}
ISR(INT4_vect){
	if(state2==0){
		state2=1;
	}
	else if(state2==1){
		state2=0;
	}
}
ISR(INT5_vect){
	count=(count+1)%8;
}
int main()
{
	DDRE=0xcf;
	DDRB=0x10; // 버저 출력 설정 PB4
	TCCR0=0x03; // 32분주
	TIMSK=0x01; // timer 0  overflow interrupt 설정 
	EICRB=0x0a;
	EIMSK=0x30;
	sei(); // 전역 인터럽트 ON
	while(1);
	{

	}
}


