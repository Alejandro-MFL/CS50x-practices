#include <cs50.h>
#include <stdio.h>

void buildRows(int rows, int totalRows);
void buildBricks(int bricks);
int askForRows(void);

int main(void)
{
    int numOfRows = askForRows();
    while (numOfRows <= 0)
    {
        numOfRows = askForRows();
    }
    buildRows(numOfRows, numOfRows);
    return 0;
}

void buildRows(int rows, int totalRows)
{
    if (rows <= 0)
    {
        return;
    }
    buildRows(rows - 1, totalRows);
    int spaces = totalRows - rows;
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
    buildBricks(rows);
    printf("  ");
    buildBricks(rows);
    printf("\n");
}

void buildBricks(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}

int askForRows(void)
{
    int numOfRows = get_int("Height: ");

    if (numOfRows > 0 && numOfRows < 9)
    {
        return numOfRows;
    }
    else
    {
        printf("Sorry, I need a number between 1 and 8\n");
        return 0;
    }
}
