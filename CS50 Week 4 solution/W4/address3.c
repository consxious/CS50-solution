// Stores and prints an integers via its address

#include <stdio.h>

int main (void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
}