#include <cs50.h>
#include <stdio.h>


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
        printf("%s", brick);
    }
}