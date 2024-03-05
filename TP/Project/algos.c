// #############################################################################
// # File algos.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "utile.h"
#include "constants.h"

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool T(int j, int l, int *tab, int *seq)
{
    if (l == 0)
    {
        return true;
    }
    if (l >= 1)
    {
        if (j < seq[l - 1] - 1) // please consider that is seauence seq the place at seq[0] is never used on our program. It's just initialises on a nunber that we never take into consideration
        {
            return false;
        }
        if (j == seq[l - 1] - 1)
        {
            // checking for any whites on this space
            for (int i = 0; i <= j; i++)
            {
                if (tab[i] == WHITE)
                {
                    return false;
                }
            }
            return (l == 1); // the condition that needs to be true in order for that sub case (2b) to be verfied
        }
        if (j > seq[l - 1] - 1)
        {
            // Checking if it white as mentioned on Project's subject
            if (tab[j] == WHITE && T(j - seq[l - 1] - 1, l - 1, tab, seq)) // we check the previous combination [I AM NOT SURE FOR THE SECOND CONDITION TO BE]
            {
                return (T(j - 1, l, tab, seq));
            }
            return (T(j - 1, l, tab, seq) || T(j - seq[l - 1] - 1, l - 1, tab, seq));
        }
    }
    return false;
}

/* Returns true if LignesAVoir or ColonnesAVoir are not emtpy yet */
bool to_see_is_not_empty(bool *table, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (table[i] == true)
        {
            return true;
        }
    }
    return false;
}

/* Colorizes the line once it knows that it can be colourised correctly */
void color_lineORcolumn(int *line, int *seq, int length)
{
    int k = 0;
    int current = 0;
    while (seq[k] != 0)
    {
        for (int i = 0; i < seq[k]; i++)
        {
            line[current] = BLACK;
            current++;
        }
        if (current < length)
        {
            line[current] = WHITE;
            current++;
        }
        k++;
    }
}

/* Retruns the correct length of a sequence and not the maximum one */
int correct_length(int *seq)
{
    int tmp = 0;
    for (int i = 0; i < sizeof((*seq)) / sizeof(seq[0]); i++)
    {
        if (seq[i] != 0)
        {
            tmp++;
        }
        else if (seq[i] == 0)
        {
            break;
        }
    }
    return tmp;
}

/* Checks if a line or column can be colorised and proceeds to the appropriate action (colorisation or not)  */
bool color_decision(int *tab, int *seq, int length)
{
    int l = correct_length(seq);
    // returns false if it's impossible to color this line otherwise it returns true
    if (T(length - 1, l, tab, seq) == true)
    {
        color_lineORcolumn(tab, seq, length);
        return true;
    }
    else
    {
        return false;
    }
}

/* Returns true if every cell of the grid is colorised */
bool grid_in_color(int **grid, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] == DEFAULT)
            {
                return false;
            }
        }
    }
    return true;
}

/* Coloeing the grid and making decisions */
enum State color_grid(int **main_grid, int n_rows, int n_columns, int **rows, int **columns)
{
    bool response;

    int **grid;
    grid = malloc(n_rows * sizeof(int *));
    if (columns == NULL)
    {
        allocation_error_print_general("grid");
    }

    for (int i = 0; i < n_rows; i++)
    {
        grid[i] = malloc(n_columns * sizeof(int));
        if (grid[i] == NULL)
        {
            allocation_error_print_with_id("grid row", i);
        }
    }

    copy_grid(main_grid, grid, n_rows, n_columns);

    bool lines_to_see[n_rows];
    init_to_see(lines_to_see, n_rows);
    bool columns_to_see[n_columns];
    init_to_see(columns_to_see, n_columns);

    while (to_see_is_not_empty(lines_to_see, n_rows) || to_see_is_not_empty(columns_to_see, n_columns))
    {
        for (int i = 0; i < n_rows; i++)
        {

            // Analysis of the line in question
            int *tab;
            tab = malloc(n_columns * sizeof(int)); // The number of columns is the length of the line in question
            if (tab == NULL)
            {
                fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                exit(-1);
            }

            line_isolation(grid, i, n_columns, tab);
            response = color_decision(tab, rows[i], n_columns); // we take the ieme table of seqeunces for the ieme line in the analysis process

            if (response == false)
            {
                return FAIL;
            }

            line_to_grid(grid, i, tab, n_columns);
            free(tab);

            // setting that the current line was treated
            lines_to_see[i] = false;
        }
        for (int i = 0; i < n_columns; i++)
        {
            // Analysis of the line in question
            int *tab;
            tab = malloc(n_rows * sizeof(int)); // The number of rows is the length of the column in question
            if (tab == NULL)
            {
                fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                exit(-1);
            }

            column_isolation(grid, i, n_rows, tab);
            response = color_decision(tab, columns[i], n_rows);

            if (response == false)
            {
                return FAIL;
            }

            column_to_grid(grid, i, tab, n_rows);
            free(tab);

            // setting that the current column was treated
            columns_to_see[i] = false;
        }
    }
    if (grid_in_color(grid, n_rows, n_columns) == true)
    {
        copy_grid(grid, main_grid, n_rows, n_columns); // Copying the final result back to the main grid
        return SUCCESS;
    }
    else
    {
        return NO_DECISION;
    }
}