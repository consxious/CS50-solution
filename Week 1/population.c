#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // TODO: Prompt for start size (Minimum 9)

    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size (Must greater than or equal to start size)

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    while (end > start)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}