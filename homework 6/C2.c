/*
 * C2.c
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

int power(int n,unsigned int p);



int main(int argc, char **argv)
{
	int a;
	unsigned int b;
	scanf("%d",&a);
	scanf("%u",&b);
	printf("%d",power(a,b));
	
	return 0;
}

int power(int n,unsigned int p)
{
	int result=1;
	unsigned int i=0;
	
	while(p>i)
	{
		result*=n;
		i++;
	}
	
	return result;
	}











