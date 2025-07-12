#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H


#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define MONTH_PER_YEAR 12


//���-�� ����������,���������� � ����� ������ � .csv-�����
#define NUM_OF_PARAM 6

//���� � ��� ���������� �����������
#define MAX_TEMP  99

#define MIN_TEMP  -99

//���� � ��� ���������� ����
#define MAX_YEAR 2100

#define MIN_YEAR 2000




//������ ���-�� ���� � ������� � ������������ ����
static uint8_t days_in_month[MONTH_PER_YEAR]={31,28,31,30,31,30,31,31,30,31,30,31};


#define  FEBRUARY 2


#define  MAX_MINUTE 59

#define  MAX_HOUR   23

#define  MAX_DAY   366






//��������,����������� ���������  ������� �����������
struct temperature_sensor{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t temperature;
	};

//���������, ����������� ������-������� ������������ ������
struct node 
{
	struct temperature_sensor temp_sensor;
	struct node *next;
};




//������� ���������� ������ ��������� ������� �����������
void AddRecord(struct temperature_sensor* info,
uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,
int8_t temperature);

//������� �������� ������ ��������� ������� �����������
void DeleteRecord(struct node**  info);
//������� ������ ��������� ������� �����������
void print(struct node* info);

void AddInfo(struct node** info,uint16_t year,
	uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature);

//������� ��� ������ ��������� ������� �����������(��������� ������ �����������)
void swap_sensor(struct temperature_sensor* i,struct temperature_sensor* j);
//������� ��� ������ ������� ��������� ������������ ������
//(��������� �� ����. ������� �� ��������)
void swap_node(struct node* i,struct node* j);

uint64_t  DateToInt(struct temperature_sensor* info);

//������� �������������� ������� ��������� ������� ����������� �� ����(�� ������ � �������)
void SortByDate(struct node* info);

//������� ���������� ������� ����������� �� ������  �����
void get_average_month_temp(struct node*  info,
float * average_month_temp,uint16_t * counts_month);

//������� ����������� ���. � ����. ����������� �� ������  �����
void get_min_max_month_temperature(struct node*  info,
int8_t *max_temp_month,int8_t *min_temp_month,uint16_t * counts_month);

//������� ����������� ���. � ����. ����������� �� ���
void get_min_max_year_temperature(struct node*  info,
int8_t *max_temp_year,int8_t *min_temp_year);

//������� ���������� ������� ����������� �� ���
float get_average_year_temperature(float *average_month_temp,uint16_t *counts_month);

//������� ��� ������ ���������� �� �����
void print_month_statistic(struct node*  info,uint8_t month,
float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,int8_t * min_temp_month);

//������� ��� ������ ���������� �� ������
void print_months_statistic(struct node* info,
float *average_month_temp,uint16_t * counts_month,int8_t * max_temp_month,
int8_t * min_temp_month);

//������� ��� ������ ���������� �� ���
void print_year_statistic(float average_year_temp,int8_t max_temp_year,
int8_t min_temp_year);

//������� ���������(�������� ������������) ������� ������ (������ �� .csv �����)
//�����. 0 ���� ������ ������������, 1 -���� ����������
unsigned int validate_input_data(uint16_t year,uint8_t month,
	uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature);

void reset_average_month_temp(float *average_month_temp,uint8_t n);

void reset_counts_month(uint16_t *counts_month,uint8_t n);

void reset_max_temp_month(uint8_t *max_temp_month,uint8_t n);

void reset_min_temp_month(uint8_t *min_temp_month,uint8_t n);

















#endif
