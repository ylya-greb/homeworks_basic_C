
#include <stdio.h>
#include <stdint.h>


void func1(uint8_t *p8);

int main(void)
{
char c='1';
uint8_t c1=0x02;
	
func1((uint8_t *)c);

//func1(&c1);

	
return 0;
}



void func1(uint8_t *p8)
{
	
printf("\n func1 =%d \n",*p8);
	
}

