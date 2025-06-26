#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char* character;
	struct node* next;
}
node;
const int ASCIIMAYUS = 32;
const int ASCIIMIN = 97;

int hash(char* character);
int addNodes(node** origen, char* newChar);
void freeMemo(node* list[]);
void freeList(node* current);

int main(void)
{
	char* word = "Alegria";
	node* table[26] = { NULL };
	int index = hash(word);
	if (index > 26) 
	{
		return index; // no es una palabra o hay problemas con la palabra
	}	
	addNodes(&table[index],word);
	printf("char: %s\n", table[index]->character);
	printf("index: %i\n", index);
	free(table);
}

int addNodes(node** origen, char* newChar)
{
	node* n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->character = newChar;
	n->next = *origen;
	*origen = n;
	return 0;
}

int hash(char* character)
{
	if (character == NULL || character[0] == '\0')
	{
		return 28;
	}		
	char c = character[0];
	if (c < 65)
	{
		return 29;
	}
	else if (c < 97)
	{
		c += ASCIIMAYUS;
	}

	return c - ASCIIMIN;
}

void freeMemo(node* list[]) 
{
	for (int i = 0; i < 26; i++)
	{
		if (list[i]->character != NULL)
		{
			freeList(list[i]);
		}
	}	
}

void freeList(node *current)
{
	if (current->next != NULL)
	{
		freeList(current->next);
	}
	free(current);
}