#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void pretty_printer(char *to_print, size_t size);
char *to_sort = "zdvixqcuvd";
//the same as "zdvixqcuvd"

int main(int argc, char **argv)
{
    int asc = 0;

    if (argc != 3)
    {
        printf("Usage: ./insertSort [asc|dsc] to_sort\n");
        return 1;
    }
    if (strcmp(argv[1], "asc") == 0)
    {
        asc = 1;
    }
    else if (strcmp(argv[1], "dsc") == 0)
    {
        asc = 0;
    }
    else
    {
        printf("Usage: ./insertSort [asc|dsc] to_sort\n");
        return 1;
    }
    to_sort = argv[2];

    //helpers
    int size = strlen(to_sort);
    int max;
    int index;

    for (int i = 0; i < size; i++)
    {
        max = to_sort[i];
        index = i -1;
        int temp = to_sort[index];
        bool cond;
        if (asc == 1)
        {
            cond = toupper(max) < toupper(to_sort[index]);
        }
        else
        {
            cond = toupper(max) > toupper(to_sort[index]);
        }
        while(index >= 0 && cond)
        {
            to_sort[index + 1] = to_sort[index];
            index--;
            if (asc == 1)
            {
                cond = toupper(max) < toupper(to_sort[index]);
            }
            else
            {
                cond = tolower(max) > tolower(to_sort[index]);
            }
        }
        to_sort[index+1] = max;
        int temp1 = to_sort[index+1];
    }

    //printf(to_sort)
    pretty_printer(to_sort, size);
    return 0;
}

void pretty_printer(char *to_print, size_t size)
{
    //printf("[");
    for (int i = 0; i < size; i++)
    {
        if (size - i > 1)
        {
            printf("%c", to_print[i]);
        }
        else
        {
            printf("%c", to_print[i]);
        }
    }
    printf("\n");
}

/*
#include <math.h>
#include <stdio.h>

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 Driver program to test insertion sort
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
*/