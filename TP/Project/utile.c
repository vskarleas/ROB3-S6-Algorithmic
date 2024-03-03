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
#include "constants.h"

/* Printing the different arrays for testing purposes */
void print_table(int *tab, int n, int mode)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (tab[i] == BLACK)
        {
            printf(" \e[1;30m#\e[0m |");
        }
        else if (tab[i] == WHITE)
        {
            printf(" \e[1;37m#\e[0m |");
        }
        else if (tab[i] == DEFAULT) // default case
        {
            printf(" ? |");
        }
    }
    if (tab[n - 1] == BLACK)
    {
        printf(" \e[1;30m#\e[0m ");
    }
    else if (tab[n - 1] == WHITE)
    {
        printf(" \e[1;37m#\e[0m ");
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

void table_content(int *tab, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf(" %d |", tab[i]);
    }
    printf(" %d ", tab[n - 1]);
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
    char *msg[1] = {"Choose an option (1.2, 1.3). Your choice: "};
    char *msg_attention[1] = {"You can only choose from 1.2 or 1.3."};

    while (true)
    {
        printf("\n%s ", msg[0]);
        scanf("%s", userInput);

        // Convert input to lowercase for case-insensitive comparison and returns
        for (int i = 0; i < strlen(userInput); i++)
        {
            userInput[i] = tolower(userInput[i]);
        }

        if (strcmp(userInput, "lalala") == 0)
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

/* Decoding an instance's file content */
void read_file(char *filename, int **lines, int **columns, int *n_rows, int *n_cols)
{
    FILE *file = fopen(filename, "r");
    char ch;

    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    *n_rows = 0; // how many lines exists for the puzzle ?

    ch = fgetc(file);
    while (ch != EOF)
    {
        // Check for new line and increment count
        if (ch == '\n')
        {
            (*n_rows)++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }

    *lines = malloc(*n_rows * sizeof(int));

    rewind(file);
    for (int i = 0; i < *n_rows; i++)
    {
        fscanf(file, "%d ", &(*lines)[i]); // Read sequence for each row
    }

    fscanf(file, "#\n"); // Read the delimiter

    *n_cols = 0;
    ch = fgetc(file);
    while (ch != EOF)
    {
        // Check for new line and increment count
        if (ch == '\n')
        {
            (*n_cols)++;
        }

        // Read the next character
        ch = fgetc(file);
    }

    (*n_cols) = (*n_cols) - 1;

    *columns = malloc(*n_cols * sizeof(int));
    rewind(file);

    int temp=0;
    ch = fgetc(file);
    while (ch != EOF)
    {
        // Check for new line and increment count
        if (ch == '\n')
        {
            temp++;
        }

        if (temp == *n_rows + 1)
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }
    

    for (int i = 0; i < *n_cols; i++)
    {
        fscanf(file, "%d ", &(*columns)[i]);
    }

    fclose(file);
}
