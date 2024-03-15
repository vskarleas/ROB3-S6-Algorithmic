// #############################################################################
// # File algos.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "utile.h"
#include "constants.h"
#include "algos.h"

bool is_subset(int *arr1, int *arr2, int m, int n)
{

    // Check if the second array (n) is larger than the first (m)
    if (n > m)
    {
        return false; // By definition, a subset cannot be larger than the set
    }

    int *duplicate;
    duplicate = malloc(m * sizeof(int *));
    if (duplicate == NULL)
    {
        allocation_error_print_general("duplicate");
    }

    // Making a local copy to return back after analysis is completed
    copy_grid_1d(arr1, duplicate, m);

    // Changing temporarily everything to black fro default cells
    for (int i = 0; i < m; i++)
    {
        if (arr1[i] == DEFAULT)
        {
            arr1[i] = BLACK;
        }
    }

    //print_line(arr1, m);

    if (n > m)
    {
        return 0; // Subarray cannot be larger than main array
    }

    for (int i = 0; i <= m - n; i++)
    {
        int j;
        for (j = 0; j < n; j++)
        {
            if (arr1[i + j] != arr2[j])
            {
                break; // Elements don't match, move to next starting point
            }
        }
        if (j == n)
        { // All elements matched, subarray found
            copy_grid_1d(duplicate, arr1, m);
            free(duplicate);
            return true;
        }
    }

    copy_grid_1d(duplicate, arr1, m);
    free(duplicate);
    return false; // Subarray not found
}

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool T(int j, int l, int *tab, int *seq, int total_length)
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
            if (tab[j] == WHITE) // we check the previous combination [I AM NOT SURE FOR THE SECOND CONDITION TO BE] && T(j - seq[l - 1] - 1, l - 1, tab, seq)
            {
                return (T(j - 1, l, tab, seq, total_length));
            }
            else
            {
                // Check whether an array is subset of another array
                int *temp = (int *)malloc(seq[l - 1] * sizeof(int));
                if (temp == NULL)
                {
                    fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                    exit(-1);
                }

                // Initialization of the array
                for (int i = 0; i < seq[l - 1]; i++)
                {
                    temp[i] = BLACK;
                }

                // int index = j;
                // int counter = 0;

                // for (int i = 0; i < seq[l - 1]; i++)
                // {
                //     if (tab[index] == BLACK || tab[index] == DEFAULT)
                //     {
                //         counter++;
                //     }
                // }

                // if (counter == seq[l-1])
                // {
                //     return true;
                // }
                // else
                // {
                //     T(j - 1, l, tab, seq, total_length);
                // }

                //print_line(temp, seq[l - 1]);

                int m = total_length;
                int n = seq[l - 1];

                if (is_subset(tab, temp, m, n))
                {
                    return true;
                }
                else
                {
                    return (T(j - 1, l, tab, seq, total_length));
                }
                free(temp);
            }
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

// TO BE CORRECTED IN ORDER TO BE CAPABLE TO TREAT THE CORRECT COLORISATION PROCESS FOR 0.txt
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
int correct_length(int *seq, int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (seq[i] != 0)
        {
            count++;
        }
    }
    return count;
}

/* Checks if a line or column can be colorised and proceeds to the appropriate action (colorisation or not)  */
bool color_decision(int *tab, int *seq, int length, int maximum)
{
    int l = correct_length(seq, maximum);
    // returns false if it's impossible to color this line otherwise it returns true
    if (T(length - 1, l, tab, seq, length) == true)
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

/* Counts how many cells exist on the grid that are not colourised yet */
int grid_defaults_count(int **grid, int rows, int columns)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] == DEFAULT)
            {
                count++;
            }
        }
    }

    return count;
}

/* Coloring the grid - DOESN'T WORK */
enum State color_grid_v1(int **main_grid, int n_rows, int n_columns, int **rows, int **columns, int maximum)
{
    bool response;

    int **grid;
    grid = malloc(n_rows * sizeof(int *));
    if (grid == NULL)
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
        // TO BE VERFIED WITH EXACT ANNEXE'S ALGORITHM
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
            response = color_decision(tab, rows[i], n_columns, maximum); // we take the ieme table of seqeunces for the ieme line in the analysis process

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
            response = color_decision(tab, columns[i], n_rows, maximum);

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
    copy_grid(grid, main_grid, n_rows, n_columns); // Copying the final result back to the main grid
    if (grid_in_color(grid, n_rows, n_columns) == true)
    {
        return SUCCESS;
    }
    else
    {
        return NO_DECISION;
    }
}

/* Finding the next not-colorised cell */
void recalculation(int **grid, int rows, int columns, int *i, int *j)
{
    int x = 0;
    int y = 0;

    while (x < rows && (*i) == -1)
    {
        for (y = 0; y < columns; y++)
        {
            if (grid[x][y] == DEFAULT)
            {
                (*i) = x;
                (*j) = y;
                break;
            }
        }
        x++;
    }
}

/* Coloring the grid (partially) and making decisions */
enum State color_grid_v2(int **grid, int n_rows, int n_columns, int **rows_columns, int maximum)
{

    for (int x = 0; x < n_rows; x++)
    {
        for (int y = 0; y < n_columns; y++)
        {
            /* If no color is aplied yet to the specific cell */
            if (grid[x][y] == DEFAULT)
            {
                int l;
                bool white_test, black_test;

                // ==========================
                // Local test for white state
                // ==========================
                grid[x][y] = WHITE;

                // Analysis of the line in question (in parallel of every column)
                int *tab = (int *)malloc(n_rows * sizeof(int)); // The number of rows is the length of the column in question
                if (tab == NULL)
                {
                    fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                    exit(-1);
                }

                column_isolation(grid, y, n_rows, tab);

                /* HORIZONTAL test */
                l = correct_length(rows_columns[x], maximum);
                white_test = T(n_columns - 1, l, grid[x], rows_columns[x], n_columns);

                /* VERTICAL test */
                if (white_test)
                {
                    l = correct_length(rows_columns[n_rows + y], maximum);                // updating l value
                    white_test = T(n_rows - 1, l, tab, rows_columns[n_rows + y], n_rows); // we need + 1 because y counts from 0, so in order to take the correct sequence for the column, we need n_rows + 0 + 1 to be distinguised
                }

                // ==========================
                // Local test for black state
                // ==========================
                grid[x][y] = BLACK;
                tab[x] = BLACK; // This step is essential. Previsouly the colourisation in white happened before isolation. Here we have to do it manually because we have already isolated the column

                /* HORIZONTAL test */
                l = correct_length(rows_columns[x], maximum);
                black_test = T(n_columns - 1, l, grid[x], rows_columns[x], n_columns);

                /* VERTICAL test */
                if (black_test)
                {
                    l = correct_length(rows_columns[n_rows + y], maximum);                // updating l value
                    black_test = T(n_rows - 1, l, tab, rows_columns[n_rows + y], n_rows); // we need + 1 because y counts from 0, so in order to take the correct sequence for the column, we need n_rows + 0 + 1 to be distinguised
                }

                free(tab);

                // ==========================
                // Reversing any changes
                // ==========================
                grid[x][y] = DEFAULT;
                tab[x] = DEFAULT;

                // ==========================
                // Decisions and conclusions
                // ==========================
                if (white_test == false)
                {
                    if (black_test == false)
                    {
                        return FAIL;
                    }
                    else
                    {
                        grid[x][y] = BLACK;
                    }
                }
                else if (black_test == false)
                {
                    if (white_test == true)
                    {
                        grid[x][y] = WHITE;
                    }
                    else
                    {
                        return NO_DECISION;
                    }
                }
            }
        }
    }
    return SUCCESS;
}

/* Completing the colorisation process with recursion */
int color_grid_complet(int **grid, int **rows_columns, int n_rows, int n_columns, int i, int j, int maximum)
{
    /* Making a temporary copy of the grid for returning_back porpuses */
    int **duplicate;
    duplicate = malloc(n_rows * sizeof(int *));
    if (duplicate == NULL)
    {
        allocation_error_print_general("duplicate");
    }

    for (int i = 0; i < n_rows; i++)
    {
        duplicate[i] = malloc(n_columns * sizeof(int));
        if (duplicate[i] == NULL)
        {
            allocation_error_print_with_id("duplicate row", i);
        }
    }

    copy_grid(grid, duplicate, n_rows, n_columns);

    // ==========================
    // White test
    // ==========================
    grid[i][j] = WHITE;
    if (color_grid_v3(grid, n_rows, n_columns, rows_columns, maximum) == SUCCESS)
    {
        free_2d(duplicate, n_rows);
        return 1;
    }
    copy_grid(duplicate, grid, n_rows, n_columns); // going back to previous state

    // ==========================
    // Black test
    // ==========================
    grid[i][j] = BLACK;
    if (color_grid_v3(grid, n_rows, n_columns, rows_columns, maximum) == SUCCESS)
    {
        free_2d(duplicate, n_rows);
        return 1;
    }
    copy_grid(duplicate, grid, n_rows, n_columns); // going back to previous state

    // Otherwise
    free_2d(duplicate, n_rows);
    return 0;
}

/* Final version that colourises and calls recursivly in order to examine all the possible cases */
/* NOTA BENE: Same logic with v2 but more elaborated */
enum State color_grid_v3(int **grid, int n_rows, int n_columns, int **rows_columns, int maximum)
{

    enum State result;
    result = SUCCESS;                        // status by default. It will be updated accordingly
    int last_time = 1, before_last_time = 1; // indicators of our not-colourised cells in the puzzle grid in two different times. last_empty happened before after_last_empty in a chronological sequence

    while (last_time > 0 && result == SUCCESS)
    {
        for (int x = 0; x < n_rows; x++)
        {
            for (int y = 0; y < n_columns; y++)
            {
                /* If no color is aplied yet to the specific cell */
                if (grid[x][y] == DEFAULT)
                {
                    int l;
                    bool white_test, black_test;

                    // ==========================
                    // Local test for white state
                    // ==========================
                    grid[x][y] = WHITE;

                    // Analysis of the line in question (in parallel of every column)
                    int *tab = (int *)malloc(n_rows * sizeof(int)); // The number of rows is the length of the column in question
                    if (tab == NULL)
                    {
                        fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                        exit(-1);
                    }

                    column_isolation(grid, y, n_rows, tab);

                    /* HORIZONTAL test */
                    l = correct_length(rows_columns[x], maximum);
                    white_test = T(n_columns - 1, l, grid[x], rows_columns[x], n_columns);

                    /* VERTICAL test */
                    if (white_test)
                    {
                        l = correct_length(rows_columns[n_rows + y], maximum);                // updating l value
                        white_test = T(n_rows - 1, l, tab, rows_columns[n_rows + y], n_rows); // we need + 1 because y counts from 0, so in order to take the correct sequence for the column, we need n_rows + 0 + 1 to be distinguised
                    }

                    // ==========================
                    // Local test for black state
                    // ==========================
                    grid[x][y] = BLACK;
                    tab[x] = BLACK; // This step is essential. Previsouly the colourisation in white happened before isolation. Here we have to do it manually because we have already isolated the column

                    /* HORIZONTAL test */
                    l = correct_length(rows_columns[x], maximum);
                    black_test = T(n_columns - 1, l, grid[x], rows_columns[x], n_columns); // we need + 1 because x counts from 0, so in

                    /* VERTICAL test */
                    if (black_test)
                    {
                        l = correct_length(rows_columns[n_rows + y], maximum);                // updating l value
                        black_test = T(n_rows - 1, l, tab, rows_columns[n_rows + y], n_rows); // we need + 1 because y counts from 0, so in order to take the correct sequence for the column, we need n_rows + 0 + 1 to be distinguised
                    }

                    free(tab);

                    // ==========================
                    // Reversing any changes
                    // ==========================
                    grid[x][y] = DEFAULT;
                    tab[x] = DEFAULT;

                    // ==========================
                    // Decisions and conclusions
                    // ==========================
                    if (white_test == false)
                    {
                        if (black_test == false)
                        {
                            return FAIL;
                        }
                        else
                        {
                            grid[x][y] = BLACK;
                        }
                    }
                    else if (black_test == false)
                    {
                        if (white_test == true)
                        {
                            grid[x][y] = WHITE;
                        }
                        else
                        {
                            return NO_DECISION;
                        }
                    }

                    printing_grid(grid, n_rows, n_columns, 2);
                    printf("\n\n");
                }
            }
        }

        int changes = grid_defaults_count(grid, n_rows, n_columns);

        if (changes == last_time && changes == before_last_time)
        {
            /* It means that there was no change during the last 2 itterations
            of the boucle while, so we need to recalculate  */

            int x_updated = -1;
            int y_updated;
            recalculation(grid, n_rows, n_columns, &x_updated, &y_updated);

            if (color_grid_complet(grid, rows_columns, n_rows, n_columns, x_updated, y_updated, maximum) == 1)
            {
                return SUCCESS;
            }
            result = NO_DECISION; // in order to terminate the while
        }
        before_last_time = last_time;
        last_time = changes;
    }

    if (grid_in_color(grid, n_rows, n_columns))
    {
        return SUCCESS;
    }
    else
    {
        return NO_DECISION;
    }

    // return result;
}