#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void init_adc();
unsigned short read_adc();
void show_adc(unsigned short value);
#define CDS_VALUE 871 // 10 LUX�� ��� �� 
unsigned char digit[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char fnd_sel[4]={0x01,0x02,0x04,0x08};
unsigned char on[2]={0x3f, 0x37};
unsigned char off[3]={0x3f, 0x71, 0x71};
int main()
{
	DDRA=0xff; // LED ��� 
	DDRC=0xff; // FND ��� 
	DDRG=0x0f; // FND 4�ڸ� ��� ��� 
	init_adc();
	while(1){
		show_adc(read_adc());
	}
}


void init_adc(){
	ADMUX=0x00; 
	// REFS(1:0) AREF (+5V �������� ���),
	// ADLAR = 0 (�� ���������� ����) ,
	// MUX(4:0) = 00000 (ADC0 ���, �ܱ� �Է�) 
	ADCSRA=0x87; 
	// ADEN =1 (ADC ���),
	// ADFR = 0 (single conversion ���),
	// ADPS(2:0) = 111 ���������Ϸ� 128���� 
}

unsigned short read_adc(){
	unsigned char adc_low,adc_high;
	unsigned short value;
	ADCSRA|=0x40; // ADC start conversion Setting ��ȣ ���� 
	while((ADCSRA & 0x10) != 0x10); // ADC ��ȯ �Ϸ� �˻�
	adc_low = ADCL; // ��ȯ�� �� �о���� 
	adc_high = ADCH; // ��ȯ�� �� �о���� 
	value = (adc_high << 8) | adc_low; // high ���� <<8�Ͽ� ���� ������ ��ȯ
	return value;
}

void show_adc(unsigned short value){
	int i, fnd[4];
	unsigned short temp=value;
	if(value <CDS_VALUE){ // ���� �� �̸� (��ο� ���)
		PORTA=0xff;
		for(i=0;i<2;i++){
			PORTC=on[1-i];
			PORTG=fnd_sel[i];
			_delay_us(2500);
		}
	}
	else{ // ���� �� �̻� (���� ���)
		PORTA=0x00;
		for(i=0;i<3;i++){
			PORTC=off[2-i];
			PORTG=fnd_sel[i];
			_delay_us(2500);
		}
	}

}
