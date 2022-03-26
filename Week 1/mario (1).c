#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user to key in height within 1 to 8 inclusively
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    
    //Parent loop
    for (int i = 0; i < n; i++)
    
    {
        //left aligned pyramind (empty space)
        {
            for (int j = n - 1; j > i; j--)
            {
                printf(" ");
            }
        }    
        
        //left aligned pyramid (#)
        {
            for (int k = -1; k < i; k++)
            {
                printf("#");
            }
        }
        
        //middle 2 empty slots (empty space)
        {
            printf("  ");
        }
        
        //right aligned pyramid (#)
        {
            for (int m = -1 ; m < i; m++)
            {
                printf("#");
            }
        }
        
        printf("\n");  
    }
}