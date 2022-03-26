// Capitalize a copy of a string without memory errors

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    // Get a string with memory checking
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    // Allocation memory for new string with memory checking
    char *t = malloc ((strlen(s)) + 1);
    if (t == NULL)
    {
        return 1;
    }

    // Copy string to new string
    strcpy (t,s);

    // If there is any failure copy to new string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print both strings
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // Free memory for t
    // get_string will auto malloc & free memory
    free(t);
    return 0;
}