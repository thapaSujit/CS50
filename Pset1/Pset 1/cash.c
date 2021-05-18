// a greedy alogorithprogram that calculates the maximum number of coint to return based on the amount oweed
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompting input for an positive input, if input is negative, then reprompting user to again enater a new input
    float change_owed;
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while (change_owed < 0);

    //convert change owed to cents
    int cents = round(change_owed * 100);
    {
        printf("%i\n", cents);
    }

    //initializing required variables
    int no_of_coin = 0;
    int remaining_cents = 0;
    remaining_cents = cents;

    //if the remaining cents- the variable which we have assigned as centsis higher or equal to 25 cents, then
    //increasing the number of coin by 1 and reducing the remaining cents by 25. Continuing this process using while
    //loop until remaning cents is greater or equal to 25 cents
    while (remaining_cents >= 25)
    {
        no_of_coin++;
        remaining_cents -= 25;
        printf("coins = %i\n", no_of_coin);
    }

    //if the new remaining cents is higher or equal to 10 cents, then increasing the number of coin by 1 and
    //reducing the remaining cents by 10. Continuing this process using while loop until remaning cents is
    //greater or equal to 10 cents
    while (remaining_cents >= 10)
    {
        remaining_cents -= 10;
        no_of_coin++;
        printf("coins = %i\n", no_of_coin);
    }

    //if the new remaining cents is higher or equal to 5 cents, then increasing the number of coin by 1 and
    //reducing the remaining cents by 5. Continuing this process using while loop until remaning cents is
    //greater or equal to 5 cents
    while (remaining_cents >= 5)
    {
        remaining_cents -= 5;
        no_of_coin++;
        printf("coins = %i\n", no_of_coin);
    }

    //if the new remaining cents is higher or equal to 1 cents, then increasing the number of coin by 1 and
    //reducing the remaining cents by 1. Continuing this process using while loop until remaning cents is
    //greater or equal to 1 cents
    while (remaining_cents >= 1)
    {
        remaining_cents -= 1;
        no_of_coin++;
        printf("coins = %i\n", no_of_coin);
    }

    //printing the minimum number of coins required which is based on user input value
    printf("coins = %i\n", no_of_coin);

}