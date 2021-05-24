
int to_sort[10] = {4711, 8, 2, 33, 5, 23, 42, 78, 123, 2398};

void pretty_printer(int *to_print)
{
    printf("[");
    for (int i = 0, j = sizeof(to_sort)/sizeof(to_sort[0]); i < j; i++)
    {
        if (i == j - 1)
        {
            printf("%i", to_print[i]);
            break;
        }
        printf("%i, ", to_print[i]);
    }
    printf("]\n");
}

int main(int argc, char **argv)
{
    int asc = 0;

    if (argc != 2)
    {
        printf("Usage: ./selsort [asc|dsc]\n");
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
        printf("Usage: ./selsort [asc|dsc]\n");
        return 1;
    }

    //helpers
    int limit = sizeof(to_sort)/sizeof(to_sort[0]);
    int max;
    int maxIndex;
    //why this way? :)
    for (int i = limit - 1; i > 0; i--)
    {
        max = to_sort[i];
        maxIndex = i;
        for (int j = 0; j < i; j++)
        {
            int mich = to_sort[j];
            bool cond = to_sort[j] >= max;
            if (!asc)
            {
                cond = !cond;
            }
            if (cond)
            {
                max = to_sort[j];
                maxIndex = j;
            }
        }
        int tmp = to_sort[i];
        to_sort[i] = to_sort[maxIndex];
        to_sort[maxIndex] = tmp;
    }

    pretty_printer(to_sort);
    return 0;
}

/*
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

 Function to print an array
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}


// C++ program for modifying Selection Sort
// so that it becomes stable.
#include <iostream>
using namespace std;

void stableSelectionSort(int a[], int n)
{
    // Iterate through array elements
    for (int i = 0; i < n - 1; i++)
    {

        // Loop invariant : Elements till a[i - 1]
        // are already sorted.

        // Find minimum element from
        // arr[i] to arr[n - 1].
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;

        // Move minimum element at current i.
        int key = a[min];
        while (min > i)
        {
            a[min] = a[min - 1];
            min--;
        }
        a[i] = key;
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int a[] = { 4, 5, 3, 2, 4, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    stableSelectionSort(a, n);
    printArray(a, n);
    return 0;
}
