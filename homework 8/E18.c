/*
 * E18.c
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

void func1(unsigned int number,unsigned int n);

int main(int argc, char **argv)
{
	unsigned int number;
	scanf("%u",&number);
	func1(number,9);
	
	
	
	return 0;
}


void func1(unsigned int number,unsigned int n)
{
	//unsigned int count=0;
	unsigned int array_count[8]={0,0,0,0,0,0,0,0};
	
	
	for(unsigned int i=2;i<=number;i++)
	{
		
		
		for(unsigned int j=2;j<=n;j++)
		{
			
			if(i%j==0)
			{
				(*(array_count+j-2))++;
				
			}
			
		}
		
	}
	
	for(unsigned int k=0;k<8;k++)
	{
		printf("%u\t%u\n",k+2,*(array_count+k));
	
	}
	
}



