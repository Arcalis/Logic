#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_PER_SEC 1000

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end; // ��������� ���������� ��� ����������� ������� ����������

	start = clock();

	double timeOfProgram;
	int i = 0, j = 0, r;
	int a[200][200], b[200][200], c[200][200], elem_c;

	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	while (i < 200)
	{
		while (j < 200)
		{
			a[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}
	srand(time(NULL)); // �������������� ��������� ���������� ��������� �����
	i = 0; j = 0;
	while (i < 200)
	{
		while (j < 200)
		{
			b[i][j] = rand() % 100 + 1; // ��������� ������ ���������� �������
			j++;
		}
		i++;
	}

	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 200; j++)
		{
			elem_c = 0;
			for (r = 0; r < 200; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();
	timeOfProgram = (double)(end - start) / TIME_PER_SEC;

	printf("working hours of the program = %fs", timeOfProgram);
	return(0);
}
