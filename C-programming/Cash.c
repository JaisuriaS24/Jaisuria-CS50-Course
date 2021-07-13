#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void) //float variable is defined as "coins"
{
    float coins;
    int amount = 0;
    do
    {
        coins = get_float("Change owed: ");  // change given *result*
    }  
    while (coins < 0);
    int cent = round(coins * 100);
    
    while (cent >= 25)
    {
        cent = cent - 25;
        amount++; //give the remainder after dividing by 25
    }
    while (cent >= 10)
    {
        cent = cent - 10;
        amount++; //give the remainder after dividng by 10
    }    
    while (cent >= 5)
    {
        cent = cent - 5;
        amount++; //give the remainder after dividng by 5
    }
    while (cent >= 1)
    {
        cent = cent - 1;
        amount ++; //give the remainder after dividing by 1
    }    
    printf("%i\n", amount);
}
