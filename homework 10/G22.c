/*
 * G22.c
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

#define STR_SIZE 21

#define RESULT_SIZE 5



unsigned int check_vowels(char c)
{
	unsigned int result=0;
	
	if((c=='a')||(c=='e')||(c=='h')||(c=='i')||(c=='o')||(c=='u')||(c=='w')||(c=='y'))
	{
		result=1;
		
	}
	return  result;
}


char convert_consonant_number(char c)
{
	char result='0';
	
	if((c=='b')||(c=='f')||(c=='p')||(c=='v'))
	{
		result='1';
	}
	else if((c=='c')||(c=='g')||(c=='j')||(c=='k')||(c=='q')||(c=='s')||(c=='x')||(c=='z'))
	{
		result='2';
	}
	else if((c=='d')||(c=='t'))
	{
		result='3';
	}
	else if((c=='l'))
	{
		result='4';
	}
	else if((c=='m')||(c=='n'))
	{
		result='5';
	}
	else if((c=='r'))
	{
		result='6';
	}
	
	return result;
}


void func1(char *str,unsigned int size,char *result,unsigned int n)
{
	unsigned int i,count=0;
	
	*(result+0)=*(str+0);
	*(result+n-1)='\0';
	
	for(i=1;i<n-1;i++)
	{
		*(result+i)='0';
		
	}
	count=1;
	
	for(i=1;i<size;i++)
	{
		if((n-1)>count)
		{
			*(result+count)=*(str+i);
			count++;
			while((*(result+count-1)==*(str+i+1))&&(i+1<size))
			{
				i++;
			}
			
			
			
			
		}
		else
		{
			break;
		}
		
	}
	
	
	
}




int main(int argc, char **argv)
{
	signed char c;
	unsigned int count=0,count1=0,i;
	FILE *f;
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	char str[STR_SIZE];
	char str1[STR_SIZE];
	
	char result[RESULT_SIZE];
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		while (((c = fgetc(f)) != EOF)&&(count<STR_SIZE)&&(c!='\n')&&(c!='\r')) 
		{
			str[count++]=c;
			
		}
		
		fclose(f);
		
		f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
			
			str1[count1++]=str[0];
			
			for(i=1;i<count;i++)
			{
				if(check_vowels(str[i])==1)
				{
					;
				}
				else
				{
					str1[count1++]=str[i];
					
				}
				
			}
			
			
			
			for(i=1;i<count1;i++)
			{
				
				str1[i]=convert_consonant_number(str1[i]);
				
			}
			
			
			func1(str1,count1,result,RESULT_SIZE);
			
			fprintf(f,"%s",result);
			
			
			
		fclose(f);
		}
		else
		{
			
		}
	
	}
	else
	{
		;
	}
	
	
	
	return 0;
}

