/*
 * G8.c
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
#define STR_SIZE 1000


void swap(unsigned int *a,unsigned int *b)
{
	unsigned int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}

void Buble_Sort(unsigned int * array,int n)
{
	int noswap;
	
	for(unsigned int i=n-1;i>=0;i--)
	{
		noswap=1;
		for(unsigned int j=0;j<i;j++)
		{
			if(*(array+j)>*(array+j+1))
			{
				swap((array+j),(array+j+1));
				noswap=0;
				
			}
		}
		if(noswap)
		{
			break;
		}
	}
	
}





int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	
	unsigned int count=0,count1=0,i;
	char str[STR_SIZE];
	unsigned int array_numbers[STR_SIZE];
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
		
		
		for(i=0;i<count;i++)
		{
			if((*(str+i)>='0')&&(*(str+i)<='9'))
			{
				array_numbers[count1]=(*(str+i)-'0');
				while((i<count-1)&&(*(str+i+1)>='0')&&(*(str+i+1)<='9'))
				{
					array_numbers[count1]=array_numbers[count1]*10+(*(str+i+1)-'0');
					
					i++;
					
				}
				
				
				count1++;
			}
			
			
			
		}
		
		
		
	f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
				if(count1>0)
				{
					Buble_Sort(array_numbers,count1);
				
				
					for(i=0;i<count1;i++)
					{
						fprintf(f,"%u ",*(array_numbers+i));
					}
				}
			
			
				fclose(f);
		}
		
		
		
	}
	else
	{
		
	}
	
	
	return 0;
}



