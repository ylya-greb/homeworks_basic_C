/*
 * F11.c
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
#define SIZE 30



void get_array(int *array,unsigned int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		scanf("%d",(array+i));
		
	}
	
}


void summ_min(int *array,unsigned int  size)
{
	unsigned int index1,index2,i,j;
	int sum_min;
	
	index1=0;
	index2=1;
	sum_min=(*(array+0))+(*(array+1));
	
	for(i=0;i<size;i++)
	{
		
		for(j=i+1;j<size;j++)
		{
			if(sum_min>((*(array+i))+(*(array+j))))
			{
				index1=i;
				index2=j;
				sum_min=(*(array+i))+(*(array+j));
			}
			
			
			
			
		}
		
	}
	
	printf("%u %u",index1,index2);
	
}



int main(int argc, char **argv)
{
	int array[SIZE];
	
	get_array(array,SIZE);
	
	summ_min(array,SIZE);
	
	
	
	return 0;
}

