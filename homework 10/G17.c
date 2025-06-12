/*
 * G17.c
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




void swap(char *a,char *b)
{
	char temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}


void change_neighbor_symbols(char *s,unsigned int count)
{
	unsigned int index1,index2,i,count1=0; 
	
	for(i=0;i<count;i++)
	{
		if ((*(s+i)) != ' ') 
		{
			if (count1==0) 
			{
				index1=i; 
				count1=1;
			} 
			else 
			{
				index2=i; 
				count1=2;
			}
		}
		if (count1 == 2) 
		{
			swap((s+index1),(s+index2));
			count1=0;
		} 
	}
	
}




int main(int argc, char **argv)
{
	
	FILE *f;
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	unsigned  int count=0,i;
	
	char str[STR_SIZE]={0};
	
	count=get_array_from_file("r",input_file,str,STR_SIZE);
	
	f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
			
			change_neighbor_symbols(str,count);
			
			for(i=0;i<count;i++)
			fprintf(f,"%c",*(str+i));
			
			
			fclose(f);
		}
		
	return 0;
}

