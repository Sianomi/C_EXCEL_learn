#ifndef _JIN_H_
#define _JIN_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentData
{
	char leader[30];
	char company[30];
	char name[30];
	char email[30];
	char school[30];
	char major[30];

}StudentData;

void read_file(StudentData *list);

#endif
