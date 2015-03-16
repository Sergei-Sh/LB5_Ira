#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>

int main()
{
	int size, sorted_size, *array[2], i, j, sorting;
	int err_detect = 0;
	printf("Enter size of array: ");
	scanf("%d", &size);
	if ((array[0] = (int *)malloc(size * sizeof(int))) == NULL)
		err_detect = 1;
	if ((array[1] = (int *)malloc(size * sizeof(int))) == NULL)
		err_detect = 1;
	if (err_detect == 1)
	{
		printf("%s", "Erroe\n");
		return 0;
	}

	for (i = 0; i < size; i++)
	{
		printf("Element %d = ", i+1);
		scanf("%d", &array[0][i]);
	}

	sorted_size = 1;
	array[1][0] = array[0][0];
	for (i = 0; i < size; i++)
	{
		sorting = 0;
		for (j = 0; j < sorted_size; j++)
		{		
			if (array[0][i] == array[1][j])
				sorting++;
		}
		if (sorting == 0)
		{
			array[1][sorted_size] = array[0][i];
			sorted_size++;
		}
	}

	for (i = 0; i < sorted_size; i++)
	{
		printf("%d ", array[1][i]);
	}

	system("pause");
	return 0;
}
