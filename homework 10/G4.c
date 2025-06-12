/*
 * G4.c
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

#define STR_SIZE 105



void swap(char *a,char *b)
{
	char temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
	
	
}




void Buble_Sort(char * array,int n)
{
	unsigned int noswap;
	if(n)
	{
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
	
}

void func1(char a[], int size){   
	
	char c1,c2;
	
	for (int i = 0; i < size-1; i++)
	{
		c1=*(a+i);
		for (int j = i+1; j < size; j++)
		{
			c2=*(a+j);
			if ((c1 == c2) && (c1!='9') ) 
			{
				*(a+i)='9';
				*(a+j)='9';
			}
		}
	}
}



int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	char word1[STR_SIZE];
	char word2[STR_SIZE];
	
	char word_repeate[STR_SIZE];
	
	unsigned  int count1=0,count2=0,count_rep=0,i,j;
	
	signed char c;
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		while ((c = fgetc(f)) != ' ') 
		{
			word1[count1++]=c;
		}
		
		
		while ((c = fgetc(f)) != EOF) 
		{
			word2[count2++]=c;
		}
		
		
		
		fclose(f);
		f=fopen(output_file,"w");
		
			if(f!=NULL)
			{
				
				func1(word1,count1);
				func1(word2, count2);
				
				
				for(i=0;i<count1;i++)
				{
					
					for(j=0;j<count2;j++)
					{
						if((*(word1+i)==*(word2+j))&&(word1[i]!='9') )
						{
							*(word_repeate+count_rep)=*(word1+i);
							count_rep++;
							
						}
						
						
					}
					
				}
				
				
				Buble_Sort(word_repeate,count_rep);
				
				for(i=0;i<count_rep;i++)
				{
					fprintf(f,"%c ",*(word_repeate+i));
					
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

