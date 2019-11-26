#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void init_adc();
unsigned short read_adc();
void show_adc(unsigned short value);
#define CDS_VALUE 871 // 10 LUX의 밝기 값 
unsigned char digit[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char fnd_sel[4]={0x01,0x02,0x04,0x08};
unsigned char on[2]={0x3f, 0x37};
unsigned char off[3]={0x3f, 0x71, 0x71};
int main()
{
	DDRA=0xff; // LED 출력 
	DDRC=0xff; // FND 출력 
	DDRG=0x0f; // FND 4자리 모두 사용 
	init_adc();
	while(1){
		show_adc(read_adc());
	}
}


void init_adc(){
	ADMUX=0x00; 
	// REFS(1:0) AREF (+5V 기준전압 사용),
	// ADLAR = 0 (값 오른쪽으로 정렬) ,
	// MUX(4:0) = 00000 (ADC0 사용, 단극 입력) 
	ADCSRA=0x87; 
	// ADEN =1 (ADC 사용),
	// ADFR = 0 (single conversion 모드),
	// ADPS(2:0) = 111 프리스케일러 128분주 
}

unsigned short read_adc(){
	unsigned char adc_low,adc_high;
	unsigned short value;
	ADCSRA|=0x40; // ADC start conversion Setting 신호 보냄 
	while((ADCSRA & 0x10) != 0x10); // ADC 변환 완료 검사
	adc_low = ADCL; // 변환된 값 읽어오기 
	adc_high = ADCH; // 변환된 값 읽어오기 
	value = (adc_high << 8) | adc_low; // high 값은 <<8하여 원래 값으로 변환
	return value;
}

void show_adc(unsigned short value){
	int i, fnd[4];
	unsigned short temp=value;
	if(value <CDS_VALUE){ // 기준 값 미만 (어두울 경우)
		PORTA=0xff;
		for(i=0;i<2;i++){
			PORTC=on[1-i];
			PORTG=fnd_sel[i];
			_delay_us(2500);
		}
	}
	else{ // 기준 값 이상 (밝은 경우)
		PORTA=0x00;
		for(i=0;i<3;i++){
			PORTC=off[2-i];
			PORTG=fnd_sel[i];
			_delay_us(2500);
		}
	}

}
