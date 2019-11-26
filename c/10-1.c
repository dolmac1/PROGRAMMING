#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

unsigned char digit[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char fnd_sel[4]={0x01,0x02,0x04,0x08};

volatile int count =0;
volatile int state = 0;
ISR(INT4_vect)
{
	if(state==0){
		state=1;
	}
	else if(state==1){
		state=0;
	}
}
ISR(INT5_vect)
{
	count=0;
	state=0;
}
int main()
{
	DDRC = 0xff; // 7 segment 모두 출력으로 설정 
	DDRG = 0x0f;  //fnd  4자리모두 출력으로 설정
	DDRE = 0xcf;
	
	EICRB = 0x0A;
	EIMSK = 0x30;
	SREG |= 0x80;
	while(1) {
		if(state==0){
			int i, j, fnd[4];
			fnd[3] = (count/1000) %10;
			fnd[2] = (count/100) %10;
			fnd[1] =  (count/10) %10;
			fnd[0] = count %10;
				

			//해당 숫자들 fnd 표시
    		for(i=0; i<4; i++)
			{
				PORTC = digit[fnd[i]];
				PORTG = fnd_sel[i];
				_delay_us(2500);
			}
		}
		else if(state==1){	
			int i, j, fnd[4];
			fnd[3] = (count/1000) %10;
			fnd[2] = (count/100) %10;
			fnd[1] =  (count/10) %10;
			fnd[0] = count %10;


			//해당 숫자들 fnd 표시
    		for(i=0; i<4; i++)
			{
				PORTC = digit[fnd[i]];
				PORTG = fnd_sel[i];
				_delay_us(2500);
			}
			count++;
		}
	}


}


