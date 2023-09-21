#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int main(void)
{
	clock_t start, end; // объ€вл€ем переменные дл€ определени€ времени выполнени€

	double timeOfProgram;

	start = clock();
	fun(100);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 100, 100, timeOfProgram);
	start = clock();
	fun(200);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 200, 200, timeOfProgram);
	start = clock();
	fun(400);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 400, 400, timeOfProgram);
	start = clock();
	fun(1000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 1000, 1000, timeOfProgram);
	start = clock();
	fun(2000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 2000, 2000, timeOfProgram);
	start = clock();
	fun(4000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 4000, 4000, timeOfProgram);
	start = clock();
	fun(10000);
	end = clock();
	timeOfProgram = (double)(end - start) / CLOCKS_PER_SEC;
	printf("working hours of the program with array %dx%d = %fs\n", 10000, 10000, timeOfProgram);


	return 0;
}
