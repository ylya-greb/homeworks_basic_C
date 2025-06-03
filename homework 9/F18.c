/*
 * F18.c
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
#define SIZE1 10
#define SIZE2 10



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




int max_array(int * array,unsigned int n)
{
	int max=*(array+0);
	
	for(unsigned int i=0;i<n;i++)
	{
		
		if(*(array+i)>max)
		{
			max=*(array+i);
		}
		
	}
	
	
	
	return max;
}







int summ_max(int (*array)[SIZE2],unsigned int n)
{
	int summ_max=0;
	
	
	for(unsigned int i=0;i<n;i++)
	{
		
		summ_max+=max_array(*(array+i),SIZE2);
		
	}
	
	
	return summ_max;
}









int main(int argc, char **argv)
{
	int array[SIZE1][SIZE2];
	
	
	get_array(array,SIZE1);
	
	//print_array(array,SIZE1);
	
	printf("%d",summ_max(array,SIZE1));
	
	
	return 0;
}
