/*
 * C4.c
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



int function(int x);





int main(int argc, char **argv)
{
	int x,max,y;
	
	scanf("%d",&x);
	max=function(x);
	
	while(x)
	{
		y=function(x);
		if(y>max)
		{
		max=y;
		}
		
		
		scanf("%d",&x);
	}
	
	printf("%d",max);
	
	
	return 0;
}


int function(int x)
{
	int result;
	
	if(x<-2)
	{
		result=4;
	}
	else if (x>=2)
	{
		result=x*x+4*x+5;
	}
	else
	{
		result=x*x;
	}
	
	
	return result;
}




















