#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Name
    string name = get_string("what is your name? ");

    // Age
   int age = get_int("what is your age? ");

    //Hometown
    string hometown = get_string("what is your hometown? ");

    // Phone number
    int phoneNumber = get_int("what is your phone number? ");

    printf("Friend's data: \nName: %s\nAge: %i\nHometown: %s\nPhone number: %i \n ", name, age,hometown,phoneNumber );

}
