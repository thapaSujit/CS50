#include <stdio.h>

int shellsort(int A[], int size);
void pretty_printer(int A[], int size);

int main(void)
{
    int A[] = {3, 4, 9, 10, 2, 1, 7, 5, 6, 8};
    int size = sizeof(A) / sizeof(int);

    shellsort(A, size);
    pretty_printer(A, size);
    return 0;
}

int shellsort(int A[], int size)
{
    for (int crs = size / 2; crs > 0; crs /= 2)
    {
        for (int i = crs; i < size; i++)
        {
            int temp = A[i];
            int swp;
            for (swp = i; swp >= crs && A[swp - crs] > temp; swp -= crs)
            {
                A[swp] = A[swp - crs];
            }
            A[swp] = temp;
        }
    }
    return 0;
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
    printf("%i ]", A[k]);
}

// Shell Sort in C programming
/*
#include <stdio.h>

// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 10};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  printf("Sorted array: \n");
  printArray(data, size);
}
*/