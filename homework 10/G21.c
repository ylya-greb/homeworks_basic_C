/*
 * G21.c
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


unsigned int check_triangle(unsigned int counter)
{
	unsigned int j,sum_j;
	
	j=1;
	sum_j=j;
	
	while(counter>sum_j)
	{
		j++;
		sum_j+=j;
		
	}
	if(counter!=sum_j)
	{
		j=0;
	}
	
	return j;
}


int main(int argc, char **argv)
{
	
	signed char c;
	unsigned int count=0,rows,i,j,k,n_spaces,n_stars;
	FILE *f;
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		while (((c = fgetc(f)) != EOF)&&(count<STR_SIZE)) 
		{
			if(c=='*')
			{
				count++;
			}
			
		}
		
		fclose(f);
		
		
		f=fopen(output_file,"w");
		
		if(f!=NULL)
		{
			
			rows=check_triangle(count);
			if(rows)
			{
			n_spaces=rows-1;
			n_stars=1;
			
			for(i=1;i<=rows;i++)
			{
				for(j=0;j<n_spaces;j++)
				{
					fprintf(f," ");
					
				}
				
				for(k=0;k<n_stars;k++)
				{
					fprintf(f,"*");
					fprintf(f," ");
				}
			
				fprintf(f,"\n");
				n_stars++;
				n_spaces--;
			}
			
			
			
			
			
			
			}
			else
			{
				fprintf(f,"NO");
			}
			
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

