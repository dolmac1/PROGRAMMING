/* GPIO�� LED ������ ǥ���ϱ� : �� ī����, ������ �̵�*/
 #include <avr/io.h>  //ATmage128 �������� ����
#include <util/delay.h> // _delay_ms ��� (ms������ sleep)
 void LSHIFT(){
	char LED=1;
	int i;
	for(i=0;i<8;i++){
		PORTA=LED;
		LED=(LED<<1);
		_delay_ms(500);
	}
 }
  void RSHIFT(){
	char LED=128;
	int i;
	for(i=0;i<8;i++){
		PORTA=LED;
		LED=(LED>>1);
		_delay_ms(500);
	}
 }
 int main(){
 	DDRA = 0xff;
 	for(;;){
		LSHIFT();
		RSHIFT();
 	}
 }
