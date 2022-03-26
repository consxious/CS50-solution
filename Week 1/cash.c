#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float a;
    do
    {
        a = get_float("Change owed: "); //Ask user to input positive float number
    }
    while (a <= 0); //input must larger than 0 (0.41 > 0)
    int cents = round(a * 100);  //dollars to cents (0.41 * 100 = 41)
    int count = 0;  //count coins
    while (cents >= 25) //Quarters 25 cents (1, 41 - 25)
    {
        count++;
        cents -= 25;
    }
    while (cents >= 10) //Dimes 10 cents (2, 41 - 25 -10 )
    {
        count++;
        cents -= 10;
    }
    while (cents >= 5) //Nickels 5 cents (3, 41 -25 -10 -5)
    {
        count++;
        cents -= 5;
    }
    while (cents >= 1) //Pennies 1 cent (4, 41 -25 -10 -5 -1)
    {
        count++;
        cents -= 1;
    }
    printf("%i\n", count); //Total number largest coins returned
}