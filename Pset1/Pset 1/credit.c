// a program that checks whether the credit card number is valid and to which company it belongs to
#include <stdio.h>
#include <cs50.h>

int digit_length(long n);
int main(void)
{
    //prompting the used for input and counting the length of the input
    long cc_number = get_long("Number: ");
    long length_cc_number = digit_length(cc_number);

    //getting access to each digit on the credit card number and multiplying every other digits assuming maximum
    //digit is 16. To get access to each digit, walkthrough by Bryan was followed using / and modulas to get access
    //to each digit. Likewise,every other digit is multiplied by 2 for Luhn’s Algorithm and giving it a new variable name
    int d1 = ((cc_number / 1000000000000000) % 10);
    int dm1 = d1 * 2;

    int d2 = ((cc_number / 100000000000000) % 10);

    int d3 = ((cc_number / 10000000000000) % 10);
    int dm3 = d3 * 2;

    int d4 = ((cc_number / 1000000000000) % 10);

    int d5 = ((cc_number / 100000000000) % 10);
    int dm5 = d5 * 2;

    int d6 = ((cc_number / 10000000000) % 10);

    int d7 = ((cc_number / 1000000000) % 10);
    int dm7 = d7 * 2;

    int d8 = ((cc_number / 100000000) % 10);

    int d9 = ((cc_number / 10000000) % 10);
    int dm9 = d9 * 2;

    int d10 = ((cc_number / 1000000) % 10) ;

    int d11 = ((cc_number / 100000) % 10);
    int dm11 = d11 * 2;

    int d12 = ((cc_number / 10000) % 10);

    int d13 = ((cc_number / 1000) % 10);
    int dm13 = d13 * 2;

    int d14 = ((cc_number / 100) % 10) ;

    int d15 = ((cc_number / 10) % 10);
    int dm15 = d15 * 2;

    int d16 = (cc_number % 10) ;

    //Here inorder to add the products digit which is multiplied by 2 (not the product itself), each product which
    //is larger than 9 is substracted from 9
    if (dm1 > 9)
    {
        dm1 -= 9;
    }
    if (d3 > 9)
    {
        dm3 -= 9;
    }
    if (d5 > 9)
    {
        dm5 -= 9;
    }
    if (d7 > 9)
    {
        dm7 -= 9;
    }
    if (d1 > 9)
    {
        dm9 -= 9;
    }
    if (d1 > 9)
    {
        dm11 -= 9;
    }
    if (d1 > 9)
    {
        dm13 -= 9;
    }
    if (d1 > 9)
    {
        dm15 -= 9;
    }

    //adding products digit together (the digit which is multiplied by 2)
    int sum1 = dm1 + dm3 + dm5 + dm7 + dm9 + dm11 + dm13 + dm15;

    //adding products digits (the digit which is multiplied by 2 and those digits that are not multiplied by 2
    int sum2 = sum1 + d2 + d4 + d6 + d8 + d10 + d12 + d14 + d16;

    // creating a variable to the the validity
    int valid = sum2 % 10;

    //based on the length of creditcard number and first two digits, identing fying to which company credit card
    //belongs to
    if (valid != 0 && length_cc_number <= 13)
    {
        printf("INVALID\n");
    }

    else if (length_cc_number == 15 && d1 == 0 && d2 == 3 && (d3 == 4 || d3 == 7))
    {
        printf("AMEX\n");
    }

    else if ((length_cc_number == 13 || length_cc_number == 16) && d4 == 4)
    {
        printf("VISA\n");
    }

    else if (length_cc_number == 16 && d1 == 5 && (d2 == 1 || d2 == 2 || d2 == 3 || d2 == 4 || d2 == 5))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }


}



//function that counts the number of digit in creditcard number
int digit_length(long n)
{
    int length = 0;
    while (n != 0)
    {
        n = n / 10;
        length++;
    }
    return length;
}


