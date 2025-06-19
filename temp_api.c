



#include "temp_api.h"


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


unsigned int AddInfo(struct temperature_sensor* info)
{
	uint32_t counter=0;
	
	AddRecord(info,counter++,2021,9,16,00,05,9);
	AddRecord(info,counter++,2021,9,16,00,10,9);
	AddRecord(info,counter++,2021,9,16,00,30,10);
	
	
	AddRecord(info,counter++,2021,1,2,00,05,-9);
	AddRecord(info,counter++,2021,1,2,00,10,-9);
	AddRecord(info,counter++,2021,1,2,00,30,-10);
	
	
	AddRecord(info,counter++,2021,9,2,00,05,16);
	AddRecord(info,counter++,2021,9,2,00,10,16);
	AddRecord(info,counter++,2021,9,2,00,30,16);
	
	
	AddRecord(info,counter++,2021,1,7,12,00,8);
	AddRecord(info,counter++,2021,1,7,12,10,8);
	AddRecord(info,counter++,2021,1,7,12,30,8);
	
	
	AddRecord(info,counter++,2021,9,5,12,00,22);
	AddRecord(info,counter++,2021,9,5,12,30,23);
	AddRecord(info,counter++,2021,9,5,13,00,24);
	
	
	AddRecord(info,counter++,2021,1,5,12,00,-12);
	AddRecord(info,counter++,2021,1,5,12,30,-12);
	AddRecord(info,counter++,2021,1,5,13,00,-12);
	
	
	return counter;
}



void swap_sensor(struct temperature_sensor* info,int i, int j)
{
	struct temperature_sensor temp;
	temp=info[i];
	info[i]=info[j];
	info[j]=temp;
}

unsigned long long  DateToInt(struct temperature_sensor* info)
{
	unsigned long long  data;
	data= info->month << 24 | info->day<<16 | info->hour<<8 
	|info->minute;
	return data;
}

//функция упорядочивания массива показаний датчика температуры по дате(от ранней к поздней)
void SortByDate(struct temperature_sensor* info,uint32_t n)
{
for(uint32_t i=0; i<n; ++i)
for(uint32_t j=i; j<n; ++j)
{
	if(((info+i)->year)>((info+j)->year))
	{
		swap_sensor(info,i,j);
	}
	else
	{
		if(DateToInt(info+i)>=DateToInt(info+j))
		{
			swap_sensor(info,i,j);
			
		}
		
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







