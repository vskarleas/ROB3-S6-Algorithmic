#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "utile.h"

int main(int argc, char **argv)
{
    init_nb_aleatoire();

    int algo_choice = menu_mode();

    switch (algo_choice)
    {
    case 1:
        clearScreen();
        printf("Exercise 1:\n\n");

    case 2:
        clearScreen();
        printf("Exercise 2:\n\n");

    case 3:
        clearScreen();
        printf("Exercise 3:\n\n");

    case 4:
        clearScreen();
        printf("Exercise 4:\n\n");

    case 5:
        clearScreen();
        printf("Exercise 5:\n\n");

    case 6:
        clearScreen();
        printf("Exercise 6:\n\n");

    default:
        printf("\n\n=====================================================\nProgram has been terminared\n\n");
    }

    return 0;
}
