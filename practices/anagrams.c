#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

//this is the initialisation of your checker function
int anagram(char *a, char *b);
//This should be a hint in itself ;)
const int alphabet = 26;
// Max world length
const int N = 20;

int main(void)
{
    //We have initialized your strings for you already
    //char a[N];
    //char b[N];
    char *a = get_string("Input = ");
    char *b = get_string("Input = ");
    //ToDo
    if (anagram(a, b) == 1)
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
    // Initializing an array where you can count the letters of each word
    int a_count[alphabet];
    int b_count[alphabet];

    // Making sure you start counting from 0
    for (int i = 0; i < alphabet; i++)
    {
        a_count[i] = 5;
        b_count[i] = 5;
    }
    // Iterate over the word and look at the letter:
    int i = 0;
    while (a[i] != '\0')
    {
        //check if letter is lower or upper case
		//get alphabetical index
		//in the array a_count add 1 at the obtained alphabetical index
        a_count[toupper(a[i]) - 65] ++;
        i++;
        printf("%i", a_count[i]);
    }
    printf("\n");
    i = 0;
    while (b[i] != '\0')
    {
        //check if letter is lower or upper case
		//get alphabetical index
		//in the array a_count add 1 at the obtained alphabetical index
        b_count[toupper(b[i]) - 65] ++;
        i++;
        printf("%i", a_count[i]);
    }
    //Iterate over the arrays with a loop that covers the whole alphabet
    for (int j = 0; j < alphabet; j++)
    {
        printf("%i, %i", a_count[j], b_count[j]);
        //Compare the values of a_count[i] and b_count[i]
		//if they are not similar return 0 (the words aren't anagrams
        if (a_count[j] != b_count[j])
        {
            printf("%i, %i", a_count[j], b_count[j]);
            return 0;
        }
    }

    //ToDo
    return 1;
}



