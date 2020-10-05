#include <stdio.h>

void swapStrings(char **destination, char **source);           

int main()
{
	char *str1 = "HP Omen 15";
	char *str2 = "Lenovo Legion";
	
	printf("Before swapping:\n");
	printf("str1: %s, str2: %s\n",str1,str2);
	swapStrings(&str1, &str2);
	printf("After swapping:\n");
	printf("str1: %s, str2: %s\n",str1,str2);

	return 0;
}


void swapStrings(char **destination, char **source)
{
	/*using character pointers because it makes it possible
	to swap strings with different lengths*/ 	
	char *temp = *destination;
	*destination = *source;
	*source = temp;
}
