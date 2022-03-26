// Capitalize a copy of a string using strcpy

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    // Get a string
    char *s = get_string("s: ");

    // Allocate memory for new string
    char *t = malloc((strlen(s)) + 1);

    // Strcpy to copy to new string
    strcpy (t,s);

    // Capitalize new string
    t[0] = toupper(t[0]);

    // Print both strings
    // new string is a copy of s
    // Capitalize t does not effect s
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}