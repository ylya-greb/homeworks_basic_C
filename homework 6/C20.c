/*
 * C20.c
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



int main(int argc, char **argv)
{
	unsigned int count1=0,count2=0,flag=0;
	char c;
	
	c=getchar();
	
	while(c!='.')
	{
		if(c=='(')
		{
			count1++;
			if(flag!=3)
			{
				flag=1;
			}
		}
		else if(c==')')
		{
			count2++;
			if(!flag)
			{
				flag=3;
			}
			else if(flag!=3)
			{
				flag=2;
			}
			
		}
		c=getchar();
		
	}
	
	if((count1==count2)&&(flag!=3))
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	
	return 0;
}

