#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void excercise1();
void excercise2();
void excercise3();
void excercise4();
void excercise5();

int main()
{
	excercise1();
	excercise2();
	excercise3();
	excercise4();
	excercise5();
}

void excercise1()
{
	int Arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int max = -1000;
	int min = 1000;
	int razn = 0;

	for (int i = 0; i < 10; i++)
	{
		if (min > Arr[i])
		{
			min = Arr[i];
		}
		if (max < Arr[i])
		{
			max = Arr[i];
		}
	}

	printf("excercise1-%d\n\n", max - min);
}

void excercise2()
{
	srand(time(NULL));
	int Arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		Arr[i] = rand() % 100;
	}
	printf("excercise2-");
	printf("Arr:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("[%d]", Arr[i]);
	}

}

void excercise3()
{
	int* Arr;
	int n;
	printf_s("\n\nexcercise3 - \nEnter the size of array:");
	scanf_s("%d", &n);
	Arr = (int*)malloc(n * 4);

	for (int i = 0; i < n; i++)
	{
		Arr[i] = i;
		printf_s("[%d]", Arr[i]);
	}
}

void excercise4()
{
	int result = 0;
	int Arr[3][3];
	printf("\n\nexcercise4-\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Arr[i][j] = i + j;
			result += Arr[i][j];
			printf("[%d]", Arr[i][j]);
		}
		printf(" result(%d) = %d", i, result);
		printf("\n");
		result = 0;
	}
	printf("\n");
}

void excercise5()
{
	typedef struct student
	{
		char Name[20];
		char SecondName[20];
		char Facult[20];
		char Group[20];
	}Student;

	Student student[5];
	student[0] = {"Alexsandr","Genadyevich", "FVT", "22VVP1"};
	student[1] = {"Georgiy","Ivanovich", "FITE", "20VE3"};
	student[2] = {"Dmitriy","Pushkin", "FVT", "22VV1"};
	student[3] = {"Maria","Avdeeva", "FITE", "19CC2"};
	student[4] = {"Evgeniy","Leontyev", "FVT", "23VV3"};

	char name[20];
	char secondName[20];

	printf("Excersise5:\nEnter name and second name of student:\n");
	getchar();
	gets_s(name);

	for (int i = 0; i < 5; i++)
	{
		if (((strcmp(student[i].Name, name))==0))
		{
			printf("Student %s %s from facult %s and from group %s", student[i].Name, student[i].SecondName, student[i].Facult, student[i].Group);
		}
	}
}