/*
 * E3.c
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
int min_array(int * array,int n);
int max_array(int * array,int n);


int main(int argc, char **argv)
{
	int array[SIZE];
	int max_index=0,min_index=0;
	
	get_array(array,SIZE);
	
	max_index=max_array(array,SIZE);
	min_index=min_array(array,SIZE);
	printf("%d %d %d %d",max_index,*(array+max_index-1),min_index,*(array+min_index-1));
	
	
	
	return 0;
}



void get_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		scanf("%d",(array+i));
		
	}
	
}

int min_array(int * array,int n)
{
	int index=1;
	int min=*array;

	
	for(unsigned int i=1;i<n;i++)
	{
		if(min>*(array+i))
		{
			min=*(array+i);
			index=i+1;
		}
		
	}
	
	return index;
}



int max_array(int * array,int n)
{
	int index=1;
	int max=*array;
	
	for(unsigned int i=1;i<n;i++)
	{
		if(*(array+i)>max)
		{
			max=*(array+i);
			index=i+1;
		}
		
	}
	
	return index;
}




