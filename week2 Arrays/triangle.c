#include <cs50.h>
#include <stdio.h>

void checkSides(float triangle[]);
float askSide();
void makeATriangle();
void tryAgain();
const int SIDE_OF_TRIANGLE = 3;

int main(void)
{
    makeATriangle();
}
void makeATriangle()
{
    float triangle[SIDE_OF_TRIANGLE];
    triangle[0] = askSide();
    triangle[1] = askSide();
    triangle[2] = askSide();
    checkSides(triangle);
}

float askSide()
{
    float side = get_float("Length of one side: ");
    while (side <= 0)
    {
        side = get_float("Length of one side (positive number): ");
    }
    return side;
}

void checkSides(float triangle[])
{
    if (triangle[0] + triangle[1] > triangle[2] && triangle[0] + triangle[2] > triangle[1] &&
        triangle[1] + triangle[2] > triangle[0])
    {
        printf("The sides form a valid triangle.\n");
    }
    else
    {
        printf("The sides no form a valid triangle.\n");
        tryAgain();
    }
}
void tryAgain()
{
    char confirmation = get_char("If you want to try again, press \"y\": ");
    if (confirmation == 'y' || confirmation == 'Y')
    {
        makeATriangle();
    }
}
