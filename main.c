/*
 * main.c
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
#include "temp_api.h"



int main(int argc, char **argv)
{
	//������ ��������  � ������ � ���������� ����������� �� ���
	struct temperature_sensor data[100];
	//���-�� ������� � ������ � ���������� ����������� �� ���
	unsigned int count;
	//������ � �������  � �������������� ����������� �� ���
	float average_month_temp[12]={0};
	//������ � �������  �  ���-�� ������� ��  �������(���-�� ������� ��  ������ �����)
	uint16_t counts_month[12]={0};
	//������� ��� ��a����� ����.� ��� ����������� ��  �����
	int8_t max_temp_month[12]={0};
	int8_t min_temp_month[12]={0};
	
	//���� � ��� ����������� �� ���
	int8_t max_temp_year;
	int8_t min_temp_year;
	//������� ����������� �� ���
	float average_year_temp;
	
	count=AddInfo(data);
	
	 print(data,count);
	
	SortByDate(data,count);
	
	print(data,count);
	
	
	get_average_month_temp(data,count,average_month_temp,counts_month);
	
	/*
	for(unsigned int i=0;i<12;i++)
	{
		printf("\n count=%u  average_month_temp=%f \n",*(counts_month+i),*(average_month_temp+i));
		
		
	}
	*/
	
	get_min_max_month_temperature(data,count,max_temp_month,min_temp_month,counts_month);
	
	
	get_min_max_year_temperature(data,count,&max_temp_year,&min_temp_year);
	//printf("max_year_temp= %d  min_year_temp= %d \n",max_temp_year,min_temp_year);
	
	
	average_year_temp=get_average_year_temperature(average_month_temp,counts_month);
	
	
	print_months_statistic(data,count,average_month_temp, counts_month,max_temp_month,min_temp_month);
	print_year_statistic( average_year_temp, max_temp_year, min_temp_year);
	
	
	
	return 0;
}

