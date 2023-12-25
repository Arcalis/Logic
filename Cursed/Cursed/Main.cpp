#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int colours(int** matrix, int count)
{
	int** sortVertecs = (int**)calloc(count, sizeof(int*));
	for (int i = 0; i < 2; i++)
	{
		sortVertecs[i] = (int*)calloc(count, sizeof(int));
	}

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			sortVertecs[0][j] = j;
			sortVertecs[1][j] += matrix[i][j];
		}
	}

	int tmp, tmpInd, k;
	int n = count;
	while (n > 1) {
		k = 0;
		for (int i = 1; i < n; ++i) {
			if (sortVertecs[1][i] > sortVertecs[1][i - 1]) {
				tmp = sortVertecs[1][i - 1];
				sortVertecs[1][i - 1] = sortVertecs[1][i];
				sortVertecs[1][i] = tmp;

				tmpInd = sortVertecs[0][i - 1];
				sortVertecs[0][i - 1] = sortVertecs[0][i];
				sortVertecs[0][i] = tmpInd;
				k = i;
			}
		}
		n = k;
	}

	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < count; j++)
		{
				printf(" %d", sortVertecs[i][j]);
		}
		printf("\n");
	}*/

	int* coloursOfVertecs = (int*)calloc(count, sizeof(int*));
	int colour = 1;

	coloursOfVertecs[sortVertecs[1][0]] = colour;
	int coloured = count - 1;

	while (coloured > 0)
	{
		int u = 2;
		for(int i = 0; )
	}

	return NULL;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int size;
	printf("¬ведите размер матрицы: ");
	scanf("%d", &size);
	printf("\n");

	int** matrix = (int**)calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)calloc(size, sizeof(int));
	}

	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int random = rand() % 2;
			matrix[i][j] = random;
			matrix[j][i] = random; 
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf(" %d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	colours(matrix, size);
}