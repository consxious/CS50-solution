// Fails to swap 2 integers

#include <stdio.h>

// Declaration
void swap (int a, int b);

// Main function
int main (void)
{
    int x = 1;
    int y = 2;
    printf("x = %i, y = %i\n", x, y);
    swap(x,y);
    printf("x = %i, y = %i\n", x, y);
}

// Swap function
void swap (int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}