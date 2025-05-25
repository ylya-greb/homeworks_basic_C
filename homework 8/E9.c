/*
 * E9.c
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
void cyclic_shift_right(int * array,int n,unsigned int shift);


int main(int argc, char **argv)
{
	int array[SIZE];
	
	get_array(array,SIZE);
	cyclic_shift_right( array,SIZE,1);
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


void print_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%d ",*(array+i));
	
	
}



void cyclic_shift_right(int * array,int n,unsigned int shift)
{
	int temp;
	
	
	for (unsigned int i=0; i<shift; i++)
	{
		 temp = *(array+n-1);
		for (unsigned int j=n-1; j>0; j--)
		{
			*(array+j)= *(array+j-1);
		}
		*(array+0)=temp;
	}
	
	
	
}





