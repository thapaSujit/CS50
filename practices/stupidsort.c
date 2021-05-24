#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void stupidsort(int A[], int size);
bool array_sorted(int A[], int size);
void randomize(int A[], int size);
void pretty_printer(int A[], int size);

int main() {
    int A[] = {5, 7, 8, 9, 6, 3, 4, 2, 3, 1};
    int size = sizeof(A)/sizeof(int);
    printf("asd");
    stupidsort(A, size);
    pretty_printer(A, size);
    return 0;
}

void stupidsort(int A[], int size)
{
    //ToDo
    printf("0");
    while(!array_sorted(A, size))
    {
        randomize(A, size);
    }
    printf("1");
}

bool array_sorted(int A[], int size)
{
    //ToDo
    for (int i = 0; i < size; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
    }
    return true;
}

void randomize(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int j = A[i];
        int temp = rand()%size;
        A[i] = A[temp];
        A[temp] = j;
    }
}

void pretty_printer(int A[], int size)
{
    printf("[ ");
    int k;
    for (k = 0; k < size; k++)
    {
        if (k != size - 1)
        {
            printf("%i, ", A[k]);
        }
    }
    printf("%i ]\n", A[k]);
}


