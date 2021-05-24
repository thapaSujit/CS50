#include <stdio.h>
#include <string.h>
#include <cs50.h>
int main(void)
{
    char *A = "pointer";
    printf("%p\n", &A); // --> prints the address of the pointer
    printf("%p\n", A); // prints the address of the 1st letter in A
    printf("%s\n", A);
     printf("%p\n", &A[0]); //same as above
      printf("%p\n", &A[1]);
       printf("%p\n", &A[2]);
    printf("%p\n", &A[3]); //prints the address of the 3 letter in A
    printf("%p\n", &*(A+4));

    printf("%p\n", &A+4);


    }