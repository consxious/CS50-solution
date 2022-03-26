#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int count = 1;

int main(int argc, string argv[])  //Command-line argument 
{
    int sumalpha = 0;
    if (argc == 2) //Check for 1 command-line argument
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++) //Check all character for alpha
        {  
            if (isalpha(argv[1][i]))
            {
                sumalpha += 1;
            }
        }
        for (int j = 0, n = strlen(argv[1]); j < n; j++) //Check no repeated character (case insensitive)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (tolower(argv[1][j]) == tolower(argv[1][k]))
                {
                    count++;
                }
            }
        }
        if (strlen(argv[1]) != 26) //condition 1: Must be 26 characters
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (sumalpha != strlen(argv[1])) //condition 2: Must be all alphabetic characters
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else if (count != 1)
        {
            printf("Key must not contain repeated characters.\n"); //condition 3: Must not contained repeated character
            return 1;
        } 
        else
        {
            //Ask user to input plaintext
            string plain = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int w = 0, x = strlen(plain); w < x; w++)
            {
                if (isalpha(plain[w]) && isupper(plain[w])) //if %c is alpha & upper
                {
                    int upper = (plain[w] - 65);
                    printf("%c", toupper(argv[1][upper]));
                } 
                else if (isalpha(plain[w]) && islower(plain[w])) //if %c is alpha & lower
                {
                    int lower = (plain[w] - 97);
                    printf("%c", tolower(argv[1][lower])); 
                } 
                else 
                {
                    printf("%c", plain[w]); //if %c is not alpha, print as it is
                }
            }
            printf("\n");
            return 0;
        } 
    } 
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}