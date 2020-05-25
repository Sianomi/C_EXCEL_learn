#include "jin.h"

void search(StudentData* list)
{
	int searchnum;
	int company;
	char name[10] = { 0, };
	char school[10] = { 0, };

	while (1)
	{
		printf("\n");
		printf("검색 기준을 선택하시오(1: 조장, 2: 배정기업, 3: 이름, 4: 학교, 0: 종료) :  ");
		scanf_s("%d", &searchnum);
		printf("\n");

		if (searchnum == 1)
		{
			for (int i = 0; i < 30; i++)
			{
				if (strcmp("조장", list[i].leader) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s \n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
					//printf("\n");
				}
			}
			
		}
		else if (searchnum == 2)
		{
			printf("배정기업을 선택하세요(1: 브이아이텍, 2: 몽키소프트, 3: 메가존클라우드, 4: 너드바나, 5: 나비랩, 6: 5Works) : ");
			scanf("%d", &company);
			printf("\n");
			for (int i = 0; i < 30; i++)
			{
				if (company == 1 && strcmp("브이아이텍", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
				else if (company == 2 && strcmp("몽키소프트", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
				else if (company == 3 && strcmp("메가존클라우드", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
				else if (company == 4 && strcmp("너드바나", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
				else if (company == 5 && strcmp("나비랩", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
				else if (company == 6 && strcmp("5Works", list[i].company) == 0)
				{
					printf("\n");
					printf("%10s %15s %10s %25s %15s %20s %15s\n", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
			}
		}
		else if (searchnum == 3)
		{
			printf("찾고자 하는 학생의 이름을 입력하시오 : ");
			scanf("%s", &name);
			printf("\n");
			for (int i = 0; i < 30; i++)
			{
				if (strcmp(list[i].name, name) == 0)
				{
					printf("%s %s %s %s %s %s %s\n ", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
			}
		}
		else if (searchnum == 4)
		{
			printf("찾고자 하는 대학교의 이름을 입력하시오 : ");
			scanf("%s", &school);
			printf("\n");
			for (int i = 0; i < 30; i++)
			{
				if (strcmp(list[i].school, school) == 0)
				{
					printf("%s %s %s %s %s %s %s\n ", list[i].leader, list[i].company, list[i].name, list[i].email, list[i].school, list[i].major);
				}
			}
		}
		else if (searchnum == 0)
		{
			break;
		}
	}

}