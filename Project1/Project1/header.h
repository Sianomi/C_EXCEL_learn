#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS
#define LIST_MAX 30
#define COMPANY_NAME_MAX 20
#define NAME_MAX 10
#define EMAIL_MAX 30
#define UNIVERSITY_MAX 50
#define MAJOR_MAX 80
#define MASTER_PATH "C:\\result\\result.txt"
#define OUTPUT_FORM "%-20s%-10s%-30s%-40s%-80s\n"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
	bool leader_flag{ false };
	char company_name[COMPANY_NAME_MAX]{ 0, };
	char name[NAME_MAX]{ 0, };
	char email[EMAIL_MAX]{ 0, };
	char unversity[UNIVERSITY_MAX]{ 0, };
	char major[MAJOR_MAX]{ 0, };
} Student;

void CSV_Input(Student* list);
void except(char* start, char* destination);
void search_leader(Student* list);
void search_company(Student* list);
void search_name(Student* list);
void search_university(Student* list);

#endif