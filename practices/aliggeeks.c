#include <stdio.h>
#include <conio.h>

int anagram(char [], char []);
int main()
{
char i[100], j[100];
printf("two strings must be entered\n");
gets(i);
gets(j);
//checking anagrams
if (anagram(i, j) == 1)
printf("The given two strings are anagrams\n");
else
printf("The given two strings are not anagrams\n");
return 0;
}
int anagram(char i[], char j[])
{
int first1[26] = {0}, second1[26] = {0}, d=0;
// the frequency of characters in the first string is calculated
while (i[d] != '\0')
{
first1[i[d]-'a']++;
d++;
}
d = 0;
while (j[d] != '\0')
{
second1[j[d]-'a']++;
d++;
}
// the frequency of characters in the second string is calculated
for (d = 0; d < 26; d++)
{
if (first1[d] != second1[d])
return 0;
}
return 1;
}


/*
reverse.c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string s= get_string("input: ");
    for (int i = strlen(s) - 1; i >= 0; i-- )
    {
        printf("%c", s[i]);
    }
    printf("\n");
}

ADDITION.C
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool is_digit(string s);
int main(int argc, string argv[])
{
	if ( argc != 3 || (!is_digit(argv[1]) && !is_digit(argv[2])))
    {
        return 1;
    }
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    printf("%s + %s = %i\n", argv[1], argv[2], i + j);
}

bool is_digit(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (isalpha(c)
        {
            return false;
        }
    }
    return true;
}
palindrom.c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string s = get_string("Text: ");
    int len  = strlen(s);
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        printf("left: %i; right: %lu\n", i, strlen(s) - i - 1);
        if (s[i] != s[strlen(s) - i - 1])
        {
            printf("No palindrome!\n");
            return 1;
        }
    }

    printf("It is a palindrome\n");
}

initials.c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string s = get_string("Name: ");
    bool output = true;

    printf("Initials:");

    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == ' ')
        {
            output = true;
        }
        else if (output == true)
        {
            printf("%c", toupper(s[i]));
            output = false;
        }

    }
    printf("\n");
}
https://sandbox.cs50.io/55c2a59f-0a70-4885-9afa-158ee6371ad8


student.c ==> https://sandbox.cs50.io/fec7b461-8e9d-4489-9cb2-306ab9e4d131

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct
{
    int student_id;
    string name;
    float gpa;
}
student;

int main(void)
{
    student students[2];
    //student chris and student max => if we dnt want to mae anew variable students
    students[0].student_id = 22608603;
    students[0].name = "Sujit Thapa";
    students[0].gpa = 1.97;

    students[1].student_id = 22608803;
    students[1].name = "Anshaj Upadhyaya";
    students[1].gpa = 2.7;

    for (int i =0; i <2; i++)
    {
        printf("%s, %i, %f \n", students[i].name, students[i].student_id, students[i].gpa);
    }

}

factorial.c
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n-1);
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    int n = atoi(argv[1]);
    printf("The factorial of %i is %i\n", n, fact(n));
    return 0;
}


fobonachi.c
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int fib(int n)
{
    if (n == 0)
    {
        return n;
    }
    else if (n ==1)
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    int n = atoi(argv[1]);
    printf("The factorial of %i is %i\n", n, fib(n));
    return 0;
}


binary.c
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int value, int values[], int start, int end)
{
    int middle = (start + end) / 2;
    if (values[middle] == value)
    {
        return true;
    }
    else if (values < values[middles])
    {
        return search(value, values[], start, middle - 1)
    }
    else (values > values[middles]) // not necessary to write (values > values[middles])
    {
        return search(value, values[], middle + 1, end)
    }
    return false;
}

int main(int argc, string argv[])
{
    int values[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int value = atoi(argv[1]);
    if (search(value, values, 0, sizeof(values)/sizeof(int) - 1))
    {
        printf("Exists\n");
    }
    else
    {
        printf("Does not exist\n");
    }
}

binarysearch.c
https://sandbox.cs50.io/fec7b461-8e9d-4489-9cb2-306ab9e4d131
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(int value, int values[], int start, int end)
{
    if(end < start)
    {
        return false;
    }

    int middle = (start + end) / 2;
    if (values[middle] == value)
    {
        return true;
    }
    else if (value < values[middle])
    {
        return search(value, values, start, middle - 1);
    }
    else // not necessary to write (values > values[middles])
    {
        return search(value, values, middle + 1, end);
    }

}

int main(int argc, string argv[])
{
    int values[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int value = atoi(argv[1]);
    if (search(value, values, 0, sizeof(values)/sizeof(int) - 1))
    {
        printf("Exists\n");
    }
    else
    {
        printf("Does not exist\n");
    }
}

   /*
    Byte buffer[Block_Size];
    int jpeg_count = 0
    bool is_jpeg = false;
    FILE *present_file;

    while(true)

    //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    //fread(<buffer><size><qty><filepointer)
    size_t bytes_read = fread(buffer, sizeof(BYTE), Block_Size, file);
    //the end of the file is reached, the return value is a short item count (or zero).
    if (bytes_read ==0)
    {
        break;
    }
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        if(!is_first_jpeg)
        {
           is_first_jpeg = false ;
        }
        else
        {
            fclose(present_file)
        }
    }
    //looking at the beginning of JPEG --> the first three bytes of jpeg file are 0xff, 0xd8, 0xff. the fourth(last) byte = 0xe(1-f)
    //Open a new JPEG File
    //Write 512 bytes unil a a new jpeg is found
}
/*











/*
    //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    //fread(<buffer><size><qty><filepointer)
    size_t bytes_read = fread(buffer, sizeof(BYTE), Block_Size, file);
    //the end of the file is reached, the return value is a short item count (or zero).
    if (bytes_read ==0)
    {
        break;
    }
        {
        if(!is_first_jpeg)
        {
           is_first_jpeg = false ;
        }
        else
        {
            fclose(present_file)
        }
    }
    //looking at the beginning of JPEG --> the first three bytes of jpeg file are 0xff, 0xd8, 0xff. the fourth(last) byte = 0xe(1-f)
    //Open a new JPEG File
    //Write 512 bytes unil a a new jpeg is found
}














/*
    //setting counter and int to 0.counter will be used to increment the name of the files generated, and variables will be used to check stop at the
    //file end. another array is deffined to store the name of file

    int counter = 0;

    int s = 0;
    //declring n array
    char name_of_file[8];

    //loop which checks the return of fread to see if we have reach the end of file
    do
    {
        //creating the buffer arrayto store the 512 bytes that will be read --> ***note to self--can use mallock as well but donot want to stress for now
        BYTE buffer[Block_Size];
        //readingthe 512 byte ino the buffer
        s = fread(buffer, sizeof(BYTE), Block_Size, file);
        //looking at the beginning of JPEG --> the first three bytes of jpeg file are 0xff, 0xd8, 0xff. the fourth(last) byte = 0xe(1-f)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (counter ==0)
            {
                //storing the name of file into the string file name
                sprintf(name_of_file, "%03i.jpg", 0);
                counter++;
                //opening anew file to write
                FILE *new_file = fopen(name_of_file, "w");
                fwrite(buffer, sizeof(BYTE), Block_Size, new_file);
                fclose(new_file);
            }
        }
    }
    while (s == Block_Size);
}





#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define Block_Size 512
//defining a new byte representing an 8 bit unsigned char
typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    // Check for invalid input
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
       char* input_file = argv[1];
    FILE* input_pointer = fopen(input_file, "r");
    if (input_file == NULL)
    {
        printf("Unable to open: %s\n", input_file);
        return 1;
    }
    // Create buffer
    BYTE buffer[Block_Size];
// File counter, initialise
    int image_counter = 0;
    FILE *output_pointer = NULL;
// Check if JPEG is found
    bool jpg_has_alr_been_found = false; //False

    //Read through the whole block, repeat for all files
    while (fread(buffer, Block_Size, 1, input_pointer) == 1)
    {
        //if start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if JPEG has been found
            if (jpg_has_alr_been_found == true)
            {
                // Start of an image has been found, so close current image
                fclose(output_pointer);
            }
            //if first JPEG, create a new first file and write in it
            else
            {
                //new JPEG discovered and we can write on file
                jpg_has_alr_been_found = true;
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", image_counter);
            output_pointer = fopen(filename, "w");
            image_counter++;
        }
        if (jpg_has_alr_been_found == true)//once new JPEGS are found
        {
            //copy over the blocks from buffer into new file
            fwrite(buffer, Block_Size, 1, output_pointer);
        }
    }
      if (output_pointer == NULL)
    {
        fclose(output_pointer);
    }
    if (input_pointer == NULL)
    {
        fclose(input_pointer);
    }
    return 0;
}

concat.c
https://sandbox.cs50.io/7f23a77f-185d-42bd-bdaf-4bdf353b2c53
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *concatenate(char *s1, char *s2);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage: ./concat string1 string2 \n");
        return 1;
    }

    char *s = concatenate(argv[1], argv[2]);
    printf("%s\n", s);
    free(s);
}

char *concatenate(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char *s = malloc(len1 + len2 + 1);

    for (int i = 0; i < len1; i++)
    {
        s[i] = s1[i];
    }


    for (int i = 0; i < len2; i++)
    {
        s[i + len1] = s2[i];
    }
    s[len1 + len2] = '\0';

    return s;
}



