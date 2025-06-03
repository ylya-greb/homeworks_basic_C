/*
 * F19.c
 * 
 * Copyright 2025 Ylya <Ylya@SADOVOI-PC>
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
#define SIZE1 5
#define SIZE2 5



void get_array(int (*array)[SIZE2],unsigned int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		
		for(unsigned int j=0;j<SIZE2;j++)
		{
			scanf("%d",(*(array+i)+j));
			
		}
	
	}
	
	
}



void print_array(int (*array)[SIZE2],unsigned int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		
		for(unsigned int j=0;j<SIZE2;j++)
		{
			printf("%d ",*(*(array+i)+j));
			
		}
	
	}
	
	
}




int arithmetic_mean_array(int (*array)[SIZE2],unsigned int n)
{
	float result=0;
	unsigned int i=0,j=0;
	
	
	for(i=0,j=0;i<n;i++,j++)
	{
		result+=*(*(array+i)+j);
		
	}
	
	return (result/(float) n);
}



unsigned int func1(int (*array)[SIZE2],unsigned int n)
{
	unsigned int count=0,i,j;
	float arithmetic_mean;
	
	 arithmetic_mean=arithmetic_mean_array(array,n);
	
	
	for(i=0;i<n;i++)
	{
		
		for(j=0;j<SIZE2;j++)
		{
			if((*(*(array+i)+j)>arithmetic_mean)&&(*(*(array+i)+j)>0))
			{
				count++;
			}
		}
		
	}
	
	return count;
}



int main(int argc, char **argv)
{
	int array[SIZE1][SIZE2];
	
	get_array(array,SIZE1);
	
	printf("%u",func1(array,SIZE2));
	
	return 0;
}

