/*
 * G18.c
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
#include <string.h>

#define STR_SIZE 1005


unsigned int get_array_from_file(char * mode,char *name,char *array,unsigned int size)
{
	signed char c;
	unsigned int count=0;
	FILE *f;
	
	f=fopen(name,mode);
	
	if(f!=NULL)
	{
		
		while (((c = fgetc(f)) != EOF)&&(count<size)&&(c!='\n')&&(c!='\r')) 
		{
			
			array[count++]=c;
			
		}
		
		fclose(f);
	
	
	}
	else
	{
		;
	}
	return count;
}





unsigned int delete_spaces(char *s,char * str1,unsigned int count)
{
	unsigned int i,count2=0,count_spaces=0; 
	
	for(i=0;i<count;i++)
	{
		if ((*(s+i) == ' ')) 
		{ 
			if ((count_spaces==0) && (count2!=0)) 
			{
				count_spaces++;
			}
		}
		else 
		{
			if (count_spaces) 
			{
				*(str1+count2)=' ';
				count2++;
			} 
			*(str1+count2)=*(s+i);
			 count2++;  
			count_spaces=0;
		}
		
		
	}
	
	return count2;
}




int main(int argc, char **argv)
{
	
	FILE *f;
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	unsigned  int count=0,i,count2=0;
	
	char str[STR_SIZE]={0};
	char str1[STR_SIZE]={0};
	
	count=get_array_from_file("r",input_file,str,STR_SIZE);
	
	f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
			
			count2=delete_spaces(str, str1, count);
			
			for(i=0;i<count2;i++)
			fprintf(f,"%c",*(str1+i));
			
			
			fclose(f);
		}
		
	return 0;
}



