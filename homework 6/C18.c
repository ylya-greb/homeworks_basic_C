/*
 * C18.c
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

 int is_digit(char c);

int main(int argc, char **argv)
{
	char c;
	unsigned int count=0;
	c=getchar();
	
	while(c!='.')
	{
		count+=is_digit(c);
		c=getchar();
	}
	printf("%u",count);
	
	return 0;
}


int is_digit(char c)
{
	if((c>='0')&&(c<='9'))
	{
		return 1;
	}
	else
		return 0;
}









