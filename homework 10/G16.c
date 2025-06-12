/*
 * G16.c
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

#define STR_SIZE 2000



int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	char name1[]="Ling";
	char name2[]="Cao";
	
	
	unsigned  int count=0,count1=0,i,j;
	char str[STR_SIZE]={0};
	
	char str1[STR_SIZE]={0};
	
	
	
	
	signed char c;
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		while ((c = fgetc(f)) != EOF) 
		{
			str[count++]=c;
		}
		
		fclose(f);
		f=fopen(output_file,"w");
		
			if(f!=NULL)
			{
				
				for(i=0;i<count;i++)
				{
					if((*(str+i)==name1[0])&&(*(str+i+1)==name1[1])&&(*(str+i+2)==name1[2])&&(*(str+i+3)==name1[3]))
					{
						strcat(str1, name2);
						count1+= strlen(name2);
						i+= strlen(name1);
					}
					
					*(str1+count1)=*(str+i);
					count1++;
					
				}
				
				fprintf(f,"%s",str1);
				
				
				fclose(f);
			}
			
	}
	else
	{
		;
	}
	
	
	
	return 0;
}

