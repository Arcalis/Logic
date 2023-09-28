#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int main(void)
{
	clock_t start, end; // объявляем переменные для определения времени выполнения
	
	int** a = (int**)malloc(25000 * sizeof(int*));
	for (int i = 0; i < 25000; i++)
	{
		a[i] = (int*)malloc(25000 * sizeof(int));
	}

	double timeOfProgram;

	/*start = clock();
	fun1(100);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n",100, 100, timeOfProgram);
	start = clock();
	fun1(200);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 200, 200, timeOfProgram);
	start = clock();
	fun1(400);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 400, 400, timeOfProgram);
	start = clock();
	fun1(1000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 1000, 1000, timeOfProgram);
	start = clock();
	fun1(2000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 2000, 2000, timeOfProgram);
	start = clock();
	fun1(4000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 4000, 4000, timeOfProgram);
	start = clock();
	fun1(10000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 10000, 10000, timeOfProgram);*/

	
	printf("\n\nExercise2\n"); //Задание 2.1

	start = clock();
	**a = fun2(25000);
	qsort(*a, 25000, sizeof(int), compare);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Working hours of the program with array %dx%d:\nquick sort = %fs", 25000, 25000, timeOfProgram);

	start = clock();
	**a = fun2(25000);
	shell(*a, 25000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSort of Shell = %fs", timeOfProgram);

	start = clock();
	**a = fun2(25000);
	qs(*a, 0, 25000 - 1);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nStandart quick sort = %fs", timeOfProgram);

	
	printf("\n\nExercise3\n"); //Задание 2.2
	
	start = clock();
	**a = fun3(25000);
	qsort(*a, 25000, sizeof(int), compare);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Working hours of the program with array %dx%d:\nquick sort = %fs", 25000, 25000, timeOfProgram);

	start = clock();
	**a = fun3(25000);
	shell(*a, 25000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSort of Shell = %fs", timeOfProgram);

	start = clock();
	**a = fun3(25000);
	qs(*a, 0, 25000 - 1);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nStandart quick sort = %fs", timeOfProgram);


	printf("\n\nExercise4\n"); //Задание 2.3

	start = clock();
	**a = fun4(25000);
	qsort(*a, 25000, sizeof(int), compare);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Working hours of the program with array %dx%d:\nquick sort = %fs", 25000, 25000, timeOfProgram);

	start = clock();
	**a = fun4(25000);
	shell(*a, 25000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSort of Shell = %fs", timeOfProgram);

	start = clock();
	**a = fun4(25000);
	qs(*a, 0, 25000 - 1);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nStandart quick sort = %fs", timeOfProgram);

	printf("\n\nExercise5\n"); //Задание 2.4
	start = clock();
	**a = fun5(25000);
	qsort(*a, 25000, sizeof(int), compare);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Working hours of the program with array %dx%d:\nquick sort = %fs", 25000, 25000, timeOfProgram);

	start = clock();
	**a = fun5(25000);
	shell(*a, 25000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nSort of Shell = %fs", timeOfProgram);

	start = clock();
	**a = fun5(25000);
	qs(*a, 0, 25000 - 1);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nStandart quick sort = %fs", timeOfProgram);

	return 0;
}
