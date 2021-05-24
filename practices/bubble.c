#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int to_sort[10] = {4711, 8, 2, 33, 5, 23, 42, 78, 123, 2398};

// Helper to print arrays
void pretty_printer(int *to_print, size_t size);

int main(int argc, char **argv)
{
    //sorting direction
    int asc = 0;
    if (argc != 2)
    {
        printf("Usage: ./bubble [asc|dsc]\n");
        return 1;
    }

    //TODO: check if sorting in asc (ascending) or dsc (descending) order
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
        printf("Usage: ./bubble [asc|dsc]\n");
        return 1;
    }

    // Some helpers
    // Limit (length of the array - 1)
    // HINT: You need to compare the ith element with the i+1th element
    int limit = sizeof(to_sort) / sizeof(to_sort[0]) - 1;

    // Was there a "bubble" before (Did the program swap at least two numbers), initially true
    bool swp = true;
    for (int i = 0; i < limit; i++)
    {
        swp = false;
        for (int j = 0; j < limit - i; j++)
        {
            //whether to sort asccending or descending
            bool order_asc_dsc;
            if (asc == 1)
            {
                order_asc_dsc = to_sort[j] > to_sort[j + 1];
            }
            else
            {
                order_asc_dsc = to_sort[j] < to_sort[j + 1];
            }
            if (order_asc_dsc)
            {
                int temp = to_sort[j];
                to_sort[j] = to_sort[j + 1];
                to_sort[j + 1] = temp;
                swp = true;
            }
       
        if (swp == false)
        break;
        }
    }

    //TODO
    //HINT: Do you need a do-while or while loop when swp = true initially?
    //HINT: It might make sense to bubble values (up or down)  with a for loop
    pretty_printer(to_sort, limit + 1);

    return 0;

}

void pretty_printer(int *to_print, size_t size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            printf("%i", to_print[i]);
        }
        else
        {
            printf("%i, ", to_print[i]);
        }
    }
    printf("]\n");
}

 /*

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}
*/

/* Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
*/
/*
// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
*/
/* Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
*/

/*
void bubbleSort(int arr[], int n)
{
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);

    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, n-1);
}
*/
/*
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr, i, i + 1);
        }
    }
    if (n - 1 > 1) {
        bubbleSort(arr, n - 1);
    }
}
*/