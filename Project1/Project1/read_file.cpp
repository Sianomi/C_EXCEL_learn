#include "header.h"

void read_file(Student * list)
{
	char* buffer1;
	char buffer2[10] = { 0, };
	int size;
	int i = 0;
	char* ptr;

	FILE* fp = fopen("C:\\result\\����� ������ ���_�ѱ�ǥ����ȸ.csv", "r"); //�ش� ���� �б� ���� ����, ���� �����͸� ��ȯ
	if (fp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return;
	}

	fseek(fp, 0, SEEK_END);        //���� �����͸� ������ ������ �̵�
	size = ftell(fp);              //���� �������� ���� ��ġ�� ����

	buffer1 = (char*)malloc(size + 1);    //����ũ��+1 ����Ʈ(���ڿ� �������� NULL)��ŭ ���� �޸� �Ҵ�
	memset(buffer1, 0, size + 1);  //����ũ��+1 ����Ʈ��ŭ �޸𸮸� 0���� �ʱ�ȭ

	fseek(fp, 0, SEEK_SET);        //���� �����͸� ������ ó������ �̵� rewind(fp)
	fread(buffer1, size, 1, fp);   //���� ũ�⸸ŭ ���� ����
	
	Eliminate(buffer1, '?' );      //Ư������ ����
	
	//printf("%s\n", buffer1);     //����

	while (1)  //���� ����
	{
		if (i == 0)
		{
			ptr = strtok(buffer1, "\n,");
		}
		else
		{
			ptr = strtok(NULL, "\n,");
			if (ptr == NULL) break;
		}

		if (i == 0 || strcmp("����", ptr) == 0)
		{
			strcpy(list[i].leader, ptr);
			ptr = strtok(NULL, "\n,");
			strcpy(list[i].company_name, ptr);
		}
		else
		{
			strcpy(list[i].leader, "����");
			strcpy(list[i].company_name, ptr);
		}

		ptr = strtok(NULL, "\n,");
		strcpy(list[i].name, ptr);
		ptr = strtok(NULL, "\n,");
		strcpy(list[i].email, ptr);
		ptr = strtok(NULL, "\n,");

		
		if (ptr[0] == '"')
		{
			ptr = strcat(ptr,strtok(NULL, ","));
			strcpy(list[i].unversity, ptr);
		}
		else
		{
			strcpy(list[i].unversity, ptr);
		}
		
		ptr = strtok(NULL, "\n,");
		strcpy(list[i].major, ptr);

		i++;
	}

	fclose(fp);    //���� ������ �ݱ�

	free(buffer1);  //���� �޸� ����

}

void Eliminate(char* str, char ch)
{
	for (; *str != 0; str++)
	{
		if (*str == ch)
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}