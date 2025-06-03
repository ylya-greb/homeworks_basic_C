/*
 * F10.c
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


unsigned int get_string(char * st)
{
	unsigned int count=0;
	char c;
	c=getchar();
	
	while((c!='\0')&&(c!='\n')&&(c!='\r')&&(c!='.'))
	{
		
			if((c>='a')&&(c<='z'))
			{
			*(st+count)=c;
			count++;
			}
		c=getchar();
	}
	
	return  count;
}

void func2(char* array1,unsigned int * array2,int n)
{
	//unsigned int raz=n;
	unsigned int i=0,count=1;
	unsigned int current,next;
	
	current=0;
	//next=1;
	
	for(i=1;i<n;i++)
	{
		next=i;
		if(*(array1+current)==*(array1+next))
		{
			count++;
			*(array1+i)='0';
		}
		else
		{
			*(array2+current)=count;
			count=1;
			current=next;
			
			
		}
		if(i==n-1)
		{
			*(array2+current)=count;
			
			
		}
		/*for(unsigned int j=i+1;j<n;j++)
		{
		
			if((*(array1+i)!='0')&&(*(array1+i)==*(array1+j)))
			{
			//raz--;
			*(array1+j)='0';
			(*(array2+i))++;
			
			}
		
		}*/
		
	}
	
	for( i=0;i<n;i++)
	{
	
	if(*(array1+i)!='0')
	printf("%c%u",*(array1+i),*(array2+i));
	
	}
	//return raz;
}




int main(int argc, char **argv)
{
	char st[1000];
	unsigned int array_count[1000];
	
	unsigned int count;
	
	
	for(unsigned int i=0;i<1000;i++)
	*(array_count+i)=1;
	
	
	count=get_string(st);
	func2(st,array_count,count);
	
	
	return 0;
}

