#include "header.h"


void CSV_Input(Student* list)
{
	FILE* fp;
	int i{ 0 };
	char buffer[50000]{ 0, };
	char* ptr = NULL;

	fp = fopen("C:\\result\\서울반 교육생 명단_한국표준협회.csv", "r");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);
	}
	fgets(buffer, sizeof(buffer), fp);

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		ptr = strtok(buffer, ",");
		if (strcmp("조장", ptr) == 0)
		{
			list[i].leader_flag = 1;
			ptr = strtok(NULL, ",");
			strcpy(list[i].company_name, ptr);
		}
		else
			strcpy(list[i].company_name, ptr);
		ptr = strtok(NULL, ",");
		strcpy(list[i].name, ptr);
		ptr = strtok(NULL, ",");
		strcpy(list[i].email, ptr);
		ptr = strtok(NULL, ",");
		if (ptr[0] == '"')
			except(ptr, list[i].unversity);
		else
			strcpy(list[i].unversity, ptr);
		ptr = strtok(NULL, ",");
		strcpy(list[i].major, ptr);
	
		i++;
	}
	fclose(fp);
}

void search_leader(Student* list)
{
	int i;
	char search_name[10]{ 0, }, searched_company_name[COMPANY_NAME_MAX]{ 0, }, timestr[30]{ 0, };
	time_t t;
	FILE* fp;

	fp = fopen(MASTER_PATH, "a");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);
	}

	printf("이름을 입력해주세요 : ");
	scanf("%s", search_name);
	printf("\n");

	for (i = 0; i < LIST_MAX; i++)
	{
		if (strcmp(list[i].name, search_name) == 0)
		{
			if (list[i].leader_flag == 1)
			{
				strcpy(searched_company_name, list[i].company_name);
				break;
			}
		}
	}

	if (strlen(searched_company_name) == 0)
	{
		printf("조장이 아닙니다.\n");
		return;
	}

	for (; i < LIST_MAX; i++)
	{
		if (strcmp(searched_company_name, list[i].company_name) != 0)
			break;

		t = time(NULL);
		strcpy(timestr, ctime(&t));
		timestr[strlen(timestr) - 1] = '\0';
		fprintf(fp, timestr);

		if (list[i].leader_flag == 1) 
		{ 
			printf("  조장  ");
			fprintf(fp, "  조장  ");
		}
		else
		{
			printf("  조원  ");
			fprintf(fp, "  조원  ");
		}

		printf(OUTPUT_FORM,
			list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
		fprintf(fp,OUTPUT_FORM,
			list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
	}
	fclose(fp);
	printf("\n");
}

void search_company(Student* list)
{
	int i{ 0 };
	char search_company_name[COMPANY_NAME_MAX]{ 0, }, timestr[30]{ 0, };
	time_t t;
	FILE* fp;

	fp = fopen(MASTER_PATH, "a");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);
	}


	printf("\n찾고자 하는 기업명을 입력해주세요. : ");
	scanf("%s", search_company_name);
	printf("\n");

	for (i = 0; i < LIST_MAX; i++)
		if (strcmp(list[i].company_name, search_company_name) == 0)
			break;

	if (i >= LIST_MAX)
	{
		printf("해당 기업명이 존재하지 않습니다.\n");
		return;
	}

	for (; i < LIST_MAX; i++)
	{
		if (strcmp(search_company_name, list[i].company_name) != 0)
			break;

		t = time(NULL);
		strcpy(timestr, ctime(&t));
		timestr[strlen(timestr) - 1] = '\0';
		fprintf(fp, timestr);

		if (list[i].leader_flag == 1)
		{
			printf("  조장  ");
			fprintf(fp, "  조장  ");
		}
		else
		{
			printf("  조원  ");
			fprintf(fp,"  조원  ");
		}
		printf(OUTPUT_FORM,
			list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
		fprintf(fp, OUTPUT_FORM,
			list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
	}

	fclose(fp);
}

void search_name(Student* list)
{
	int i{ 0 };
	char search_name[NAME_MAX]{ 0, }, timestr[30]{ 0, };
	time_t t;
	FILE* fp;

	fp = fopen(MASTER_PATH, "a");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);
	}

	printf("\n찾고자 하는 이름을 입력해주세요. : ");
	scanf("%s", search_name);
	printf("\n");

	for (i = 0; i < LIST_MAX; i++)
	{
		if (strcmp(list[i].name, search_name) == 0)
			break;
	}

	if (i >= LIST_MAX)
	{
		printf("해당 이름이 존재하지 않습니다.\n");
		return;
	}

	t = time(NULL);
	strcpy(timestr, ctime(&t));
	timestr[strlen(timestr) - 1] = '\0';
	fprintf(fp, timestr);

	if (list[i].leader_flag == 1)
	{
		printf("  조장  ");
		fprintf(fp,"  조장  ");
	}
	else
	{
		printf("  조원  ");
		fprintf(fp,"  조원  ");
	}
	printf(OUTPUT_FORM,
		list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
	fprintf(fp,OUTPUT_FORM,
		list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);

	fclose(fp);
}

void search_university(Student* list)
{
	bool flag{ false };
	char search_university[UNIVERSITY_MAX]{ 0, }, timestr[30]{ 0, };
	time_t t;
	FILE* fp;

	fp = fopen(MASTER_PATH, "a");
	if (fp == NULL)
	{
		printf("파일 오픈 실패\n");
		exit(1);
	}

	printf("\n찾고자 하는 대학명을 입력해주세요. : ");
	scanf("%s", search_university);
	printf("\n");

	for (int i = 0; i < LIST_MAX; i++)
	{
		if (strcmp(list[i].unversity, search_university) == 0)
		{
			flag = true;

			t = time(NULL);
			strcpy(timestr, ctime(&t));
			timestr[strlen(timestr) - 1] = '\0';
			fprintf(fp, timestr);

			if (list[i].leader_flag == 1)
			{
				printf("  조장  ");
				fprintf(fp,"  조장  ");
			}
			else
			{
				printf("  조원  ");
				fprintf(fp,"  조원  ");
			}
			printf(OUTPUT_FORM,
				list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
			fprintf(fp,OUTPUT_FORM,
				list[i].company_name, list[i].name, list[i].email, list[i].unversity, list[i].major);
		}
	}

	fclose(fp);

	if (flag == false)
		printf("해당 대학명이 존재하지 않습니다.\n");
}

void except(char* start, char* destination)
{
	while (true)
	{
		strcat(destination, start);
		destination[strlen(destination)] = ',';
		start = strtok(NULL, ",");
		if (start[strlen(start) - 1] == '"')
		{
			strcat(destination, start);
			break;
		}
	}
}