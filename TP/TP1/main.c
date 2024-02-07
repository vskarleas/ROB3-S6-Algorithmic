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
        printf("\nExercise 1:\n\n");

        break;

    case 2:
        clearScreen();
        printf("\nExercise 2:\n\n");

        break;

    case 3:
        clearScreen();
        printf("\nExercise 3:\n\n");

        break;

    case 4:
        clearScreen();
        printf("\nExercise 4:\n\n");

        break;

    case 5:
        clearScreen();
        printf("\nExercise 5:\n\n");

        break;

    case 6:
        clearScreen();
        printf("\nExercise 6:\n\n");

        break;

    default:
        printf("\n\n=====================================================\nProgram has been terminared\n\n");
        break;
    }

    return 0;
}
