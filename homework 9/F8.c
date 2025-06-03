/*
 * F8.c
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

unsigned int get_array(unsigned int * array)
{
	unsigned int a,count=0;
	
	scanf("%u",&a);
	
	while(a)
	{
		
		*(array+count)=a;
		count++;
		scanf("%u",&a);
		
	}
	
	
	return  count;
}




void print_array(unsigned int *array,int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		printf("%u ",*(array+i));
		
	}
	
}



void swap(unsigned int *a,unsigned int *b)
{
	unsigned int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}


void Buble_Sort(unsigned int * array,int n)
{
	unsigned int noswap;
	
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

unsigned int func1(unsigned int *array,unsigned int size)
{
	unsigned int result,min,current;
	
	min=*(array+0);
	
	for(unsigned int i=1;i<size;i++)
	{
		current=min+i;
		
		if(current!=*(array+i))
		{
				result=current;
				break;
		}
		
		
	}
	
	return result;
}




int main(int argc, char **argv)
{
	unsigned int array[1000];
	unsigned int count;
	
	count=get_array(array);
	
	Buble_Sort(array,count);
	
	printf("%u",func1(array,count));
	
	return 0;
}

