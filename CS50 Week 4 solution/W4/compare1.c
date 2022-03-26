// Compares two string's addresses

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    char *s = get_string ("s: ");
    char *t = get_string ("t: ");

    // Compare 2 strings addresses - Cannot be same because those are memory addresses
    // Every memory address has unique hexadecimal number
    if (s == t)
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }
}