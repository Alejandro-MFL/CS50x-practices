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

node* table[26];

