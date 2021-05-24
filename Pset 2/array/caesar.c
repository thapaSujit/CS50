//a program that encrypts messages using Caesar’s cipher
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//function declaration
bool is_digits(string argv_1);


//declaring global vriables
const int alphabet = 26;

int main(int argc, string argv[])
{
    // checking if the command line arguement is exactly one or is digit. and if they are not, printing "Usage: ./caesar key\n" and exiting the program and if
    //it is exactly one and is digit, returning 0
    if (argc != 2 || !is_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //as the command line argument at argv[1] is always string converting it to integer
    int key = atoi(argv[1]);

    //prompting user for plain text and printing ciphertext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    //iterating over each character in plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)

    {
        // if uppercase, changing plaintxt to ciphertext using the key. Then printing the ciphertext preserving the uppercase.
        if (isupper(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 'A') + key) % alphabet) + 'A'));
        }

        // if lowercase, changing plaintexxt to ciphertext using the key. Then printing the ciphertext preserving the lowercase.
        else if (islower(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 'a') + key) % alphabet) + 'a'));
        }

        // if neither, printing character as it is
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

//a function defination ==> that checks if the characters in argv[1] is digit or not and returns true if digit and false if alpha
bool is_digits(string argv_1)
{
    for (int i = 0; i < strlen(argv_1); i++)
    {
        //as the isalpha function checks over every character, this function will provide segmenttion fault if we use string argv_1. thats why created ane char
        //variable
        char s = argv_1[i];
        if (isalpha(s))
        {
            return false;
        }
    }
    return true;
}
