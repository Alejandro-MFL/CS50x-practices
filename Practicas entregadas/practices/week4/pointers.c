#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /*
        int i = 23;
        int *p = &i;
        printf("%p\n",p);
        printf("%i\n",*p-1);
        printf("%i\n",i);
    */

    // 1. Abrir archivo
    FILE *input = fopen("hi.txt", "r");

    if (input == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // 2. Crear buffer para leer datos (caracteres + 1 para '\0')
    char *buffer = malloc(5); // 3 caracteres + 1 para terminador nulo(pone hi!)
    if (buffer == NULL)
    {
        return 1;
    }

    // 3. Leer hasta 4 bytes
    size_t bytesRead = fread(buffer, sizeof(char), 4, input);

    buffer[bytesRead] = '\0'; // Asegurar que sea string válido

    // 4. Imprimir contenido leído
    printf("Leído: %s\n", buffer);

    // 5. Cerrar archivo
    free(buffer);
    fclose(input);

    return 0;
}
