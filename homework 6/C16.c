/*
 * C16.c
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


int is_prime(int n);


int main(int argc, char **argv)
{
	int n;
	scanf("%d",&n);
	if(is_prime(n))
		printf("YES");
	else
		printf("NO");
	
	return 0;
}



int is_prime(int n)
{
	int result=1;
	
	if(n>1)
	{
		for(unsigned int i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
			result=0;
			break;
			}
		
		}
	}
	else
	{
	 result=0;   
	}
	
	return result;
}






















