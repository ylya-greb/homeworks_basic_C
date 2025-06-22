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
	//массив структур  с даными о показани€х температуры за год
	struct temperature_sensor data[SIZE];
	//кол-во записей с даными о показани€х температуры за год
	unsigned int count;
	//массив с данными  о среднемес€чной температуре за год
	float average_month_temp[MONTH_PER_YEAR]={0};
	//массив с данными  о  кол-ве записей по  мес€цам(кол-во записей за  каждый мес€ц)
	uint16_t counts_month[MONTH_PER_YEAR]={0};
	//массивы дл€ хрaнени€ макс.и мин температуры за  мес€ц
	int8_t max_temp_month[MONTH_PER_YEAR]={0};
	int8_t min_temp_month[MONTH_PER_YEAR]={0};
	
	//макс и мин температуры за год
	int8_t max_temp_year;
	int8_t min_temp_year;
	//средн€€ температура за год
	float average_year_temp;
	
	//дл€ хранени€ данных командной строки
	char* str;
	//счетчик кол-ва аргументов командной строки
	uint8_t i;
	//им€ .csv  файла с показани€ми датчика температуры
	//задаетс€ с командной строки
	char filename[256];
	//номер мес€ца,введенный в качестве параметра командной строки
	//выводим статистику только за этот мес€ц
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
//перебираем введенные параметры командной строки
//argc- кол-во введенных параметров командной строки
//argv- массив строк (введенных параметров) командной строки
for( i=0; i<argc; i++)
    {
        //printf("argc = %d, argv = %s\n", i, argv[i]);
         str = argv[i];
		//если не введен ключ, то выдаем всю статистику 
		 if(argc==1)
	 	{
		
			print_months_statistic(data,count,average_month_temp, counts_month,max_temp_month,min_temp_month);
			print_year_statistic( average_year_temp, max_temp_year, min_temp_year);

	 	}
	 	else
		{
		 	//если задан ключ,то обрабатываем его
        	if(str[0]=='-')
         	{   switch (str[1])
            	{
				// если задан ключ -h выдаем справку
                	case 'h': 
                    	printf("HELP\n""List of keys:\n"
						"\t -f <filename.csv> input csv file with temperature data from sensor\n"
						"\t -m <month number> print statistic only for choosen month\n"
						"\t -h HELP\n");
                	break;
					// если задан ключ -f считываем им€ .csv файла
                	case 'f':
				   		printf("Filename \n");
				   	//считываем им€ файла
				   	sscanf(argv[i+1],"%s",filename);
				   	printf("Filename : %s \n",filename);

                	break;
					//если задан ключ -m выводим статистику за выбранный мес€ц
					case 'm':
					//printf("Month number \n");
					// считываем номер мес€ца
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

