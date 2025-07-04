

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define MONTH_PER_YEAR 12

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

unsigned int AddInfo(struct node** info);

//������� ��� ������ ��������� ������� �����������(��������� ������ �����������)
void swap_sensor(struct temperature_sensor* i,struct temperature_sensor* j);
//������� ��� ������ ������� ��������� ������������ ������
//(��������� �� ����. ������� �� ��������)
void swap_node(struct node* i,struct node* j);

unsigned long long  DateToInt(struct temperature_sensor* info);

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
