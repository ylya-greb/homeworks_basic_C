/*
 * F7.c
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


void print_array(int *array,int n)
{
	
	for(unsigned int i=0;i<n;i++)
	{
		printf("%d ",*(array+i));
		
	}
	
}



int compression(int a[], int b[], int N)
{
	int count=0,current,next;
	 int count1=0;
	
	current=0;
	
	for(unsigned int i=0;i<N;i++)
	{
		next=*(a+i);
		if(current==next)
		{
			count1++;
			
		}
		else
		{
			*(b+count)=count1;
			count1=1;
			current=next;
			count++;
		
		}
		
		if(i==N-1)
		{
			*(b+count)=count1;
			count++;
			
		}
	}
	
	return count;
}




int main(int argc, char **argv)
{
	//int array1[100];
	//int array2[100];
	int array_size;
	int array1[10]={0,1,1,0,1,0,1,0,1,0};
	int array2[10];
	
	
	array_size=compression(array1, array2,10);
	print_array(array2,array_size);
	
	
	return 0;
}

