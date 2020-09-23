#include <stdio.h>

//Write a c program where you define a function that takes two integers,swaps them, prints the swapped 
//integers inside the function. You don't need to think in terms pointers, pointers will be taught in one to two weeks.
//Pass values by copy into the function.

int swapIntegers(int int1, int int2);

int main()
{
	int a, b;
	a = 20;
	b = 40;
	printf("Given integers: a = %d; b = %d\n", a, b);
	swapIntegers(a, b);

	return 0;
}

int swapIntegers(int int1, int int2){

	int temp;

	temp = int1;
	int1 = int2;
	int2 = temp;

	printf("Swapped integer values: a = %d; b = %d\n", int1, int2);
	
	return 0;	
}
