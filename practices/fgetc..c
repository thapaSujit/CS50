#include <stdio.h>
int main(void)
{
    char ch;
    while ((ch = fgetc(ptr)) != EOF)
    {
        printf("%c", ch)
        //fputc(ch, ptr2)  -->reading from one file and writing to another
    }
}