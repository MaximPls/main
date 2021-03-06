#include "pch.h"

#include <limits.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <memory.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

int printMenu();
int correctInput();
int** setArray(int** &arr, int &rank);
void processingArray(int** &arr, int rank, int &rowMax, int &colMax, int &rowMin, int &colMin);
void outputArray(int** &arr, int rank, int rowMax, int colMax, int rowMin, int colMin);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	int** arr = nullptr;
	int menu = 0, rank = 0, rowMax = 0, colMax = 0, rowMin = 0, colMin = 0;

	do
	{
		menu = printMenu();
		switch (menu)
		{
		case 1:
		{
			arr = setArray(arr, rank);
		}
		break;
		case 2:
		{
			processingArray(arr, rank, rowMax, colMax, rowMin, colMin);
		}
		break;
		case 3:
		{
			outputArray(arr, rank, rowMax, colMax, rowMin, colMin);
		}
		break;
		default:
		{
			if (menu != 0)
			{
				printf("Такого пункта нет!");
			}
		}
		break;
		}
	} while (menu != 0);

	for (int i = 0; i < rank; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}
int printMenu()
{
	printf("\n\n");
	printf(" ################################\n");
	printf(" # 1- Ввод данных               #\n");
	printf(" # 2- Обработка данных          #\n");
	printf(" # 3- Вывод результата на экран #\n");
	printf(" # 0- Выход                     #\n");
	printf(" ################################\n");
	printf(" >> ");
	int point = correctInput();
	return point;
}
int correctInput()
{
	
}
int** setArray(int** &arr, int &rank)
{
	int menu = 0;

	if (arr != nullptr)
	{
		for (int i = 0; i < rank; i++)
		{
			delete[] arr[i];
		}

		delete[] arr;
	}
	do
	{
		printf("Введите ранг матрицы \n >> ");
		rank = correctInput();
	} while (rank < 2 || rank > 20);

	arr = new int*[rank];

	for (int i = 0; i < rank; i++)
	{
		arr[i] = new int[rank]();
	}

	printf("Матрица %dX%d \n", rank, rank);

	do
	{
		printf("  1- Заполнить массив вручную           \n");
		printf("  2- Заполнить массив случайными числами\n >> ");
		menu = correctInput();
	} while (menu < 1 || menu > 2);

	switch (menu)
	{

	case 1:

		for (int i = 0; i < rank; i++)
		{
			for (int j = 0; j < rank; j++)
			{
				do
				{
					printf("Введите (%d; %d) элемент\n >>", i + 1, j + 1);
					arr[i][j] = correctInput();
				} while ((arr[i][j] < INT_MIN) or (arr[i][j] > INT_MAX));
			}
		}
		break;

	case 2:

		for (int i = 0; i < rank; i++)
		{
			for (int j = 0; j < rank; j++)
			{
				arr[i][j] = (rand() % 1001) - (rand() % 401);
			}
		}
		break;
	}

	for (int i = 0; i < rank; i++)
	{
		printf("\n");
		for (int j = 0; j < rank; j++)
		{
			printf(" [%4.1d] ", arr[i][j]);
		}
	}

	return arr;
}
void processingArray(int** &arr, int rank, int &rowMax, int &colMax, int &rowMin, int &colMin)
{
	int max = arr[0][0], min = arr[0][0];

	for (int i = 0; i < rank; i++)
	{
		for (int j = 0; j < rank; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				rowMax = i;
				colMax = j;
			}

			if (arr[i][j] < min)
			{
				min = arr[i][j];
				rowMin = i;
				colMin = j;
			}
		}
	}

	arr[rowMax][colMax] = 0;
	arr[rowMin][colMin] = 0;
}
void outputArray(int** &arr, int rank, int rowMax, int colMax, int rowMin, int colMin)
{
	for (int i = 0; i < rank; i++)
	{
		printf("\n");
		for (int j = 0; j < rank; j++)
		{
			printf(" [%4.1d] ", arr[i][j]);
		}
	}
	printf("\n---------------------------------------\n");
	printf("Максимальный элемент [%d][%d] занулен.\n", rowMax+1, colMax+1);
	printf("Минимальный элемент [%d][%d] занулен.\n", rowMin+1, colMin+1);
}
