/*
 * F4.c
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


void print_digit(char s[])
{
	
	unsigned int count=0,noswap,raz,i;
	char c,temp,s1[100];
	unsigned int array_count[100];
	
	
	for(i=0;i<100;i++)
	{
		*(array_count+i)=1;
	}
	
	
	 i=0;
	 c=*(s+0);
	 while((c!='\0')&&(c!='\n')&&(c!='\r'))
	{
	 
	 if((c>='0')&&(c<='9'))
			{
			*(s1+count)=c;
			count++;
			}
	 i++;
	 c=*(s+i);
	}
	 
	if(count)
	{
		for(unsigned int i=count-1;i>=0;i--)
		{
			noswap=1;
			for(unsigned int j=0;j<i;j++)
			{
				if(*(s1+j)>*(s1+j+1))
				{
					
					temp=*(s1+j);
					*(s1+j)=*(s1+j+1);
					*(s1+j+1)=temp;
					
					noswap=0;
					
				}
			}
			if(noswap)
			{
				break;
			}
		}
	
	}
	
	raz=count;
	
	for(i=0;i<count;i++)
	{
		
		for(unsigned int j=i+1;j<count;j++)
		{
		
			if((*(s1+i)!=10)&&(*(s1+i)==*(s1+j)))
			{
			raz--;
			*(s1+j)=10;
			(*(array_count+i))++;
			
			}
		
		}
		
	}
	
	for( i=0;i<count;i++)
	{
	
	if(*(s1+i)!=10)
	printf("%c %u\n",*(s1+i),*(array_count+i));
	}
	
	
}





int main(int argc, char **argv)
{
	char st[]={"Hello123 world77."};
	
	print_digit(st);
	
	return 0;
}

