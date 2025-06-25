#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char character;
	struct node* next;
}
node;
const int ASCIIMAYUS = 32;
const int ASCIIMIN = 97;

int hash(char* character);

int main(void)
{
	node* table[26] = malloc(26,sizeof(node));
}


int hash(char* character)
{
	if (character < 97)
	{
		character += ASCIIMAYUS;
	}
	return character - ASCIIMIN;
}