// Capitalizes a string

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    // Get a string
    string s = get_string ("s: ");

    // Copy string address
    string t = s;

    // Capitalize first char of the string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print both strings
    // Both string first char capitalize due to t is only refer to s
    // Capitalize t = capitalize s
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}