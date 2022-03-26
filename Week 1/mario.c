#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for positive int btw 1 to 8 (inclusively)
    int n;
    do
    {
        n = get_int("Height: ");
    } 
    while (n < 1 || n > 8);
    //printf("%i\n", n);
    
    //Form left-aligned pyramid
    //Each i iteration of # then a newline
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i ; j--)
        {
            printf(" ");
        }
        for (int k = -1 ; k < i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}