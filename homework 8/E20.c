/*
 * E20.c
 * 
 * Copyright 2025 USER <USER@PC-1>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

void print_array(unsigned int * array,int n);
unsigned int number_raz(unsigned int number);
void Buble_Sort1(unsigned int * array,int n);
void func1(unsigned int number,unsigned int raz,unsigned int * array);
void swap(unsigned int *a,unsigned int *b);


int main(int argc, char **argv)
{
	unsigned int number,i;
	unsigned int array[SIZE];
	scanf("%u",&number);
	i=number_raz(number);
	func1(number,i,array);
	Buble_Sort1(array,i);
	print_array(array,i);
	
	
	return 0;
}




void swap(unsigned int *a,unsigned int *b)
{
	unsigned int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}



void print_array(unsigned int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%u",*(array+i));
	
	
}


unsigned int number_raz(unsigned int number)
{
	unsigned int count=0;
	
	while(number)
	{
		number/=10;
		count++;
		
	}
	
	return count;
}


void Buble_Sort1(unsigned int * array,int n)
{
	bool noswap;
	
	for(unsigned int i=n-1;i>=0;i--)
	{
		noswap=1;
		for(unsigned int j=0;j<i;j++)
		{
			if(*(array+j)<*(array+j+1))
			{
				swap((array+j),(array+j+1));
				noswap=0;
				
			}
		}
		if(noswap)
		{
			break;
		}
	}
	
}


void func1(unsigned int number,unsigned int raz,unsigned int * array)
{
	unsigned int i=1,dec=1;
	
	while(raz>i)
	{
		dec*=10;
		i++;
	}
	
	
	*(array+0)=number/dec;
	dec/=10;
	for(i=1;i<raz;i++)
	{
		*(array+i)=(number/dec)%10;
		dec/=10;
		
	}
	
}



