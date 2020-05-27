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

typedef struct student {  // �л����� ������ �����ϱ� ���� ����ü.
	char leader[LEADER_MAX]{ 0, };
	char company_name[COMPANY_NAME_MAX]{ 0, };
	char name[NAME_MAX]{ 0, };
	char email[EMAIL_MAX]{ 0, };
	char unversity[UNIVERSITY_MAX]{ 0, };
	char major[MAJOR_MAX]{ 0, };
} Student;

// �Լ����� �⺻������ �л����� ������ ó���ϴ� �Լ��̱� ������ ����ü �迭�� �Ű������� �̿��մϴ�. ������ �����ϴ�.
void read_file(Student* list);	             // CSV������ �Ľ��ϱ� ���� �Լ��Դϴ�.
void Eliminate(char* str, char ch);			 // �Ľ̰������� ���ڿ��� �߸��� ���ڰ� ���Ե� ��� �����մϴ�.
void search_leader(Student* list);           // �̸��� �Է¹޾� �������� �ƴ��� �Ǵ��ϰ� �����̶�� ���� ���õ� ��� ������ ���. �ƴ϶�� ������ �ƴ϶�� �˷��ְ� �����մϴ�.
void search_company(Student* list);          // ȸ����� �Է¹޾� �����ϴ��� �ƴ��� Ȯ���ϰ� �����Ѵٸ� �ش� ���� ���õ� ��� ������ ���. �ƴ϶�� ȸ�簡 �������� �ʴ´ٰ� �˷��ְ� �����մϴ�.
void search_name(Student* list);             // �̸��� �Է¹޾� �ش� �л��� �����ϴ��� ��ȸ�ϰ� �����Ѵٸ� ���. �ƴ϶�� �ش� �л��� �������� �ʴ´ٰ� �˷��ְ� �����մϴ�.
void search_university(Student* list);       // ���и��� �Է¹޾� �ش� ������ �����ϴ��� Ȯ���ϰ� �����Ѵٸ� ������ ������ �ٴ� ��� �л��� ���. �������� �ʴ´ٸ� �ش� ������ �������� �ʴ´ٰ� �˷��ְ� �����մϴ�.



#endif