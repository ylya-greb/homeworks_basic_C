



#include "temp_api.h"


void AddRecord(struct temperature_sensor* info,
uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,
int8_t temperature)
{
	
	info->year = year;
	info->month = month;
	info->day = day;
	info->hour = hour;
	info->minute = minute;
	info->temperature = temperature;

	
	
	
}


void DeleteRecord(struct node** info)
{
	
	struct node *ptmp;
	
	
	while((*info)->next!=NULL)
	{
		ptmp=*info;
		*info=ptmp->next;
		free(ptmp);
		
	}
	
}




void print(struct node* info){
printf("===================================\n");
while(info!=NULL)
{
	printf("%04d-%02d-%02d-%02d-%02d t=%3d\n",
	info->temp_sensor.year,
	info->temp_sensor.month,
	info->temp_sensor.day,
	info->temp_sensor.hour,
	info->temp_sensor.minute,
	info->temp_sensor.temperature
	);
	info=info->next;
}

}


unsigned int AddInfo(struct node** info)
{
	uint32_t counter=0;
	struct node *ptmp,*ptmp1;
	
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	*info=ptmp;
	
	
	
	if(ptmp!=NULL)
	{
	AddRecord(&(ptmp->temp_sensor),2021,9,16,00,05,9);
	counter++;
	ptmp->next=NULL;
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,16,00,10,9);
	counter++;
	ptmp->next=NULL;
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,16,00,30,10);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,2,00,05,-9);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,2,00,10,-9);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,2,00,30,-10);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,2,00,05,16);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,2,00,10,16);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,2,00,30,16);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,7,12,00,8);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,7,12,10,8);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,7,12,30,8);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,5,12,00,22);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,5,12,30,23);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,9,5,13,00,24);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,5,12,00,-12);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,5,12,30,-12);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	ptmp=(struct node *)malloc(sizeof(struct node));
	
	if(ptmp!=NULL)
	{
	ptmp1->next=ptmp;
	AddRecord(&(ptmp->temp_sensor),2021,1,5,13,00,-12);
	counter++;
	ptmp->next=NULL;
	
	ptmp1=ptmp;
	
	
	
	
	}
	
	
	}
	
	
	}
	
	
	
	}
	
	}
	
	
	}
	
	
	
	}
	
	
	}
	}
	
	
	
	}
	}
	}
	
	}
	}
	}
	
	}
	
	
	}
	}
	
	
	return counter;
}





void swap_sensor(struct temperature_sensor* i,struct temperature_sensor* j)
{
struct temperature_sensor temp;
temp=*i;

*i=*j;
*j=temp;
}





void swap_node(struct node* i,struct node* j)
{

swap_sensor(&(i->temp_sensor),&(j->temp_sensor));

}



unsigned long long  DateToInt(struct temperature_sensor* info)
{
	unsigned long long  data;
	data= info->month << 24 | info->day<<16 | info->hour<<8 
	|info->minute;
	return data;
}

//функция упорядочивания массива показаний датчика температуры по дате(от ранней к поздней)
void SortByDate(struct node* info)
{
	struct node* ptmpi;
	struct node* ptmpj; 
	
	for(ptmpi=info; ptmpi!=NULL;ptmpi=ptmpi->next)
	{
		for(ptmpj=ptmpi; ptmpj!=NULL; ptmpj=ptmpj->next)
		{
			if((ptmpi->temp_sensor.year)>(ptmpj->temp_sensor.year))
			{
				swap_node(ptmpi,ptmpj);
			}
			else
			{
				if(DateToInt(&(ptmpi->temp_sensor))>=DateToInt(&(ptmpj->temp_sensor)))
				{
					
					swap_node(ptmpi,ptmpj);
				}
				
				
			}
					
			
		}
	}
	
}




void get_average_month_temp(struct node* info,float * average_month_temp,uint16_t * counts_month)
{
	int64_t temp_sum=0;
	uint8_t i;
	uint16_t j;
	
	struct node* ptmpj; 
	
	//uint8_t counts_month[12]={0};
	
	//float average_month_temp;
	
	
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		for(ptmpj=info;ptmpj!=NULL; ptmpj=ptmpj->next)
		{
			if((ptmpj->temp_sensor.month)==i)
			{
				temp_sum+=ptmpj->temp_sensor.temperature;
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




void get_min_max_month_temperature(struct node* info,int8_t *max_temp_month,int8_t *min_temp_month,uint16_t * counts_month)
{
	uint16_t i=1,j;
	uint32_t k=0;
	int8_t max_temp,min_temp; 
	struct node* ptmp;
	struct node* ptmpj;
	
	ptmp=info;
	
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		if(counts_month[i-1])
		{
			
			
			while(((ptmp->temp_sensor.month)!=i)&(ptmp!=NULL))
			{
				
				ptmp=ptmp->next;
			}
			max_temp=ptmp->temp_sensor.temperature;
			min_temp=ptmp->temp_sensor.temperature;
			ptmp=info;
			
			
			for(ptmpj=info->next;ptmpj!=NULL;ptmpj=ptmpj->next)
			{
				
				if((ptmpj->temp_sensor.month)==i)
				{
					
					if((ptmpj->temp_sensor.temperature)>max_temp)
					{
						max_temp=ptmpj->temp_sensor.temperature;
						
						
					}
					
				
				if((ptmpj->temp_sensor.temperature)<min_temp)
				{
					min_temp=ptmpj->temp_sensor.temperature;
					
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




void get_min_max_year_temperature(struct node* info,int8_t *max_temp_year,int8_t *min_temp_year)
{
	int8_t max_temp,min_temp; 
	uint32_t i=0;
	struct node* ptmp=info;
	
	min_temp=(info->temp_sensor.temperature);
	max_temp=(info->temp_sensor.temperature);
	
	for(ptmp=info;ptmp!=NULL;ptmp=ptmp->next)
	{
		
		if(ptmp->temp_sensor.temperature>max_temp)
		{
			max_temp=ptmp->temp_sensor.temperature;
			
		}
		
		
		if(ptmp->temp_sensor.temperature<min_temp)
		{
			min_temp=ptmp->temp_sensor.temperature;
			
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


void print_month_statistic(struct node* info,uint8_t month,float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month)
{
	
	if((month>=1)&&(MONTH_PER_YEAR>=month))
	{
		printf("\n  #\tYear\tMonth\tNuValue\tMonthAvg MonthMax MonthMin\n");
		
		printf("  %u\t%u\t%u\t%u \t%.2f \t %d \t  %d \n",
		month,info->temp_sensor.year,month,*(counts_month+month-1),*(average_month_temp+month-1),*(max_temp_month+month-1),*(min_temp_month+month-1));
		
	}
	
}




void print_months_statistic(struct node* info,float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month)
{
	uint16_t i=1;
	
	printf("\n  #\tYear\tMonth\tNuValue\tMonthAvg MonthMax MonthMin\n");
	for(i=1;i<=MONTH_PER_YEAR;i++)
	{
		
		printf("  %u\t%u\t%u\t%u \t%.2f \t %d \t  %d \n",
		i-1,info->temp_sensor.year,i,*(counts_month+i-1),*(average_month_temp+i-1),*(max_temp_month+i-1),*(min_temp_month+i-1));
		//ptmp=ptmp->next;
	}
	
}



void print_year_statistic(float average_year_temp,int8_t max_temp_year,int8_t min_temp_year)
{
	
	printf("Year statistic: average is %.2f, max is %d , min is %d  \n",average_year_temp, max_temp_year, min_temp_year);
	
	
}







