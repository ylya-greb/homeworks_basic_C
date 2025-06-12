/*
 * G6.c
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
#include <stdbool.h>
#define STR_SIZE 1000

bool is_palindrom(char * str,unsigned int n );

int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	
	unsigned int count=0;
	char str[STR_SIZE];
	signed char c;
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		
		
		c=fgetc(f);
		while(((c)!=EOF)&&(c!='\n')&&(c!='\r'))
		{
			
			str[count]=c;
			count++;
			
			c=fgetc(f);
		}
		
		fclose(f);
		
		
		f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
			
			if(is_palindrom(str,count))
			{
				fprintf(f,"%s","YES");
				
				
			}
			else
			{
				fprintf(f,"%s","NO");
				
			}
			
			fclose(f);
		}
			
	}
	else
	{
		
	}
	
	
	return 0;
}




bool is_palindrom(char * str,unsigned int n )
{
	bool result=1;
	
	for(unsigned int i=0;i<n/2;i++)
	{
		if((*(str+i))!=(*(str+n-1-i)))
		{
			result=0;
			break;
			
		}
		
	}
	
	return result;
}





