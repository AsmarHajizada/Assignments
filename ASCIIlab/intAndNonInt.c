#include <stdio.h>
	
void function(char *source, char *integers, char *nonInteger)
{
	int a = 0, b = 0, i = 0;

	for ( ; source[i] != '\0'; i++)
	{
		if ((int)source[i] >= 48 && (int)source[i] <= 57)
		{ 
			integers[a] = source[i];
			a++;	
		}
		else
		{
			nonInteger[b] = source[i];
			b++;      
		}
		integers[a] = '\0';
		nonInteger[b] = '\0'; 
	}  
}

int main()
{
	char source[256] = "H684erge5f4e8h!!";
	char integers[256];
	char nonInteger[256];

	printf("Source: %s\n", source);
	function(source,integers,nonInteger);
	printf("Integers: %s, nonintegers: %s\n", integers, nonInteger);
	
	return 0;
}
