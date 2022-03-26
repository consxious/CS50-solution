// Capitalize a copy of a string

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    // Get a string
    char *s = get_string("s: ");

    // Create memory for new string
    char *t = malloc((strlen(s)) + 1);

    // Copy string into the new string
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Capitalize the new string
    // Since t has its own memory space and its a copy from s, it can be capitalize without effecting s
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

}