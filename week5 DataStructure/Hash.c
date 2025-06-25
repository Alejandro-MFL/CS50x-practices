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
void freeMemo(node* list);
void freeList(node* current);

int main(void)
{
	char* word = "hola";
	node* table[26] = malloc(26,sizeof(node));
	int index = hash(word);
	if (index = 28) 
	{
		return 1 // no es una palabra
	}

	
	addNodes(table[index],word);		
	
	

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
	if (character < 65) 
	{
		return 28;
	}
	else if (character < 97)
	{
		character += ASCIIMAYUS;
	}
	return character - ASCIIMIN;
}

void freeMemo(node* list) 
{
	for (int i = 0; i < 26; i++)
	{
		if (list[i].character != NULL)
		{
			freeList(list[i]);
		}
	}
	free(list);
}

void freeList(node* current)
{
	if (current->next != NULL)
	{
		freeList(current->next);
	}
	free(current);
}