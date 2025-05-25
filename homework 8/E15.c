/*
 * E15.c
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
#define SIZE 10


void get_array(int * array,int n);
void print_array(int * array,int n);

unsigned int func1(int *array1,int *array2,int n);
unsigned int func2(int *array1,int *array2,int n);




int main(int argc, char **argv)
{
	int array[SIZE];
	int array2[SIZE];
	int array3[SIZE];
	unsigned int index1,index2;
	
	
	get_array(array,SIZE);
	index1=func1(array,array2,SIZE);
	index2=func2(array,array3,SIZE);
	print_array(array2,index1);
	print_array(array3,index2);
	
	
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


unsigned int func1(int *array1,int *array2,int n)
{
	unsigned int j=0;
	
	for(unsigned int i=0;i<n;i++)
	{
		if(*(array1+i)>0)
		{
			*(array2+j)=*(array1+i);
			j++;
		}
		
	}
	
	return j;
}




unsigned int func2(int *array1,int *array2,int n)
{
	unsigned int j=0;
	
	for(unsigned int i=0;i<n;i++)
	{
		if(*(array1+i)<0)
		{
			*(array2+j)=*(array1+i);
			j++;
		}
		
	}
	
	return j;
	
}

