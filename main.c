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

#define SIZE 100




int main(int argc, char **argv)
{
	//������ ��������  � ������ � ���������� ����������� �� ���
	struct temperature_sensor data[SIZE];
	//���-�� ������� � ������ � ���������� ����������� �� ���
	unsigned int count;
	//������ � �������  � �������������� ����������� �� ���
	float average_month_temp[MONTH_PER_YEAR]={0};
	//������ � �������  �  ���-�� ������� ��  �������(���-�� ������� ��  ������ �����)
	uint16_t counts_month[MONTH_PER_YEAR]={0};
	//������� ��� ��a����� ����.� ��� ����������� ��  �����
	int8_t max_temp_month[MONTH_PER_YEAR]={0};
	int8_t min_temp_month[MONTH_PER_YEAR]={0};
	
	//���� � ��� ����������� �� ���
	int8_t max_temp_year;
	int8_t min_temp_year;
	//������� ����������� �� ���
	float average_year_temp;
	
	//��� �������� ������ ��������� ������
	char* str;
	//������� ���-�� ���������� ��������� ������
	uint8_t i;
	//��� .csv  ����� � ����������� ������� �����������
	//�������� � ��������� ������
	char filename[256];
	//����� ������,��������� � �������� ��������� ��������� ������
	//������� ���������� ������ �� ���� �����
	uint8_t month;

	count=AddInfo(data);
	
	 //print(data,count);
	
	SortByDate(data,count);

	get_average_month_temp(data,count,average_month_temp,counts_month);
	
	get_min_max_month_temperature(data,count,max_temp_month,min_temp_month,counts_month);
	
	
	get_min_max_year_temperature(data,count,&max_temp_year,&min_temp_year);
	
	average_year_temp=get_average_year_temperature(average_month_temp,counts_month);
	

	/*
	print(data,count);
	print_month_statistic(data,9,average_month_temp,counts_month,max_temp_month,min_temp_month);
	*/
//���������� ��������� ��������� ��������� ������
//argc- ���-�� ��������� ���������� ��������� ������
//argv- ������ ����� (��������� ����������) ��������� ������
for( i=0; i<argc; i++)
    {
        //printf("argc = %d, argv = %s\n", i, argv[i]);
         str = argv[i];
		//���� �� ������ ����, �� ������ ��� ���������� 
		 if(argc==1)
	 	{
		
			print_months_statistic(data,count,average_month_temp, counts_month,max_temp_month,min_temp_month);
			print_year_statistic( average_year_temp, max_temp_year, min_temp_year);

	 	}
	 	else
		{
		 	//���� ����� ����,�� ������������ ���
        	if(str[0]=='-')
         	{   switch (str[1])
            	{
				// ���� ����� ���� -h ������ �������
                	case 'h': 
                    	printf("HELP\n""List of keys:\n"
						"\t -f <filename.csv> input csv file with temperature data from sensor\n"
						"\t -m <month number> print statistic only for choosen month\n"
						"\t -h HELP\n");
                	break;
					// ���� ����� ���� -f ��������� ��� .csv �����
                	case 'f':
				   		printf("Filename \n");
				   	//��������� ��� �����
				   	sscanf(argv[i+1],"%s",filename);
				   	printf("Filename : %s \n",filename);

                	break;
					//���� ����� ���� -m ������� ���������� �� ��������� �����
					case 'm':
					//printf("Month number \n");
					// ��������� ����� ������
					sscanf(argv[i+1],"%u",&month);
					//printf("month number=%u\n",month);
					print_month_statistic(data,month,average_month_temp,counts_month,max_temp_month,min_temp_month);
					break;
                	default:
					printf("Underfined key!\n");
                	break;
            	}
		 	}
		}
    }

	return 0;
}

