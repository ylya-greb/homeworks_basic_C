/*
 * D9.c
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

int sum_digits(int n);


int main(int argc, char **argv)
{
	int n;
	scanf("%d",&n);
	printf("%d",sum_digits(n));
	
	
	
	
	return 0;
}

int sum_digits(int n)
{
	int sum=0;
	if(n)
	{
		sum=(n%10)+sum_digits(n/10);
	}
	
	return sum;
}













