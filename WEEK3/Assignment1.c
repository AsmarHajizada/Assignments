#include <stdio.h>
#include <string.h>

void swapArrays(int a1[], int a2[], int len);           
void print2DArr(int *arr2D[], int rows, int columns);

int main()
{
	int a1[] = {1,2,3,4,5};
	int a2[] = {0,0,0,0,0};
	int len = sizeof(a1)/sizeof(int);
	int *arr2D[2] = {a1,a2};          
                                      
     printf("Array1 and Array2 before swapping:\n");
	print2DArr(arr2D, 2, len);
	swapArrays(a1, a2, len);
	printf("Array1 and Array2 after swapping:\n");
	print2DArr(arr2D, 2, len);
	return 0;
}

void swapArrays(int a1[], int a2[], int len) //swaps contents of arrays
{
	int i, temp;
	for (i = 0; i < len; ++i)
	{
		temp = a1[i];
		a1[i] = a2[i];
		a2[i] = temp;
	}
}

void print2DArr(int *arr2D[], int rows, int columns) //prints 2D array contents
{
	int a, b;
	for (a = 0; a < rows; ++a)
	{
		for (b = 0; b < columns; ++b)
		{
			if (a == rows - 1 && b == columns - 1) //making sure no empty ' ' is printed after last element
				printf("%d", arr2D[a][b]);
			else
				printf("%d ", arr2D[a][b]);
		}
	}
	printf("\n");
}  

