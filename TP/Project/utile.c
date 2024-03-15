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
void print_table(int *tab, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (tab[i] == BLACK)
        {
            printf("\e[1;30m#\e[0m | ");
        }
        else if (tab[i] == WHITE)
        {
            printf("\e[1;37m#\e[0m | ");
        }
        else if (tab[i] == DEFAULT) // default case
        {
            printf("? | ");
        }
    }
    if (tab[n - 1] == BLACK)
    {
        printf("\e[1;30m#\e[0m ");
    }
    else if (tab[n - 1] == WHITE)
    {
        printf("\e[1;37m#\e[0m ");
    }
    else if (tab[i] == DEFAULT) // default case
    {
        printf("? ");
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
    char *msg[1] = {"Choose an option (1.2, 1.3, 3). Your choice: "};
    char *msg_attention[1] = {"You can only choose from 1.2 or 1.3, 3."};

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
        else if (strcmp(userInput, "3") == 0)
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

/* Returns the max of two numbers */
int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

/* Saving the nb of lines, columsn as well as the maximum length of a sequence of a line and a sequence of a collumn */
void decode_file(char *filename, int *n_rows, int *n_cols, int *max_rows, int *max_cols)
{
    FILE *file = fopen(filename, "r");
    char ch;
    int temp = 0;

    // Verification
    if (file == NULL)
    {
        printf("There was an error opening the file!\n");
        return;
    }

    // Initialisations
    *n_rows = 0;
    *max_cols = 0;
    *max_rows = 0;
    *n_cols = 0;

    // Analyzing
    ch = fgetc(file);
    if (ch != '\n' && ch != '\r' && ch != ' ')
    {
        temp++;
    }
    while (ch != EOF)
    {
        // Check for new line and increment count
        if (ch == '\n')
        {
            *max_rows = max(*max_rows, temp);
            temp = 0;
            (*n_rows)++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
        if (ch != '\n' && ch != '\r' && ch != ' ')
        {
            temp++;
        }
    }

    temp = 0;

    ch = fgetc(file);
    if (ch != '\n' && ch != '\r' && ch != ' ')
    {
        temp++;
    }
    while (ch != EOF)
    {
        // Check for new line and increment count
        if (ch == '\n')
        {
            *max_cols = max(*max_cols, temp);
            temp = 0;
            (*n_cols)++;
        }

        // Read the next character
        ch = fgetc(file);
        if (ch != '\n' && ch != '\r' && ch != ' ')
        {
            temp++;
        }
    }

    fclose(file);
}

/* Caracter to int */
int ctoi(int c)
{
    return c - '0';
}

/* Reverses an array of numbers */
void reverse(int l, int h, int *arr)
{
    if (l >= h)
    {
        return;
    }
    int temp;
    temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
    reverse(l + 1, h - 1, arr); // recursive call
}

/* Decoding an instance's file content */
void read_file(char *filename, int **lines, int **columns, int n_rows, int n_cols, int max_lines, int max_columns)
{
    FILE *file = fopen(filename, "r");
    char ch;

    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    int id = 0;
    int local = 0;

    ch = fgetc(file);
    while (ch != EOF)
    {
        if (ch != '\n' && ch != '\r' && ch != ' ' && ch != '#')
        {
            lines[id][local] = ctoi(ch);
            local++;
        }

        // Check for new line and increment count
        if (ch == '\n')
        {
            if (local < max_lines)
            {
                for (int i = local; i < max_lines; i++)
                {
                    lines[id][i] = 0;
                }
            }
            local = 0;
            // reverse(0, max_lines-1, lines[id]);
            id++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }

    id = 0;
    local = 0;

    ch = fgetc(file);
    while (ch != EOF)
    {
        if (ch != '\n' && ch != '\r' && ch != ' ' && ch != '#')
        {
            columns[id][local] = ctoi(ch);
            local++;
        }

        // Check for new line and increment count
        if (ch == '\n')
        {
            if (local < max_columns)
            {
                for (int i = local; i < max_columns; i++)
                {
                    columns[id][i] = 0;
                }
            }
            local = 0;
            // reverse(0, max_lines-1, lines[id]);
            id++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }
}

/* Same as read_file but we set the sequences length to be the same for columsn and lines' sequences */
void read_file_v2(char *filename, int **lines, int **columns, int n_rows, int n_cols, int maximum)
{
    FILE *file = fopen(filename, "r");
    char ch;

    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    int id = 0;
    int local = 0;

    ch = fgetc(file);
    while (ch != EOF)
    {
        if (ch != '\n' && ch != '\r' && ch != ' ' && ch != '#')
        {
            lines[id][local] = ctoi(ch);
            local++;
        }

        // Check for new line and increment count
        if (ch == '\n')
        {
            if (local < maximum)
            {
                for (int i = local; i < maximum; i++)
                {
                    lines[id][i] = 0;
                }
            }
            local = 0;
            // reverse(0, max_lines-1, lines[id]);
            id++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }

    id = 0;
    local = 0;

    ch = fgetc(file);
    while (ch != EOF)
    {
        if (ch != '\n' && ch != '\r' && ch != ' ' && ch != '#')
        {
            columns[id][local] = ctoi(ch);
            local++;
        }

        // Check for new line and increment count
        if (ch == '\n')
        {
            if (local < maximum)
            {
                for (int i = local; i < maximum; i++)
                {
                    columns[id][i] = 0;
                }
            }
            local = 0;
            // reverse(0, max_lines-1, lines[id]);
            id++;
        }

        // Check for '#' at the beginning of a line
        if (ch == '#' && fgetc(file) == '\n')
        {
            break;
        }

        // Read the next character
        ch = fgetc(file);
    }
}

/* Printing error message for allocating memory with corresponding general */
void allocation_error_print_general(char reference[512])
{
    fprintf(stderr, "Failed to allocate memory for %s.\n", reference);
    exit(-1);
}

/* Printing error message for allocating memory with corresponding ID */
void allocation_error_print_with_id(char reference[512], int i)
{
    fprintf(stderr, "Failed to allocate memory for %s %d.\n", reference, i);
    exit(-1);
}

/* Simple printing function for visualisations puproses */
void printing_grid(int **grid, int lines, int columns, int mode)
{
    if (mode == 1)
    {
        for (int i = 0; i < lines; i++)
        {
            for (int j = 0; j < columns - 1; j++)
            {
                printf("%d | ", grid[i][j]);
            }
            printf("%d \n", grid[i][columns - 1]);
        }
    }
    else if (mode == 2)
    {
        for (int i = 0; i < lines; i++)
        {
            print_table(grid[i], columns);
            printf("\n");
        }
    }
    else
    {
        printf("\nAn error occured!\n");
    }
}


/* Copying date from gridA to gridB (1D)*/
void copy_grid_1d(int *grid, int *final, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        final[i] = grid[i];
    }
}

/* Copying date from gridA to gridB */
void copy_grid(int **grid, int **final, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            final[i][j] = grid[i][j];
        }
    }
}

/* Initializing the LignesAVoir abd the ColonnesAVoir tables */
void init_to_see(bool *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = true;
    }
}

/* Isolating a specific line from the grid */
void line_isolation(int **grid, int line_id, int length, int *returned)
{
    for (int i = 0; i < length; i++)
    {
        returned[i] = grid[line_id][i];
    }
}

/* Values from a seperate table (represents a line) are copied to the 2D grid */
void line_to_grid(int **grid, int line_id, int *line, int length)
{
    for (int i = 0; i < length; i++)
    {
        grid[line_id][i] = line[i];
    }
}

/* Values from a seperate table (represents a column here) are copied to the 2D grid */
void column_to_grid(int **grid, int column_id, int *column, int length)
{
    for (int i = 0; i < length; i++)
    {
        grid[i][column_id] = column[i];
    }
}

/* Isolating a specific column from the grid */
void column_isolation(int **grid, int column_id, int length, int *returned)
{
    for (int i = 0; i < length; i++)
    {
        returned[i] = grid[i][column_id];
    }
}

/* Concatenate two strings */
char *concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

/* For debugging purposes */
void print_line(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/* Freeing a 2D array */
void free_2d(int **table, int n)
{
    for (int i = 0; i < n; i++)
        free(table[i]);
    free(table);
}