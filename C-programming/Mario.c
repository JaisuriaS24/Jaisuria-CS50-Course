#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x; //Assigned int variable as x
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8); //the height should not be greater than 8 or lesser than 1

    for (int i = 0; i < x; i++)
    {
        for (int j = x - 1; j > i; j--) // j is a variable assigned for row
        {
            //if (i + j >= x - 1) {
            printf(" ");
        }
        for (int k = -1; k < i; k++)
        {
            printf("#"); //conditional statement is used to assign the "#"" and "space" variable
        }
        printf("\n");
    }
}