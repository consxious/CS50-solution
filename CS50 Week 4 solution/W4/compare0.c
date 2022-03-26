// Compares two integers

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int i = get_int ("i: ");
    int j = get_int ("j: ");

    // Compare two integers
    if (i == j)
    {
        printf("Same.\n");
    }
    else
    {
        printf("Different.\n");
    }
}