#include "header.h"

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
			if (strcmp(list[i].leader,"조장")==0)
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

		if (strcmp(list[i].leader, "조장") == 0)
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

		if (strcmp(list[i].leader, "조장") == 0)
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

	if (strcmp(list[i].leader, "조장") == 0)
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

			if (strcmp(list[i].leader, "조장") == 0)
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