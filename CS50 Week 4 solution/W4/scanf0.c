// Gets an int from user using scanf

#include <stdio.h>

int main (void)
{
    int x;
    printf("x: ");
    // Looks like if x is large number, it will print out other values
    scanf("%i",&x);
    printf("x: %i\n",x);
}