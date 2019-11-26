/* GPIO로 FND 하나 켜기 */
 #include <avr/io.h>  //ATmage128 레지스터 정의
 #define F_CPU 16000000UL
#include <util/delay.h> // _delay_ms 사용 (ms단위로 sleep)
unsigned char digit[10]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
unsigned char fnd_sel[4]={0x01,0x02,0x04,0x08};
int main(){
	int i=0;
 	DDRC = 0xff;
 	DDRG = 0x0f;
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	int carrya=0;
	int carryb=0;
	int carryc=0;
 	while(1){
		for(i=0;i<4;i++){
			if(i==0){
 				PORTC=digit[a];
			}
			else if(i==1){
 				PORTC=digit[b];
			}
			else if(i==2){
 				PORTC=digit[c]|0x80;

			}
			else if(i==3){
 				PORTC=digit[d];
			}
 			PORTG=fnd_sel[i];
 			_delay_ms(2.5);

 		}
		a=a+1;
		if(a==10){
			a=0;
			carrya=1;
		}
		if(carrya==1){
			b++;
			carrya=0;
		}
		if(b==10){
				b=0;
				carryb=1;
			}
		if(carryb==1){
			c++;
			carryb=0;
		}
		if(c==10){
				c=0;
				carryc=1;
		}
		if(carryc==1){
			d++;
			carryc=0;

		}
		if(d==10){
			d=0;
		}
 	} 
}
