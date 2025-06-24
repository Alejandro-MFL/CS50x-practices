#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
} node;

void printList(node *current);

int main(void)
{
	node *list = NULL;

	for (int i = 0; i < 3; i++)
	{
		node *n = malloc(sizeof(node));
		if (n == NULL)
		{
			return 1;
		}
		n->number = i;
		n->next = list;
		list = n;		
	}

	printList(list);
	return 0;
}

void printList(node *current) 
{
	if (current->next != NULL)
	{
		printList(current->next);
	}

	printf("p: %i\n", current->number);
	free(current);	
}