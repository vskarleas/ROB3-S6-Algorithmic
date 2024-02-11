#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <ncurses.h>
#include "utile.h"

void affiche_tab(int *tab, int n, int mode, char *methode)
{
    if (mode == 1)
    {
        printf("\nTable generated: \n");
    }
    else
    {
        printf("\nTable after treatment with %s: \n", methode);
    }
    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf(" %d |", tab[i]);
    }
    printf(" %d \n", tab[n - 1]);
}

/* Starting the random engine */
void init_nb_aleatoire()
{
    srand(time(0));
}

/*Generates random numbers min and max given as arguments*/
int nb_random(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

void init_tab(int *tab, int n, int Bmin, int Bmax)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = nb_random(Bmin, Bmax);
    }
}

/* Clearing the terminal screen for more optimised visualisations */
void clearScreen()
{
    // const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    // write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
    printf("\e[1;1H\e[2J");
}

/* Gives a user the choice of the exercise */
int menu_mode()
{
    char userInput[20];
    char *msg[1] = {"Choose an option (Exo1, Exo2 or Exo3). Your choice: "};
    char *msg_attention[1] = {"You can only choose from Exo1, Exo2 or Exo3."};

    while (true)
    {
        printf("\n%s ", msg[0]);
        scanf("%s", userInput);

        // Convert input to lowercase for case-insensitive comparison and returns
        for (int i = 0; i < strlen(userInput); i++)
        {
            userInput[i] = tolower(userInput[i]);
        }

        if (strcmp(userInput, "exo1") == 0)
        {
            return 1;
        }
        else if (strcmp(userInput, "exo2") == 0)
        {
            return 2;
        }
        else if (strcmp(userInput, "exo3") == 0)
        {
            return 3;
        }
        else
        {
            clearScreen();
            printf("\n\033[0;33mATTENTION!\033[1;0m: %s\n", msg_attention[0]);
        }
    }
    return 0;
}

void get_max(int *tab, int n, int *max)
{
    for (int i = 0; i < n; i++)
    {
        if (tab[i] > *max)
        {
            *max = tab[i];
        }
    }
}