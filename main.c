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
#include "temp_functions.h"





int main(int argc, char **argv)
{
	//имя .csv  файла с показаниями датчика температуры
	//задается с командной строки
	char filename[256]="temperature_big3.csv";


	//указатель на структуру с данными о показаниях температуры
	//служит для указания на начало динамически выделенной памяти
	struct node * data=NULL;

	//кол-во записей с даными о показаниях температуры за год
	unsigned int count=0;
	//массив с данными  о среднемесячной температуре за год
	float average_month_temp[MONTH_PER_YEAR]={0};
	//массив с данными  о  кол-ве записей по  месяцам(кол-во записей за  каждый месяц)
	uint16_t counts_month[MONTH_PER_YEAR]={0};
	//массивы для хрaнения макс.и мин температуры за  месяц
	int8_t max_temp_month[MONTH_PER_YEAR]={0};
	int8_t min_temp_month[MONTH_PER_YEAR]={0};
	
	//макс и мин температуры за год
	int8_t max_temp_year;
	int8_t min_temp_year;
	//средняя температура за год
	float average_year_temp;
	
	//для хранения данных командной строки
	char* str;
	//счетчик кол-ва аргументов командной строки
	uint8_t i;
	
	//номер месяца,введенный в качестве параметра командной строки
	//выводим статистику только за этот месяц
	uint8_t selected_month;

	FILE *f ;

	//временные переменные для хранения только что считанных  из 
	// .csv-файла с исходных данных
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t temperature;
	
	signed  char ch=0;
	
	//кол-во успешно считанных параметров из 
	// .csv-файла с исходных данных
	int r;
	
	//номер текущей считываемой строки в .csv-файле с исходными данными
	uint32_t line_number=1;
	


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
		
			f=fopen(filename,"r");
		if(f!=NULL)
		{
		while((r = fscanf(f, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",&year,&month,&day,&hour,&minute,&temperature))!=EOF)
    	{
        //если не все данные успешно считали
        if(r<NUM_OF_PARAM )
        {
           printf("!!!Error in line %u\t",line_number);
            do
            {
                putchar(ch);
                ch=fgetc(f);
            } while(EOF!=ch && '\n'!=ch);
//пропускаем оставшиеся символы до конца файла
//или строки (на случай, если строка была
//чересчур длинной
            ch = 0;
            printf("\n");
        }
        else
           {
			 if(validate_input_data(year,month,day,hour,minute,temperature)==0)
			 {
				 //если данные не прошли проверку
				 printf("!!!Error in line \t");
				 printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				 
				 
				 
				}
			 else
			{
				 //если данные прошли проверку
				 //printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				
				 AddInfo(&data,year,month, day, hour, minute, temperature);
				 count++;
			}
			 
			} 
             
            line_number++;
    }
		
		fclose(f);
		
		SortByDate(data);
	
		get_average_month_temp(data,average_month_temp,counts_month);
	
	get_min_max_month_temperature(data,max_temp_month,min_temp_month,counts_month);
	
	
	get_min_max_year_temperature(data,&max_temp_year,&min_temp_year);
	
	average_year_temp=get_average_year_temperature(average_month_temp,counts_month);
	
	print_months_statistic(data,average_month_temp, counts_month,max_temp_month,min_temp_month);
	
	print_year_statistic( average_year_temp, max_temp_year, min_temp_year);
	
	DeleteRecord(&data);
	}

	else
	{
		printf("Error!!!  File %s isn't open\n",filename);
		return 1;
		
	}
	
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
					// если задан ключ -f считываем имя .csv файла
                	case 'f':
				   	//считываем имя файла
				   	sscanf(argv[i+1],"%s",filename);
				   	printf("Filename : %s \n",filename);
					f=fopen(filename,"r");
					if(f!=NULL)
					{
					while((r = fscanf(f, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",&year,&month,&day,&hour,&minute,&temperature))!=EOF)
    				{
        			//если не все данные успешно считали
        			if(r<NUM_OF_PARAM )
        			{
           			printf("!!!Error in line %u\t",line_number);
           			 do
            		{
               		 putchar(ch);
                	ch=fgetc(f);
            		} while(EOF!=ch && '\n'!=ch);
				//пропускаем оставшиеся символы до конца файла
				//или строки (на случай, если строка была
				//чересчур длинной
            		ch = 0;
            		printf("\n");
        			}
        	else
           {
			 if(validate_input_data(year,month,day,hour,minute,temperature)==0)
			 {
				 //если данные не прошли проверку
				 printf("!!!Error in line \t");
				 printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				 
				 
				 
				}
			 else
			{
				 //если данные прошли проверку
				 //printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				 
				 AddInfo(&data,year,month, day, hour, minute, temperature);
				 count++;
			}
			 
			} 
             
            line_number++;
    }
		
		fclose(f);
		SortByDate(data);
	
		get_average_month_temp(data,average_month_temp,counts_month);
	
	get_min_max_month_temperature(data,max_temp_month,min_temp_month,counts_month);
	
	
	get_min_max_year_temperature(data,&max_temp_year,&min_temp_year);

	average_year_temp=get_average_year_temperature(average_month_temp,counts_month);
	
	print_months_statistic(data,average_month_temp, counts_month,max_temp_month,min_temp_month);
	
	print_year_statistic( average_year_temp, max_temp_year, min_temp_year);
	
			DeleteRecord(&data);

			line_number=1;
			count=0;
			reset_average_month_temp(average_month_temp,MONTH_PER_YEAR);
			reset_counts_month(counts_month,MONTH_PER_YEAR);

			reset_max_temp_month(max_temp_month,MONTH_PER_YEAR);

			reset_min_temp_month(min_temp_month,MONTH_PER_YEAR);


	}

		else
		{
		printf("Error!!!  File %s isn't open\n",filename);
		return 1;
		
		}
                	break;
					//если задан ключ -m выводим статистику за выбранный месяц
					case 'm':
					// считываем номер месяца
					sscanf(argv[i+1],"%u",&selected_month);
					//printf("month number=%u\n",month);
					f=fopen(filename,"r");
					if(f!=NULL)
					{
					while((r = fscanf(f, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd",&year,&month,&day,&hour,&minute,&temperature))!=EOF)
    				{
        			//если не все данные успешно считали
        			if(r<NUM_OF_PARAM )
        			{
           			printf("!!!Error in line %u\t",line_number);
           			 do
            		{
               		 putchar(ch);
                	ch=fgetc(f);
            		} while(EOF!=ch && '\n'!=ch);
				//пропускаем оставшиеся символы до конца файла
				//или строки (на случай, если строка была
				//чересчур длинной
            		ch = 0;
            		printf("\n");
        			}
        	else
           {
			 if(validate_input_data(year,month,day,hour,minute,temperature)==0)
			 {
				 //если данные не прошли проверку
				 printf("!!!Error in line \t");
				 printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				 
				 
				 
				}
			 else
			{
				 //если данные прошли проверку
				 //printf("%u :%u %u %u %u %u %d\n",line_number,year,month,day,hour,minute,temperature); 
				 
				 AddInfo(&data,year,month, day, hour, minute, temperature);
				 count++;
			}
			 
			} 
             
            line_number++;
    }
		
		fclose(f);
		SortByDate(data);
	
		get_average_month_temp(data,average_month_temp,counts_month);
	
		get_min_max_month_temperature(data,max_temp_month,min_temp_month,counts_month);
	
		print_month_statistic(data,selected_month,average_month_temp,counts_month,max_temp_month,min_temp_month);
					
		//!!! При считывании с несколькими параметрами во время оброботки втрого паараметра при считывании из
		//файла в последний месяц добавляется какое-то лишнее значение
			DeleteRecord(&data);

			line_number=1;
			count=0;
			reset_average_month_temp(average_month_temp,MONTH_PER_YEAR);
			reset_counts_month(counts_month,MONTH_PER_YEAR);

			reset_max_temp_month(max_temp_month,MONTH_PER_YEAR);

			reset_min_temp_month(min_temp_month,MONTH_PER_YEAR);


	}

		else
		{
		printf("Error!!!  File %s isn't open\n",filename);
		return 1;
		
		}
					
				
					
					break;
                	default:
					printf("Underfined key!\n");
					printf("Enter -h key for HELP\n");
                	break;
            	}
		 	}
		}
    }

	return 0;
}


