#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getDate(void);

int main(void)
{
    //Obtener fecha y hora
    char* fecha = getDate();
    printf("fecha:  %s", fecha);
    free(fecha);
    return 0;
}
char* getDate(void) 
{
    time_t t;
    struct tm* tm_info;
    char* fecha = malloc(100);

    time(&t);
    tm_info = localtime(&t);
    strftime(fecha, 100, "%Y-%m-%d_%H-%M-%S", tm_info);
    return fecha;
}