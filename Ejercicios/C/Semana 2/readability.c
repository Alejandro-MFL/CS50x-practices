#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int ReadAndCalculate(string reading);
void printTheAnswer(int index);

int main(void)
{
    string reading = get_string("Text: ");

    int index = ReadAndCalculate(reading);

    printTheAnswer(index);
}

// It scans the text and counts letters, words and sentences and calculates the Coleman-Liau index.
int ReadAndCalculate(string reading)
{
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0, j = strlen(reading); i < j; i++)
    {
        if (isalpha(reading[i]))
        {
            letters++;
        }
        else if (reading[i] == ' ')
        {
            words++;
        }
        else if (reading[i] == '.' || reading[i] == '!' || reading[i] == '?')
        {
            sentences++;
        }
    }
    words++;
    float l = (letters * 100.0) / words;
    float s = (sentences * 100.0) / words;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    return index;
}

// Prints the answer depending on the reading level
void printTheAnswer(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
