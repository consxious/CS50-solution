#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompt user for their name (Input)
    string name = get_string("What is your name?\n");
    
    //Display hello with user name (Output)
    printf("hello, %s\n", name);
}