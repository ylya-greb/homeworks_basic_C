/*
 * F3.c
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
#include <string.h>


unsigned int number_raz(unsigned long number)
{
	unsigned int count=0;
	
	if(number)
	{
		while(number)
		{
			number/=10;
			count++;
			
		}
	}
	else
	count=1;
	
	
	return count;
}



void func1(unsigned long number,unsigned int raz,unsigned int *array)
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



void swap(unsigned int *a,unsigned int *b)
{
	unsigned int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}




void Buble_Sort1(unsigned int * array,int n)
{
	bool noswap;
	if(n)
	{
		for(unsigned int i=n-1;i>=0;i--)
		{
			noswap=1;
			for(unsigned int j=0;j<i;j++)
			{
				if(*(array+j)>*(array+j+1))
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
	
}



void print_array(unsigned int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%u",*(array+i));
	
	
}


unsigned int func2(unsigned int * array1,unsigned int * array2,int n)
{
	unsigned int raz=n;
	unsigned int i=0;
	
	for(i=0;i<n;i++)
	{
		
		for(unsigned int j=i+1;j<n;j++)
		{
		
			if((*(array1+i)<10)&&(*(array1+i)==*(array1+j)))
			{
			raz--;
			*(array1+j)=10;
			(*(array2+i))++;
			
			}
		
		}
		
	}
	
	for( i=0;i<n;i++)
	{
	
	if(*(array1+i)!=10)
	printf("%u %u\n",*(array1+i),*(array2+i));
	
	
	}
	return raz;
}

unsigned int get_array(unsigned int * array)
{
	unsigned int count=0;
	char c;
	
	c=getchar();
	
	while((c!='\0')&&(c!='\n')&&(c!='\r'))
	{
		*(array+count)=c-'0';
		count++;
		c=getchar();
	}
	
	
	return count;
}



int main(int argc, char **argv)
{
	unsigned int array_count[1000];
	unsigned int array_numbers[1000];
	
	unsigned int raz;
	
	
	for(unsigned int i=0;i<1000;i++)
	*(array_count+i)=1;
	
	//print_array(array_count,1000);
	raz=get_array(array_numbers);
	//print_array(array_numbers,raz);
	
	
	Buble_Sort1(array_numbers,raz);
	//print_array(array_numbers,raz);
	
	
	func2(array_numbers,array_count,raz);
	//
	//raz
	
	return 0;
}


