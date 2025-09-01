#include <cs50.h>
#include <stdio.h>

long long askCard(void);
int checkLength(long long card);
void createList(long long card, int length, int listLong[]);
int checkCompany(int array[], int length);
bool checkLuhn(int array[], int length);
void printResult(bool lunh, int company);

int main(void)
{
    long long card = askCard();
    int length = checkLength(card);
    int listCard[length];
    createList(card, length, listCard);
    int ref = checkCompany(listCard, length);
    bool luhn = checkLuhn(listCard, length);
    printResult(luhn, ref);
    return 0;
}

void printResult(bool lunh, int company)
{
    if (lunh == true)
    {
        if (company == 1)
        {
            printf("AMEX\n");
        }
        else if (company == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (company == 3)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checkLuhn(int array[], int length)
{
    int sumDouble = 0;
    int sumNormal = 0;

    for (int i = 0; i < length; i++)
    {
        if ((i == 0 || i % 2 == 0))
        {
           sumNormal += array[i];
        }
        else
        {
            int x2 = array[i] * 2;
            if (x2 < 10)
            {
                sumDouble += x2;
            }
            else
            {
                sumDouble += (x2 / 10);
                sumDouble += (x2 % 10);
            }
        }
    }

    // Unlock to check the Luhn calculation
    /*int sum = sumDouble + sumNormal;
    printf("%d ",sum);*/

    if ((sumDouble + sumNormal) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkCompany(int array[], int length)
{
    if (length == 15)
    {
        if (array[14] == 3 && (array[13] == 4 || array[13] == 7))
        {
            return 1;
            // AMEX reference
        }
        else
        {
            return 9;
            // INVALID reference
        }
    }
    else if (length == 16)
    {
        if (array[15] == 5 && (array[14] == 1 || array[14] == 2 || array[14] == 3 ||
                               array[14] == 4 || array[14] == 5))
        {
            return 2;
            // MASTERCARD reference
        }
        else if (array[15] == 4)
        {
            return 3;
            // VISA reference
        }
        else
        {
            return 9;
        }
    }
    else if (length == 13)
    {
        if (array[12] == 4)
        {
            return 3;
        }
        else
        {
            return 9;
        }
    }
    else
    {
        return 9;
    }
}

long long askCard(void)
{
    long long cardNum = get_long("Number: ");
    return cardNum;
}

int checkLength(long long card)
{
    int digits = 0;

    while (card > 0)
    {
        card /= 10;
        digits++;
    }
    return digits;
}

void createList(long long card, int length, int listInt[])
{
    for (int i = 0; i < length; i++)
    {
        int n = card % 10;
        card /= 10;
        listInt[i] = n;
    }
}
