#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    //Input credit number
    long long credit_num;
    do
    {
        credit_num = get_long_long("Number: ");
    }
    while (credit_num < 1); //Make sure credit number is more than zero

    int digit;  //Declare variables
    int digit_1;
    int digit_2;
    int digit1;
    int digit1_1;
    int digit1_2;
    int sum = 0;
    int sum_1 = 0;
    int sum_total;
    int sum_lastdigit;
    int first2digits;
    int firstdigits;

    //Luhn's algorithm - Group 1
    long long credit_num1 = credit_num / 10; //shift one position to become odd
    while (credit_num1 > 0) //first loop for second to last digit, then repeat
    {
        digit = credit_num1 % 10;
        credit_num1 /= 100;
        digit = digit * 2;
        if (digit > 9) //Add 2 digit value together
        {
            digit_1 = digit % 10;
            digit /= 10;
            digit_2 = digit % 10;
            digit = digit_1 + digit_2;
        }
        sum = sum + digit;
    }

    //Luhn's algorithm - Group 2
    long long credit_num2 = credit_num; //Second loop start from last digit, repeat
    while (credit_num2 > 0)
    {
        digit1 = credit_num2 % 10;
        credit_num2 /= 100;
        if (digit1 > 9) //Add 2 digit value together
        {
            digit1_1 = digit1 % 10;
            digit1 /= 10;
            digit1_2 = digit1 % 10;
            digit1 = digit1_1 + digit1_2;
        }
        sum_1 = sum_1 + digit1;
    }

    //Luhn's algorithm - Others
    sum_total = sum + sum_1;
    sum_lastdigit = sum_total % 10; 

    // Card length
    long long creditdigit = credit_num;
    int digit_length = 0;
    while (creditdigit != 0) //16 -> 0
    {
        creditdigit /= 10;
        digit_length++;
    }

    //Find starting 1st digit and (1st & 2nd digits) //1.23
    first2digits = credit_num / pow(10, digit_length - 2);
    firstdigits = credit_num / pow(10, digit_length - 1);

    //Print AMEX, MASTERCARD, VISA, or INVALID
    if (sum_lastdigit == 0 && digit_length == 15 && (first2digits == 34 || first2digits == 37)) //AMEX condition
    {
        printf("AMEX\n");
    }
    else if (sum_lastdigit == 0 && digit_length == 16 && (first2digits == 51 || first2digits == 52 || first2digits == 53
             || first2digits == 54 || first2digits == 55)) //MASTERCARD condition
    {
        printf("MASTERCARD\n");
    }
    else if (sum_lastdigit == 0 && (digit_length == 13 || digit_length == 16) && firstdigits == 4) //VISA condition
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}