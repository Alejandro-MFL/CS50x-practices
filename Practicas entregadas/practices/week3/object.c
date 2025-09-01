#include <cs50.h>
#include <stdio.h>


int main(void)
{
    char name = get_char("Do you think the CS50 system is working? \"y\" or \"n\" ");
    if(name == 'y' || name == 'Y')
    {
        printf("It`s possible, I'd like to think he's ready too.\n");
    }
    else if(name == 'n' || name == 'N')
    {
        printf("I hope you are wrong.\n");
    }
    else
    {
        printf("It's one letter or another, I even accept capital letters...\n");
        main();
    }

}
