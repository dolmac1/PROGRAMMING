/* GPIO�� LED �Ѱ� ���� 1�� ��
 LED 8���� ����Ǿ� �ִ� ��Ʈ : Port A(PA)
 - ��Ʈ7 : LED7(LD1), ��Ʈ6 : LED6(LD2)
 - ...
 - ��Ʈ1 : LED1(LD7), ��Ʈ0 : LED0(LD8) */
 #include <avr/io.h>  //ATmage128 �������� ����
 #include <util/delay.h>
 #include <stdlib.h>
 #define F_CPU 16000000UL

char LED;
int i;
unsigned char digit[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
void light(int index)//index�� 0~7
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
    DDRA= 0xff; // ��Ʈ A�� ��� ��Ʈ�� ��� 
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
