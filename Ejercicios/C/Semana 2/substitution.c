#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool checkKey(string key);
void encrypt(string plainT, string key);

/*Checks that only one argument has been given and executes the functions*/
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    bool validKey = checkKey(key);
    if (validKey == false)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    encrypt(plaintext, key);
    return 0;
}

/*Check that the password is 26 characters long and that it is not repeated or
  contains any characters outside the English alphabet.*/
bool checkKey(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int characters[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int character = toupper(key[i]) - 'A';
        if (character > 25)
        {
            return false;
        }
        if (characters[character] == 1)
        {
            return false;
        }
        else
        {
            characters[character] = 1;
        }
    }
    return true;
}

// Encrypts the plain argument according to the key argument, respecting uppercase.
void encrypt(string plainT, string key)
{
    char encrypted[strlen(plainT) + 1];
    for (int i = 0, j = strlen(plainT); i < j; i++)
    {
        if (isupper(plainT[i]))
        {
            int character = plainT[i] - 'A';
            encrypted[i] = toupper(key[character]);
        }
        else if (islower(plainT[i]))
        {
            int character = plainT[i] - 'a';
            encrypted[i] = tolower(key[character]);
        }
        else
        {
            encrypted[i] = plainT[i];
        }
    }
    encrypted[strlen(plainT)] = '\0';
    printf("ciphertext: %s\n", encrypted);
}
