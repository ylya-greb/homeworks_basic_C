



#include "temp_functions.h"


void AddRecord(struct temperature_sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,
int8_t temperature)
{
	
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].hour = hour;
	info[number].minute = minute;
	info[number].temperature = temperature;
	
	
	
}


void DeleteRecord(struct temperature_sensor* info,int number)
{
	
	info[number].year = 0;
	info[number].month = 0;
	info[number].day = 0;
	info[number].hour = 0;
	info[number].minute = 0;
	info[number].temperature = 0;
	
	
	
}


void print(struct temperature_sensor* info,uint32_t number)
{
	printf("===================================\n");
	for(int i=0;i<number;i++)
	printf("%04d-%02d-%02d-%02d-%02d t=%3d\n",
	info[i].year,
	info[i].month,
	info[i].day,
	info[i].hour,
	info[i].minute,
	info[i].temperature
	);
}


void AddInfo(struct temperature_sensor* info,uint32_t count, uint16_t year,
	uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature)
{	
	AddRecord(info,count,year,month,day,hour,minute,temperature);
	
}




void swap_sensor(struct temperature_sensor* info,int i, int j)
{
	struct temperature_sensor temp;
	temp=info[i];
	info[i]=info[j];
	info[j]=temp;
}

uint64_t  DateToInt(struct temperature_sensor* info){
uint64_t  data;
data=(uint64_t)info->year << 40 | info->month << 24 | info->day<<16 | info->hour<<8 
|info->minute;
return data;
}


//функци€ упор€дочивани€ массива показаний датчика температуры по дате(от ранней к поздней)
void SortByDate(struct temperature_sensor* info,uint32_t n)
{
for(uint32_t i=0; i<n; ++i)
for(uint32_t j=i; j<n; ++j)
{
	if(DateToInt(info+i)>=DateToInt(info+j))
		{
			swap_sensor(info,i,j);
			
		}

}


}


void get_average_month_temp(struct temperature_sensor* info,uint32_t n,float * average_month_temp,uint16_t * counts_month)
{
	int64_t temp_sum=0;
	uint8_t i;
	uint16_t j;
	//uint8_t counts_month[12]={0};
	
	//float average_month_temp;
	
	
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		for(j=0;j<n;j++)
		{
			if(((info+j)->month)==i)
			{
				temp_sum+=(info+j)->temperature;
				counts_month[i-1]++;
			}
			
			
			
			
			
		}
		if(counts_month[i-1])
		{
			(*(average_month_temp+i-1))+=(float)temp_sum/counts_month[i-1];
			
			//printf("\n average month temp = %1.2f month=%d temp_sum=%lld  count=%u \n",
			//(*(average_month_temp+i-1)),i,temp_sum,counts_month[i-1]);
			temp_sum=0;
			//count=0;
		}
	}
	
	
}


void get_min_max_month_temperature(struct temperature_sensor* info,uint32_t n,int8_t *max_temp_month,int8_t *min_temp_month,uint16_t * counts_month)
{
	uint16_t i=1,j;
	uint32_t k=0;
	int8_t max_temp,min_temp; 
	
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		if(counts_month[i-1])
		{
			
			
			while((((info+k)->month)!=i)&(k<n))
			{
				k++;
			}
			max_temp=(info+k)->temperature;
			min_temp=(info+k)->temperature;
			k=0;
			
			
			for(j=1;j<n;j++)
			{
				
				if(((info+j)->month)==i)
				{
					
					if(((info+j)->temperature)>max_temp)
					{
						max_temp=(info+j)->temperature;
						
						
					}
					
				
				if(((info+j)->temperature)<min_temp)
				{
					min_temp=(info+j)->temperature;
					
				}
				
				
				}
				
			}
			
			
			*(min_temp_month+i-1)=min_temp;
			*(max_temp_month+i-1)=max_temp;
			//printf("\n min month temp = %d  max month temp = %d month= %u  \n",
			  //*(min_temp_month+i-1),*(max_temp_month+i-1),i);
			
		}
			
			
			
	}
	
	
}




void get_min_max_year_temperature(struct temperature_sensor* info,uint32_t n,int8_t *max_temp_year,int8_t *min_temp_year)
{
	int8_t max_temp,min_temp; 
	uint32_t i=0;
	
	min_temp=((info+0)->temperature);
	max_temp=((info+0)->temperature);
	
	for(i=0;i<n;i++)
	{
		
		if((info+i)->temperature>max_temp)
		{
			max_temp=(info+i)->temperature;
			
		}
		
		
		if((info+i)->temperature<min_temp)
		{
			min_temp=(info+i)->temperature;
			
		}
	}
	
	*max_temp_year=max_temp;
	*min_temp_year=min_temp;
	
	//printf("max_year_temp= %d  min_year_temp= %d \n",max_temp_year,min_temp_year);
	
	
	
}


float get_average_year_temperature(float *average_month_temp,uint16_t *counts_month)
{
	float average_year_temp;
	float sum_temp=0;
	uint8_t i=0,count=0;
	
	
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		if(*(counts_month+i-1))
		{
			sum_temp+=*(average_month_temp+i-1);
			count++;
			
		}
		
	}
	
	average_year_temp=sum_temp/count;
	
	return average_year_temp;
}


void print_month_statistic(struct temperature_sensor* info,uint8_t month,float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month)
{
	
	if((month>=1)&&(MONTH_PER_YEAR>=month))
	{
		printf("\n  #\tYear\tMonth\tNuValue\tMonthAvg MonthMax MonthMin\n");
		
		printf("  %u\t%u\t%u\t%u \t%.2f \t %d \t  %d \n",
		month,info->year,month,*(counts_month+month-1),*(average_month_temp+month-1),*(max_temp_month+month-1),*(min_temp_month+month-1));
		
	}
	
}


void print_months_statistic(struct temperature_sensor* info,uint32_t n,float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month)
{
	uint16_t i=1;
	
	printf("\n  #\tYear\tMonth\tNuValue\tMonthAvg MonthMax MonthMin\n");
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		printf("  %u\t%u\t%u\t%u \t%.2f \t %d \t  %d \n",
		i-1,info->year,i,*(counts_month+i-1),*(average_month_temp+i-1),*(max_temp_month+i-1),*(min_temp_month+i-1));
		
	}
	
}


void print_year_statistic(float average_year_temp,int8_t max_temp_year,int8_t min_temp_year)
{
	
	printf("Year statistic: average is %.2f, max is %d , min is %d  \n",average_year_temp, max_temp_year, min_temp_year);
	
	
}



//функци€ валидации(проверки корректности) входных данных (строки из .csv файла)
//возвр. 0 если данные некорректные, 1 -если правильные
unsigned int validate_input_data(uint16_t year,uint8_t month,
	uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature)
{
	unsigned int result=1;
	
	if(temperature>MAX_TEMP||temperature<MIN_TEMP)
	{result=0;}
	if(minute>MAX_MINUTE)
	{result=0;}
	if(hour>MAX_HOUR)
	{result=0;}
	if(month>MONTH_PER_YEAR)
	{result=0;}
	if(year>MAX_YEAR||year<MIN_YEAR)
	{result=0;}
	//если год не высокосный
	if(year%4)
	{
		if(day>days_in_month[month-1])
		{result=0;}
		
		
	}
	else
	{
		//если год высокосный и мес€ц-февраль
		if(month==FEBRUARY)
		{
			if(day>(++days_in_month[month-1]))
			{result=0;}
			
		}
		else
		{
			if(day>days_in_month[month-1])
			{result=0;}
			
		}
		
		
	}
	
	
	
	return result;
}




void reset_average_month_temp(float *average_month_temp,uint8_t n)
{
	for(uint8_t i=0;i<n;i++)
	*(average_month_temp+i)=0;

}


void reset_counts_month(uint16_t *counts_month,uint8_t n)
{
	for(uint8_t i=0;i<n;i++)
	*(counts_month+i)=0;

}


void reset_max_temp_month(uint8_t *max_temp_month,uint8_t n)
{
	for(uint8_t i=0;i<n;i++)
	*(max_temp_month+i)=0;

}


void reset_min_temp_month(uint8_t *min_temp_month,uint8_t n)
{
	for(uint8_t i=0;i<n;i++)
	*(min_temp_month+i)=0;

}





