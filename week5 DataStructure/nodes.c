#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

void freeList(node* current);
void printList(node* current);
void printInvertedList(node *current);
int addNodes(node **origen, int newInt);

int main(void)
{
	node *list = NULL;

	for (int i = 0; i < 3; i++)
	{
		int check = addNodes(&list, i);
		if (check != 0) 
		{
			return check;
		}
	}

	int check = addNodes(&list, 9);
	if (check != 0)
	{
		return check;
	}
	printList(list);
	printInvertedList(list);
	freeList(list);
	return 0;
}

int addNodes(node **origen, int newInt)
{
	node *n = malloc(sizeof(node));
	if (n == NULL)
	{
		return 1;
	}
	n->number = newInt;
	n->next = *origen;
	*origen = n;
	return 0;
}

//Al estar la lista agragada los numeros al principio o en pila,
//he decidido considerarla invertida para el nombre de las funciones, no es ideal

void printInvertedList(node* current) 
{	
	printf("p: %i\n", current->number);
	if (current->next != NULL)
	{
		printInvertedList(current->next);
	}
}

void printList(node *current) 
{
	if (current->next != NULL)
	{
		printList(current->next);
	}
	printf("p: %i\n", current->number);		
}
//Modularizo la liberacion de memoria
void freeList(node *current)
{
	if (current->next != NULL)
	{
		freeList(current->next);
	}
	free(current);
}
