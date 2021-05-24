// Compares two strings using strcmp

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string j = get_string("J: ");
    string k = get_string("K: ");

    if (strcmp(j, k) == 0)
    {
        printf("Same\n");
        return 0;
    }
    printf("Different\n");

}