/*
 * G14.c
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

#define STR_SIZE 100




int main(int argc, char **argv)
{
	FILE *f;
	
	char input_file[]="input.txt";
	char output_file[]="output.txt";
	
	char name[STR_SIZE];
	char surname[STR_SIZE];
	
	f=fopen(input_file,"r");
	
	if(f!=NULL)
	{
		
		fscanf(f,"%s",surname);
		fscanf(f,"%s",name);
		
		fclose(f);
		f=fopen(output_file,"w");
		
			if(f!=NULL)
			{
				
				fprintf(f,"Hello, %s %s!",name,surname);
				
				fclose(f);
			}
	}
	else
	{
		;
	}
	
	
	
	return 0;
}

