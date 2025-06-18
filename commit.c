#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* getDate(void);
int autoCommit(char* message);

int main(void)
{
    //Obtener fecha y hora
    char* fecha = getDate();
    //Comandos de Git
    int check = autoCommit(fecha);

    printf(" Commit automatico %s completado con éxito.\n", fecha);

    free(fecha);
    return check;
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

int autoCommit(char* message)
{
    //Comandos de Git
    char addChanges[] = "git add .";
    char commitchanges[200];
    char pushChanges[] = "git push";
    snprintf(commitchanges, sizeof(commitchanges), "git commit -m \"Auto-commit %s\"", message);
    //Los ejecuta
    int checkAdd = system(addChanges);
    if (checkAdd != 0)
    {
        printf("Error al ejecutar 'git add'\n");
        return 1;
    }
    if (system("git diff --cached --quiet") != 0)
    {
        int checkCommit = system(commitchanges);
        if (checkCommit != 0)
        {
            printf("Error al ejecutar 'git commit'\n");
            return 2;
        }
        int checkPush = system(pushChanges);
        if (checkCommit != 0)
        {
            printf("Error al ejecutar 'git push'\n");
            return 3;
        }
        return 0;
    }
    printf("no habia cambios\n");
    return 4;
    
}