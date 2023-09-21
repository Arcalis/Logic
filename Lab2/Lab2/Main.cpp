#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int main(void)
{
	clock_t start, end, end2; // объявляем переменные для определения времени выполнения

	double timeOfProgram, timeOfProgram2;

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
	end = fun2(50000);
	end2 = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	timeOfProgram2 = (double)(end2 - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d:\nsort of Shell = %fs\nquick sort = %fs", 50000, 50000, timeOfProgram, timeOfProgram2);

	printf("\n\nExercise3\n"); //Задание 2.2
	start = clock();
	end = fun3(50000);
	end2 = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	timeOfProgram2 = (double)(end2 - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d:\nsort of Shell = %fs\nquick sort = %fs", 50000, 50000, timeOfProgram, timeOfProgram2);

	printf("\n\nExercise4\n"); //Задание 2.3
	start = clock();
	end = fun4(50000);
	end2 = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	timeOfProgram2 = (double)(end2 - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d:\nsort of Shell = %fs\nquick sort = %fs", 50000, 50000, timeOfProgram, timeOfProgram2);

	printf("\n\nExercise5\n"); //Задание 2.4
	start = clock();
	end = fun5(50000);
	end2 = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	timeOfProgram2 = (double)(end2 - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d:\nsort of Shell = %fs\nquick sort = %fs", 50000, 50000, timeOfProgram, timeOfProgram2);


	return 0;
}
