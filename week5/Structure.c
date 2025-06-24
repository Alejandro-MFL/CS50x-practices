#include <stdio.h>
#include <stdlib.h>

// Es parte de la explicacion del funcionamiento de los pasos en memoria cuando se agranda un array

int main(void)
{
	//Se crea el array list
	int *list =  malloc(3 * sizeof(int));
	if (list == NULL) 
	{
		return 1;
	}

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	//Con el tiempo quieres agregar un elemento y no sabes si la memoria colindante esta
	//ocupada por lo que se crea una nueva memoria con el espacio necesario.
	int *tmp = malloc(4 * sizeof(int));
	if (list == NULL)
	{
		return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		tmp[i] = list[i];
	}
	tmp[3] = 4;

	free(list);

	list = tmp;

	for (int i = 0; i < 4; i++) 
	{
		printf("%i\n", list[i]);
	}
	
	free(list);
	return 0;

}