/*
 * E14.c
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


void get_array(int * array,int n);
void print_array(int * array,int n);
bool check_element(int element,int *array,int n);
unsigned int func1(int *array1,int *array2,int n);

int main(int argc, char **argv)
{
	int array[SIZE];
	int array2[SIZE];
	unsigned int index;
	
	get_array(array,SIZE);
	index=func1(array,array2,SIZE);
	print_array(array2,index);
	
	return 0;
}


void get_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		scanf("%d",(array+i));
		
	}
	
}


void print_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%d ",*(array+i));
	
	
}


bool check_element(int element,int *array,int n)
{
	bool  result=0;
	
	for(unsigned int i=0;i<n;i++)
	{
		if(*(array+i)==element)
		{
			result=1;
			break;
		}
		
	}
	
	return result;
}


unsigned int func1(int *array1,int *array2,int n)
{
	unsigned int j=0,count=0;
	
	for(unsigned int i=0;i<n;i++)
	{
		for(unsigned int j1=i;j1<n;j1++)
		{
			if((*(array1+i)==*(array1+j1))&&(check_element(*(array1+i),array2,j)==0))
			{
				count++;
				if(count>1)
				{
					*(array2+j)=*(array1+i);
					j++;
				}
				
			}
		}
		count=0;
	}
	return j;
}
