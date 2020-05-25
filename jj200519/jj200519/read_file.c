#include "jin.h"

void read_file(StudentData *list)
{
	char* buffer1;
	int size;
	int i = 0;
	char* ptr;

	FILE* fp = fopen("C:\\result\\서울반 교육생 명단_한국표준협회.csv", "r"); //해당 파일 읽기 모드로 열기, 파일 포인터를 반환
	if (fp == NULL)
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	fseek(fp, 0, SEEK_END); //파일 포인터를 파일의 끝으로 이동
	size = ftell(fp);       //파일 포인터의 현재 위치를 얻음

	buffer1 = malloc(size + 1);    //파일크기+1 바이트(문자열 마지막의 NULL)만큼 동적 메모리 할당
	memset(buffer1, 0, size + 1);  //파일크기+1 바이트만큼 메모리를 0으로 초기화

	fseek(fp, 0, SEEK_SET);      //파일 포인터를 파일의 처음으로 이동 rewind(fp)
	fread(buffer1, size, 1, fp);  //파일 크기만큼 값을 읽음

	//printf("%s\n", buffer1); //내용, 파일크기, 읽은 횟수
	
	while (1)  //내용 분할
	{
		if (i == 0)
		{
			ptr = strtok(buffer1, ",");
		}
		else
		{
			ptr = strtok(NULL, ",");
			if (ptr == NULL) break;
		}

		if (i == 0 || strcmp("조장", ptr) == 0)
		{
			strcpy(list[i].leader, ptr);
			ptr = strtok(NULL, ",");
			strcpy(list[i].company, ptr);
		}
		else
		{
			strcpy(list[i].leader, "조원");
			strcpy(list[i].company, ptr);
		}

		ptr = strtok(NULL, ",");
		strcpy(list[i].name, ptr);
		ptr = strtok(NULL, ",");
		strcpy(list[i].email, ptr);
		ptr = strtok(NULL, ",");
		strcpy(list[i].school, ptr);
		ptr = strtok(NULL, "\n");
		strcpy(list[i].major, ptr);

		i++;
	}

	fclose(fp);    //파일 포인터 닫기

	free(buffer1);  //동적 메모리 해제

}