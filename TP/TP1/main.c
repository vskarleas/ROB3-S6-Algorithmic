#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "utile.h"

int main(int argc, char **argv)
{
    init_nb_aleatoire();
    clearScreen();
    int bmin =0;
    int bmax = 10;
    // TO BE UPDATED OR REMOVED
    //printf("\nPlease enter the minimum for the random generator: ");
    //scanf("%d", &bmin);
    //printf("Now the maximum for the random generator: ");
    //scanf("%d", &bmax);
    //clearScreen();
    int algo_choice = menu_mode();
    clearScreen();
    int length;

    // Loop until a valid number is entered
    do
    {
        printf("\nPlease enter the desired length for the array that is at least 1 or bigger: ");
        scanf("%d", &length);

        // Check if the input is valid
        if (length < 1)
        {
            clearScreen();
            printf("\nError: The number must be at least 1.\n");
        }
    } while (length < 1);

    int *tab;
    tab = malloc(length * sizeof(int));
    if (tab == NULL)
    {
        clearScreen();
        fprintf(stderr, "\nFailed to allocate memory for tab.\n");
        exit(-1);
    }
    clearScreen();

    switch (algo_choice)
    {
    case 1:
        printf("\nExercise 1:\n");
        init_tab(tab, length, bmin, bmax);
        affiche_tab(tab, length, 1, ""); // one here for message "generated". Otherwise it prints "treated"

        break;

    case 2:
        printf("\nExercise 2:\n");
        init_tab(tab, length, bmin, bmax);
        affiche_tab(tab, length, 1, "");
        tri_ins(tab, length);
        affiche_tab(tab, length, 0, "INSERTION Sort");

        break;

    case 3:
        printf("\nExercise 3:\n");
        init_tab(tab, length, bmin, bmax);
        affiche_tab(tab, length, 1, "");
        tri_fusion(tab, length);
        affiche_tab(tab, length, 0, "FUSION Sort");

        break;

    case 4:
        printf("\nExercise 4:\n");
        init_tab(tab, length, bmin, bmax);
        affiche_tab(tab, length, 1, "");
        tri_enum(tab, length);
        affiche_tab(tab, length, 0, "ENUMARATION Sort");

        break;

    case 5:
        printf("\nExercise 5:\n");

        break;

    case 6:
        printf("\nExercise 6:\n");

        break;

    default:
        printf("\n\n=====================================================\nProgram has been terminared\n\n");
        break;
    }

    return 0;
}
