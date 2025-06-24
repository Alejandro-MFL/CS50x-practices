#include <cs50.h>
#include <stdio.h>

void myMerge(int length, int array[]);
void divideArray(int array[], int left, int right);
void sortAndMerge(int array[], int left, int mid, int right);
void printList(string text, int array[], int length);

int main(void)
{
    int list[] = { 0, 6, 1, 2, 8, 0, 35, 7, 10 };
    int listLength = 9;
    printList("List", list, listLength);
    myMerge(listLength, list);
    printList("Ordered list", list, listLength);
}
void printList(string text, int array[], int length)
{
    printf("%s \n", text);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void myMerge(int length, int array[])
{
    divideArray(array, 0, length - 1);
}

void divideArray(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        /*En caso de que no sea un numero unico se vuelve a llamar para hacer el proceso en dos
                mitades, esto para ir organizando desde int individuales para reducir el tiempo de
                        procesado, a costa de crear arrays temporales que aumenta la memoria*/
        divideArray(array, left, mid);
        divideArray(array, mid + 1, right);
        sortAndMerge(array, left, mid, right);
    }
}

void sortAndMerge(int array[], int left, int mid, int right)
{
    int lengthLeft = mid - left + 1;
    int lengthRight = right - mid;

    // Se hacen los arrays temporales y se rellenan
    int leftArray[lengthLeft], rightArray[lengthRight];

    for (int i = 0; i < lengthLeft; i++)
    {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < lengthRight; j++)
    {
        rightArray[j] = array[mid + j + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < lengthLeft && j < lengthRight)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // En caso de que uno de los arrays sea más grande porque la lista sea impar se copia el resto,
    // que al estar ordenado el ultimo sera mas alto.

    while (i < lengthLeft)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j < lengthRight)
    {

        array[k] = rightArray[j];
        j++;
        k++;
    }
}