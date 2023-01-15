#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int startPopulation;
    int endPopulation;

    do
    {
        startPopulation = get_int("Population's start: ");
        if(startPopulation < 9)
        {
            printf("Type a number greater than 9\n");
        }
    }
    while(startPopulation < 9);

    do
    {
        endPopulation = get_int("Population's end: ");
        if(endPopulation < startPopulation)
        {
            printf("Type a number greater than population start\n");
        }
    }
    while(endPopulation < startPopulation);

    int years = 0;
    int population = startPopulation;

    for(int i = 0; population < endPopulation; i++)
    {
        population = population + (population / 3) - (population / 4);
        years++;
    }

    printf("years: %i\n", years);
};