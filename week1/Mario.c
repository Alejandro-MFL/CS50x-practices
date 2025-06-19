#include <cs50.h>
#include <stdio.h>

/*
void Row(int blocks);
string brick = "#";
int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        int blocks = i + 1;
        Row(blocks);
         printf("\n");
    }
}

void Row(int blocks)
{
    for (int i = 0; i < blocks; i++)
    {
        printf("%s",brick);
    }
}*/
void draw(int bricks);

int main(void)
{
    int numOfRows = get_int("How many rows of bricks do you want? ");
    draw(numOfRows);
}

void draw(int bricks)
{
    if (bricks <= 0)
    {
        return;
    }
    draw(bricks - 1);
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
