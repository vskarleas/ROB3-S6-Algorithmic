// #############################################################################
// # File utile.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <ncurses.h>

#include "utile.h"

#define WHITE 1
#define BLACK 0
#define UNKNOWN -1
#define DEFAULT -2

/* Printing the different arrays for testing purposes */
void print_table(int *tab, int n, int mode)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (tab[i] == BLACK)
        {
            printf(" \e[1;35m#\e[0m |"); //magenta
        }
        else if (tab[i] == WHITE)
        {
            printf(" \e[1;33m#\e[0m |"); //yellow
        }
        else if (tab[i] == DEFAULT) // default case
        {
            printf(" ? |");
        }
    }
    if (tab[n - 1] == BLACK)
    {
        printf(" \e[1;35m#\e[0m ");
    }
    else if (tab[n - 1] == WHITE)
    {
        printf(" \e[1;33m#\e[0m ");
    }
    else if (tab[i] == DEFAULT) // default case
    {
        printf(" ? ");
    }
    if (mode == 1)
    {
        printf("\nI am SURE for that\n");
    }
    else if (mode == 2)
    {
        printf("\n");
    }
    else
    {
        printf("\nI am NOT SURE for that\n");
    }
}

/* Initialiazing everything to DEFAULT (nothing) */
void initialize1D(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = DEFAULT;
    }
}

/* Gives a user the choice of the exercise */
int menu_mode()
{
    char userInput[20];
    char *msg[1] = {"Choose an option (1.1, 1.2, 1.3). Your choice: "};
    char *msg_attention[1] = {"You can only choose from 1.1, 1.2 or 1.3."};

    while (true)
    {
        printf("\n%s ", msg[0]);
        scanf("%s", userInput);

        // Convert input to lowercase for case-insensitive comparison and returns
        for (int i = 0; i < strlen(userInput); i++)
        {
            userInput[i] = tolower(userInput[i]);
        }

        if (strcmp(userInput, "1.1") == 0)
        {
            return 1;
        }
        else if (strcmp(userInput, "1.2") == 0)
        {
            return 2;
        }
        else if (strcmp(userInput, "1.3") == 0)
        {
            return 3;
        }
        else if (strcmp(userInput, "exo4") == 0)
        {
            return 4;
        }
        else if (strcmp(userInput, "exo5") == 0)
        {
            return 5;
        }
        else if (strcmp(userInput, "exo4-v2") == 0)
        {
            return 6;
        }
        else
        {
            printf("\n\033[0;33mATTENTION!\033[1;0m: %s\n", msg_attention[0]);
        }
    }
    return 0;
}

/* Initialiazing everything on a 2D table to DEFAULT (nothing) */
void initialize2D(int **table, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            table[i][j] = DEFAULT;
        }
    }
}