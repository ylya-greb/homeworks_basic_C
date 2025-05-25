/*
 * E8.c
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
#define SIZE 12


void get_array(int * array,int n);
void swap(int *a,int *b);
void inv_array(int * array,int n);
void print_array(int * array,int n);



int main(int argc, char **argv)
{
	int array[SIZE];
	
	get_array(array,SIZE);
	
	inv_array(array,SIZE);
	
	print_array(array,SIZE);
	
	
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
	
	for(unsigned int i=0;i<n/6;i++)
	{
		swap((array+i),(array+(n/3)-i-1));
		swap((array+(n/3)+i),(array+(2*n/3)-i-1));
		swap((array+(2*n/3)+i), (array+n-i-1));
		
	}
	
}


void print_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%d ",*(array+i));
	
	
}


