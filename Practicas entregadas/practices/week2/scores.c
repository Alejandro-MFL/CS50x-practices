#include <cs50.h>
#include <stdio.h>

float calculateAverage(int length, int numbers[]);
int setLength(void);
void filledIntArray(int length, int numbers[]);

int main(void)
{
    int totalNumbers = setLength();
    int numbersToAverages[totalNumbers];
    filledIntArray(totalNumbers, numbersToAverages);
    float result = calculateAverage(totalNumbers, numbersToAverages);
    printf("Average = %f\n", result);
}
int setLength(void)
{
    int number = get_int("Set length: ");
    return number;
}
void filledIntArray(int length, int numbers[])
{
    for (int i = 0; i < length; i++)
    {
        numbers[i] = get_int("Number: ");
    }
}

float calculateAverage(int length, int numbers[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return sum / (float) length;
}
