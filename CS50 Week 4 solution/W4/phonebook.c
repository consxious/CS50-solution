// Saves names and numbers to a CSV file

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    // Open a file
    FILE *file = fopen("phonebook.csv","a");
    if (!file)
    {
        return 1;
    }

    // Get name & number
    string name = get_string("name: ");
    string number = get_string("number: ");

    // Print name & number to file
    fprintf(file, "%s,%s\n", name, number);

    // Close file
    fclose(file);
}