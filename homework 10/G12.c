/*
 * G12.c
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
#define STR_SIZE 1000




int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	
	unsigned  int count=0,count1=0,i,j;
	char str[STR_SIZE];
	
	char word[STR_SIZE];
	
	
	signed char c;
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		
		c=fgetc(f);
		while(((c)!=EOF)&&(c!='\n')&&(c!='\r')&&((count)<STR_SIZE))
		{
			
			str[count]=c;
			count++;
			
			c=fgetc(f);
		}
		
		fclose(f);
		f=fopen(output_file,"w");
		
			if(f!=NULL)
			{
				for(i=0;i<count;i++)
				{
					
					if((*(str+i)!=' ')&&((*(str+i)>='A'&&*(str+i)<='Z')||(*(str+i)>='a'&&*(str+i)<='z')||(*(str+i)>='0'&&*(str+i)<='9')))
					{
						
						*(word+count1)=*(str+i);
						count1++;
						i++;
						while((*(str+i)!=' ')&&(i<count))
						{
							
							*(word+count1)=*(str+i);
							count1++;
							i++;
							
						}
						
						for(j=0;j<count1;j++)
						fprintf(f,"%c",*(word+j));
						
						fprintf(f,"\n");
						
					}
					
					
					
					count1=0;
					
					
				}
				
				
				
				fclose(f);
			}
			
		
		
		
	}
	else
	{
		;
	}
	
	
	
	return 0;
}

