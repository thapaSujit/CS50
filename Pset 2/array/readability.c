// a programme that calculates the grade level to understand different texts

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string x);
int count_words(string x);
int count_sentences(string x);

int main(void)
{
    // asking the user for the text
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    printf("%i\n", letters);
    printf("%i\n", words);
    printf("%i\n", sentences);

    //calculating letters per 100 words and sentence per 100 words
    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;

    // using Coleman-Liau index, calculating the grade
    int grade = round((0.0588 * l) - (0.296 * s) - 15.8);

    // if the grade is less than 1, printing "Before Grade 1"
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    // if the grade is grade than 16, printing "Grade 16+"
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    // if the grade is between 1 & 16 exclusive, printing respective "Grade "
    else
    {
        printf("Grade %i\n", grade);
    }
}


// a function that counts the number of letters in the text
int count_letters(string x)
{
    int ls = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isalpha(x[i]))
        {
            ls++;
        }

    }
    return ls;
}

// a function that counts the number of words in the text
int count_words(string x)
{
    int ws = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (x[i] == ' ')
        {
            ws++;
        }
    }
    return ws + 1;
}

// a function that counts the number of sentences in the text
int count_sentences(string x)
{
    int ss = 0;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (x[i] == '.' || x[i] == '!' || x[i] == '?')
        {
            ss++;
        }
    }
    return ss;
}