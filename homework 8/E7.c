/*
 * E7.c
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
void swap(int *a,int *b);
void inv_array(int * array,int n);




int main(int argc, char **argv)
{
	int array[SIZE];
	
	get_array(array,SIZE);
	
	inv_array(array,SIZE);
	
	for(unsigned int i=0;i<SIZE;i++)
	printf("%d ",*(array+i));
	
	
	return 0;
}


void get_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		scanf("%d",(array+i));
		
	}
	
}


void swap(int *a,int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}

void inv_array(int * array,int n)
{
	
	for(unsigned int i=0;i<n/4;i++)
	{
		swap((array+i),(array+(n/2)-i-1));
		
		swap((array+n-i-1),(array+(n/2)+i));
		
	}
	
}




