#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

	printf("1-%d\n", max - min);
}

void excercise2()
{
	srand(time(NULL));
	int Arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		Arr[i] = rand() % 100;
	}

	printf("Arr: ");
	for (int i = 0; i < 10; i++)
	{
		printf("2-\n%d\n", Arr[i]);
	}

}

void excercise3()
{
	int* Arr;
	int n;
	scanf_s("Enter the size of array:%d", &n);
	Arr = (int*)malloc(n * 4);

	for (int i = 0; i < n; i++)
	{
		Arr[i] = i;
		printf_s("3-\n[%d]\n", Arr[i]);
	}
}

void excercise4()
{
	int result = 0;
	int Arr[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Arr[i][j] = i + j;
			result += Arr[i][j];
			printf("%d", Arr[i][j]);
		}
		printf("4-result(%d) = %d", i, result);
		result = 0;
		printf("/n");
	}
}

void excercise5()
{
	typedef struct student
	{
		char Name[20];
		char SecondName[20];
	}Student;

	Student student1, student2, student3;
	//student1.Name = "George";
	//student1.SecondName = "Chomic";
}