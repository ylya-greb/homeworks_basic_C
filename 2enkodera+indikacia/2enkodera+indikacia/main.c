/*
 * 2enkodera+indikacia.c
 *
 * Created: 12.06.2020 12:40:52
 * Author : pro
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>


const int increment[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

volatile int32_t counter1=0;
volatile int8_t ABprev1 = 0;
volatile int32_t angle1=0;

volatile int32_t counter2 = 0;
volatile int8_t  ABprev2 = 0;
volatile int32_t angle2=0;

const  float  dlin_okr=38.9; /*   длина окружности ,  проходимой шестернёй на энкодере,*/
/* контролирующем перемещение тележки  за 1 поворот  в мм */
volatile long peremeshenie=0; /*  в милиметрах*/


ISR(PCINT0_vect)// энкодер  угол отклонения маятника
{


	int8_t AB1 = PINB & 3;
	//counter1 += increment[AB1 + ABprev1 *4];
	counter1 += increment[AB1 + ABprev1*4];
	//angle1=counter1*0.77;
angle1=counter1*6;

	ABprev1 = AB1;

}



ISR(PCINT1_vect)//энкодер  угол отклонения маятника
{
int8_t AB2 = PINC & 3;

counter2 += increment[AB2 + ABprev2*4];
angle2=counter2*6;

peremeshenie=(dlin_okr*angle2)/360; /* вычисление перемещения тележки относительно началаьного положения в   мм  */


ABprev2 = AB2;	
	
	
}


void pin_change()//настройка прерываний для  обработки  значений с энкодеров
{
	//настройка прерывания Pin Change Interrupt 0
	PCMSK0|=(1<<PCINT0)|(1<<PCINT1);
	PCICR|=(1<<PCIE0);

	//настройка прерывания Pin Change Interrupt 1
	PCMSK1|=(1<<PCINT8)|(1<<PCINT9);
	PCICR|=(1<<PCIE1);
	
}



//Функции работы с УАРТом
void USART_Transmit( char data)
{
	while (!(UCSR0A & (1<<UDRE0)))
	;
	
	UDR0=data;//посылка данных по УСАРТ
	
}

static int uart_putchar(char c, FILE *stream);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

static int uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
	uart_putchar('\r', stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}

void send_int_Uart(long c)//    Отправка числа от 0000 до 9999

{
	
	signed char temp;
	
	c=c%10000;
	
	temp=c/100;
	
	USART_Transmit(temp/10+'0');
	
	USART_Transmit(temp%10+'0');
	
	temp=c%100;;
	
	USART_Transmit(temp/10+'0');
	
	USART_Transmit(temp%10+'0');
	
}


void USART_INIT()
{
	UBRR0H|=0b00000000;
	UBRR0L|=0b00011001;	UCSR0A|=(0<<U2X0);
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C|=(0<<UMSEL00)|(0<<UMSEL01)|(0<< UPM00)|(0<< UPM01)|(0<<USBS0);
	UCSR0C|=( 1<<UCSZ00)|(1<<UCSZ01)|(0<<UCSZ02);


}













int main(void)
{
  //DDRC=(1<<DDC4);
 // PORTC=(1<<PC4);//светодиод горит, оповещая о нормальном ходе работы программы.  
   pin_change();
   stdout = &mystdout;
   USART_INIT();
    USART_Transmit("T");
	sei();
	
	
	/* Replace with your application code */
    while (1) 
    {
		_delay_ms(200);
		printf("\n angle1\n");
		send_int_Uart(angle1);
		_delay_ms(200);
		
		printf("\n angle2\n");
		send_int_Uart(angle2);
		_delay_ms(200);
		
		printf("\n peremeshenie\n");
		send_int_Uart(peremeshenie);
		_delay_ms(200);
		
		_delay_ms(200);
		
		
    }
}

