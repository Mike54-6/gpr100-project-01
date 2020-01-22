// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "GPRO-FW/foo.h"



int main()
{
	int test = foo(9000);

	printf("\n %d \n", test);

    int num = 0;
    int guess = 0;
    int tries = 0;

    srand(time(0));
    num = rand() % 100 + 1;

    do
    {
        printf("Enter a guess between 1 and 100 : ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
        {
            printf("Your guess was too high, try again.\n\n");
        }
        else if (guess < num)
        {
            printf("Your guess was too low, try again.\n\n");
        }
        else
        {
            printf("Correct! You got it in %d guesses!\n", tries);
        }

    } while (guess != num);

    return 0;
}
