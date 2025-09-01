#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("what's is your name? ");
    if (name != NULL)
    {
        printf("hello, %s\n", name);
        return 0;
    }
    else
    {
        printf("Problem 1");
        return 1;
    }
}
