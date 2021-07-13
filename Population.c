#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size (9 = Minimum population size))

    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size ()

    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold/At the end of the program is should include the number of years required)

    int years = 0;
    while (end > start)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i/n", years);
}
