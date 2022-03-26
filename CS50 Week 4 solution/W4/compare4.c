// Prints two strings' addresses

#include <stdio.h>
#include <cs50.h>

int main (void)
{
    char *s = get_string ("s: ");
    char *t = get_string ("t: ");

    //Prints string addresses
    printf("%p\n",s);
    printf("%p\n",t);
}