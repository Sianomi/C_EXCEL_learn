#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS
#define LIST_MAX 30
#define COMPANY_NAME_MAX 20
#define NAME_MAX 10
#define EMAIL_MAX 30
#define UNIVERSITY_MAX 50
#define MAJOR_MAX 80
#define LEADER_MAX 10
#define MASTER_PATH "C:\\result\\result.txt"
#define OUTPUT_FORM "%-20s%-10s%-30s%-40s%-80s\n"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {  // 학생들의 정보를 저장하기 위한 구조체.
	char leader[LEADER_MAX]{ 0, };
	char company_name[COMPANY_NAME_MAX]{ 0, };
	char name[NAME_MAX]{ 0, };
	char email[EMAIL_MAX]{ 0, };
	char unversity[UNIVERSITY_MAX]{ 0, };
	char major[MAJOR_MAX]{ 0, };
} Student;

// 함수들은 기본적으로 학생들의 정보를 처리하는 함수이기 때문에 구조체 배열을 매개변수로 이용합니다. 리턴은 없습니다.
void read_file(Student* list);	             // CSV파일을 파싱하기 위한 함수입니다.
void Eliminate(char* str, char ch);			 // 파싱과정에서 문자열에 잘못된 문자가 포함된 경우 제거합니다.
void search_leader(Student* list);           // 이름을 입력받아 팀장인지 아닌지 판단하고 팀장이라면 팀에 관련된 모든 정보를 출력. 아니라면 팀장이 아니라고 알려주고 종료합니다.
void search_company(Student* list);          // 회사명을 입력받아 존재하는지 아닌지 확인하고 존재한다면 해당 팀에 관련된 모든 정보를 출력. 아니라면 회사가 존재하지 않는다고 알려주고 종료합니다.
void search_name(Student* list);             // 이름을 입력받아 해당 학생이 존재하는지 조회하고 존재한다면 출력. 아니라면 해당 학생이 존재하지 않는다고 알려주고 종료합니다.
void search_university(Student* list);       // 대학명을 입력받아 해당 대학이 존재하는지 확인하고 존재한다면 동일한 대학을 다닌 모든 학생을 출력. 존재하지 않는다면 해당 대학이 존재하지 않는다고 알려주고 종료합니다.



#endif