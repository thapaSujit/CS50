
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>

int anagram(char *a, char *b);
const int alphabet = 26;

int main(void)
{
    char *a = get_string("1. Word: ");
    char *b = get_string("2. Word: ");

    if (anagram(a, b))
    {
        printf("Strings are anagrams\n");
    }
    else
    {
        printf("Strings are not anagrams\n");
    }
    return 0;

}

int anagram(char *a, char *b)
{
    int _a[26] = {0}, _b[26] = {0};
    int counter = 0;

    while (a[counter] != '\0')
    {
        _a[tolower(a[counter]) - 97] ++;
        counter++;
        printf("%i", _a[counter]);
    }
    counter = 0;
    while (b[counter] != '\0')
    {
        _b[tolower(b[counter]) - 97] ++;
        counter++;
        printf("%i", _b[counter]);
    }

    for (int i = 0; i < alphabet; i++)
    {
        printf("%i", _a[i]);
        printf("\n");

        if(_a[i] != _b[i])
        {
            return 0;
        }
    }
    return 1;
}