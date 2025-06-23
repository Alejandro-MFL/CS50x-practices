//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 23;
	int* p = &i;
	printf("%p\n", p);
	printf("%i\n", *p - 1);
	printf("%i\n", i);
}

