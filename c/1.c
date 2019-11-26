/* GPIO로 LED 움직임 표현하기 : 링 카운터, 오른쪽 이동*/
 #include <avr/io.h>  //ATmage128 레지스터 정의
#include <util/delay.h> // _delay_ms 사용 (ms단위로 sleep)
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
