

#include <stdio.h>
#include <inttypes.h>
#include <string.h>


#define MONTH_PER_YEAR 12

//структра,описывающая показания  датчика температуры
struct temperature_sensor{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t temperature;
	};

//функция добавление записи показания датчика температуры
void AddRecord(struct temperature_sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,
int8_t temperature);

//функция удаления записи показания датчика температуры
void DeleteRecord(struct temperature_sensor* info,int number);
//функция печати показаний датчика температуры
void print(struct temperature_sensor* info,uint32_t number);

unsigned int AddInfo(struct temperature_sensor* info);

void swap_sensor(struct temperature_sensor* info,int i, int j);

unsigned long long  DateToInt(struct temperature_sensor* info);

//функция упорядочивания массива показаний датчика температуры по дате(от ранней к поздней)
void SortByDate(struct temperature_sensor* info,uint32_t n);

//функция вычисления средней температуры за каждый  месяц
void get_average_month_temp(struct temperature_sensor* info,uint32_t n,
float * average_month_temp,uint16_t * counts_month);

//функция определения мин. и макс. температуры за каждый  месяц
void get_min_max_month_temperature(struct temperature_sensor* info,uint32_t n,
int8_t *max_temp_month,int8_t *min_temp_month,uint16_t * counts_month);

//функция определения мин. и макс. температуры за год
void get_min_max_year_temperature(struct temperature_sensor* info,
uint32_t n,int8_t *max_temp_year,int8_t *min_temp_year);

//функция вычисления средней температуры за год
float get_average_year_temperature(float *average_month_temp,uint16_t *counts_month);

//функция для печати статистики за месяц
void print_month_statistic(struct temperature_sensor* info,uint8_t month,
float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month);

//функция для печати статистики за месяцы
void print_months_statistic(struct temperature_sensor* info,uint32_t n,
float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,
int8_t * min_temp_month);

//функция для печати статистики за год
void print_year_statistic(float average_year_temp,int8_t max_temp_year,
int8_t min_temp_year);
