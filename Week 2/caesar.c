#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])  //Command-line argument (argv.c)
{
    int sumdigit = 0;
    int val;
    if (argc == 2)
    {
        //printf("Success\n");
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                sumdigit += 1;
            }
        }
        if (sumdigit == strlen(argv[1]))
        {
            val = atoi(argv[1]); //Converted string into integers & val is the "key"

            //Ask user to input plaintext then convert to ciphertext 
            string plain = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int j = 0, m = strlen(plain); j < m; j++) //Iterate through the string
            {
                if (isalpha(plain[j]) && isupper(plain[j])) //if %c is alpha & upper
                {
                    printf("%c", (((plain[j] - 65) + val) % 26) + 65);
                } 
                else if (isalpha(plain[j]) && islower(plain[j]))
                {
                    printf("%c", (((plain[j] - 97) + val) % 26) + 97); //if %c is alpha & upper
                } 
                else 
                {
                    printf("%c", plain[j]); //if %c is not alpha, print as it is
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    } 
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}