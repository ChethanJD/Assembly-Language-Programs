#include<at89c51xd2.h>
void delay(void);
void main(){
	while(1){
		P0=0x00;
		delay();
		
		P0=0xff;
		delay();
	}
}
void delay(void){
	int i;
	for(i=0;i<=300;i++);
}