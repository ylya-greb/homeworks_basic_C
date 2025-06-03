/*
 * F12.c
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



void get_array(int *array,unsigned int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		scanf("%d",(array+i));
		
	}
	
}



void print_array( int *array,int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		printf("%d ",*(array+i));
		
	}
	
}



void change_max_min(int size, int a[])
{
	int min,max,temp;
	unsigned int max_index,min_index,i;
	
	
	min=*(a+0);
	max=*(a+0);
	min_index=0;
	max_index=0;
	
	
	for(i=1;i<size;i++)
	{
		if(*(a+i)>max)
		{
			max=*(a+i);
			max_index=i;
		}
		
		if(*(a+i)<min)
		{
			min=*(a+i);
			min_index=i;
		}
		
		
	}
	
	temp=*(a+max_index);
	*(a+max_index)=*(a+min_index);
	*(a+min_index)=temp;
	
	
}


int main(int argc, char **argv)
{
	int array[SIZE];
	
	get_array(array,SIZE);
	
	change_max_min(SIZE, array);
	
	print_array(array,SIZE);
	
	return 0;
}

