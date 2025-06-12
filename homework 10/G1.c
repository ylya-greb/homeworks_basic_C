/*
 * G1.c
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
#include <string.h>
#define STR_SIZE 200


int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	char str[STR_SIZE];
	signed char c;
	
	unsigned int count=0,i,j;
	
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		//printf("File is  open\n");
		
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
			for(i=0;i<3;i++)
			{
				for(j=0;j<strlen(str);j++)
				{
					fprintf(f,"%c",*(str+j));
					
				}
				
				if(i!=2)
				fprintf(f,"%c ",',');
				
				
				
			}
			
			fprintf(f," %llu",strlen(str));
			
			fclose(f);
			
		}
			
			
			
	}
	else
	{
		//printf("File is not opened\n");
		
		
	}
	
	
	
	return 0;
}

