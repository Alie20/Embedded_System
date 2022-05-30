/*
 * main.c
 *
 *  Created on: May 30, 2022
 *      Author: alie
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
	int rollNumber;
    char    name[100];
    char    branch[50];
    int dob;
    int semister;

}STUDENTS_T;

int STUDENTS_NO = 10;
STUDENTS_T students[10];

int add_student(STUDENTS_T * record,int STUDENTS_NO);
void display_students(STUDENTS_T * record,int STUDENTS_NO);
int delete_record(STUDENTS_T * record,int STUDENTS_NO);

int main ()
{
	while(1)
	{
		int check;
		printf("Press 1 to Add student \n");
		printf("Press 2 to Display students \n");
		printf("Press 3 to Display students \n");
		printf("Press 0 to Exit \n");


		scanf("%i",&check);
		if (check == 1)
		{
			int add = add_student(students,STUDENTS_NO);
			!add ? printf("Record add unsuccessful\n") : printf("Record added successfully\n");
		}
		else  if (check == 2)
		{
			display_students(students,STUDENTS_NO);

		}
		else if (check == 0)
		{
			printf("Have A good day\n");
			break;
		}
		else if (check == 3)
		{
			int del = delete_record(students,STUDENTS_NO);
			!del ? printf("Record add unsuccessful\n") : printf("Record added successfully\n");


		}

	}
		return 0;
}
int check(int roll_number,STUDENTS_T *record,int STUDENTS_NO)
{
	for (int i = 0 ; i < STUDENTS_NO;i++)
	{
		if (record[i].rollNumber == roll_number)
		{
			return 1;
		}
	}
	return 0;
}
int add_student(STUDENTS_T * record,int STUDENTS_NO)
{
	int roll_number;
	int add_status = 0;
	int is_exsist;
	int i ;
	for( i = 0 ; i < STUDENTS_NO ; i++)
	{
		if (!record[i].rollNumber)
		{
			printf("Enter the rollNumber : ");
			scanf("%d",&roll_number);
			is_exsist = check(roll_number,students,STUDENTS_NO);
			if (!is_exsist)
			{
				add_status = 1; //adding new record
				record[i].rollNumber = roll_number;
				printf("Enter the studentSemister   : ");
				scanf("%d",&record[i].semister);
				printf("Enter the studentDOB        : ");
				scanf("%d",&record[i].dob);
				getchar();
				printf("Enter the studentBranch     : ");
				scanf("%50[^\n]s",record[i].branch);
				getchar();
				printf("Enter the studentName       : ");
				scanf("%50[^\n]s",record[i].name);
			}
			else
			{
				printf("ROLL NUMBER IS EXSIST \n");
			}
			break;

		}

	}
	if (i == STUDENTS_NO)
	{
		printf("Sorry ! No space available\n");
	}
	return add_status;

}
void display_students(STUDENTS_T * record,int STUDENTS_NO)
{
	int RecordFound = 0;
	for (int i = 0 ; i<STUDENTS_NO;i++)
	{
		if (record[i].rollNumber)
		{
			RecordFound = 1;
			printf("***********\n");
			printf("rollNumber : %u\n",record[i].rollNumber);
			printf("studentSemister   : %u\n",record[i].semister);
			printf("studentDOB        : %u\n",record[i].dob);
			printf("studentBranch     : %s\n",record[i].branch);
			printf("studentName       : %s\n",record[i].name);
			printf("***********\n");

		}
	}
	if (!RecordFound)
	{
		printf("NO RECORD ADDED\n");
	}
}
int delete_record(STUDENTS_T * record,int STUDENTS_NO)
{
	int rollNumber ;
	int found = 0;
	printf("Enter the rollNumber\n");
	scanf("%i",&rollNumber);
	for (int i = 0 ; i < STUDENTS_NO ; i++)
	{
		if (record[i].rollNumber == rollNumber)
		{
			found = 1;
			memset(&record[i],0,sizeof(STUDENTS_T));
			break;
		}
	}
	if (!found)
	{
		printf("Not Found \n");
	}
	return found;

}



