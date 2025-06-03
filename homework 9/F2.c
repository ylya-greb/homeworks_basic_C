
/*
 * F2.c
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
#define SIZE 20


void sort_even_odd(int n, int a[]);
void print_array(int * array,int n);

int main(int argc, char **argv)
{
	int array[SIZE]={ 11, 25, 5, -48, -15, -16, 27, 43, -22, -1, -39, -16, -28, 28, -31, -36, 17, 17, -39, -50};
	
	//int array[SIZE]={1,0,3,2,2};
	
	sort_even_odd(SIZE, array);
	
	print_array(array,SIZE);
	
	return 0;
}



void sort_even_odd(int n, int a[])
{
	int noswap,temp;
	
	for(unsigned int i=n-1;i>=0;i--)
	{
		noswap=1;
		for(unsigned int j=0;j<i;j++)
		{
			if((((*(a+j)%2)==1)&&((*(a+j+1)%2)==0))||(((*(a+j)%2)==-1)&&((*(a+j+1)%2)==0)))
			{
				temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
				
				noswap=0;
				
			}
		}
		if(noswap)
		{
			break;
		}
	}
	
}



void print_array(int * array,int n)
{
	for(unsigned int i=0;i<n;i++)
	printf("%d ",*(array+i));
	
	
}

