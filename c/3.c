/* GPIO로 LED 켜고 끄기 1번 예
 LED 8개가 연결되어 있는 포트 : Port A(PA)
 - 비트7 : LED7(LD1), 비트6 : LED6(LD2)
 - ...
 - 비트1 : LED1(LD7), 비트0 : LED0(LD8) */
 #include <avr/io.h>  //ATmage128 레지스터 정의
 #include <util/delay.h>
 #include <stdlib.h>
 #define F_CPU 16000000UL

char LED;
int i;
unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
void light(int index)//index는 0~7
{
   LED = 0x01;
   LED = LED<<index;
   PORTA = LED;
   //_delay_ms(10000);   
   PORTC = digit[index];
   PORTG = 0x0f;
   _delay_ms(10000);   
}


 int main(){
    DDRA= 0xff; // 포트 A를 출력 포트로 사용 
   DDRG = 0x0f;
   DDRC = 0xff;

   while(1) {
   int num = rand()%8;
 for(i=0;i<8;i++) {
    if(i==num)
   {
   light(i);
   }
}
 }
 }
