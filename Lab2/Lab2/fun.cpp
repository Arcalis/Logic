#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

int fun1(int size) 
{

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int i = 0, j = 0, r;
	int elem_c;

	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}
	int** b = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		b[i] = (int*)malloc(size * sizeof(int));
	}
	int** c = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		c[i] = (int*)malloc(size * sizeof(int));
	}

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < size)
	{
		while (j < size)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			elem_c = 0;
			for (r = 0; r < size; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	return 0;
}

int fun2(int size)
{
	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	int i=0, j=0;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	shell(*a, size);
	clock_t end = clock();
	qs(*a, 0,size-1);
	return end;
}

int fun3(int size)
{
	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	int i = 0, j = 0;
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = i+j+1;
			j++;
		}
		i++;
	}

	shell(*a, size);
	clock_t end = clock();
	qs(*a, 0, size - 1);
	return end;
}

int fun4(int size)
{
	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	int i = 0, j = 0;
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = size - j-i-1;
			j++;
		}
		i++;
	}

	shell(*a, size);
	clock_t end = clock();
	qs(*a, 0, size - 1);
	return end;
}

int fun5(int size)
{
	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	for(int i = 0; i < size/2;i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			a[i][j] = i + j + 1;  
		}
	}
	for (int i = size/2; i < size-1; i++)
	{
		for (int j = size/2; j < size-1; j++)
		{
			a[i][j] = a[i-1][j-1] - 1;
		}
	}

	shell(*a, size);
	clock_t end = clock();
	qs(*a, 0, size - 1);
	return end;
}

int fun6(int size)
{
	int** a = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}

	int i = 0, j = 0;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < size)
	{
		while (j < size)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	shell(*a, size);
	clock_t end = clock();
	qs(*a, 0, size - 1);
	return end;
}

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}