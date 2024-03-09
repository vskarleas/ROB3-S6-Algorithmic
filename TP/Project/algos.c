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
            if (tab[j] == WHITE) // we check the previous combination [I AM NOT SURE FOR THE SECOND CONDITION TO BE] && T(j - seq[l - 1] - 1, l - 1, tab, seq)
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

// bool colorier(int *line, int line_length, int *seq, int seq_length)
// {
//     // 1. Divisez la ligne en segments en fonction des cases blanches connues.
//     int **segments = (int **)malloc(seq_length * sizeof(int *));
//     int *segment_lengths = (int *)malloc(seq_length * sizeof(int));
//     int segments_count = 0;
//     int segment_start = 0;

//     // Initialiser le premier segment
//     segments[segments_count] = &line[0];

//     for (int i = 0; i < line_length; ++i)
//     {
//         if (line[i] == WHITE && i != segment_start)
//         {
//             // Fin d'un segment noir
//             segment_lengths[segments_count] = i - segment_start;
//             segments_count++;
//             segment_start = i + 1;

//             // Commencer un nouveau segment après le blanc
//             if (segments_count < seq_length)
//             {
//                 segments[segments_count] = &line[segment_start];
//             }
//         }
//     }

//     // Fin du dernier segment
//     if (segment_start < line_length)
//     {
//         segment_lengths[segments_count] = line_length - segment_start;
//         segments_count++;
//     }

//     // 2. Résolvez chaque segment indépendamment.
//     for (int i = 0; i < segments_count; ++i)
//     {
//         if (!resolve_segment(segments[i], segment_lengths[i], seq, seq_length))
//         {
//             // Libérer les ressources allouées
//             free(segment_lengths);
//             free(segments);
//             return false;
//         }
//     }

//     // 3. Fusionnez les résultats des segments.
//     bool success = merge_segments(line, line_length, segments, segment_lengths, segments_count);

//     // Libérer les ressources allouées
//     free(segment_lengths);
//     free(segments);

//     return success;
// }

bool color_local(int *tab, int *seq, int length, int seq_length)
{
    int seqIndex = 0; // Index dans la séquence
    int blockLength;  // Longueur du bloc courant dans la séquence

    for (int i = 0; i < length; i++)
    {
        if (seqIndex < seq_length)
        {
            blockLength = seq[seqIndex];

            // Déterminez si l'espace actuel peut contenir le bloc courant
            int spaceLength = 0;
            int j = i;
            while (j < length && (tab[j] == DEFAULT || tab[j] == BLACK) && spaceLength < blockLength)
            {
                spaceLength++;
                j++;
            }

            if (spaceLength == blockLength)
            {
                // Coloriez le bloc en noir si l'espace est exact
                for (int k = i; k < i + blockLength; k++)
                {
                    tab[k] = BLACK;
                }

                // Mettre à jour l'index pour le prochain bloc et l'index de la ligne
                seqIndex++;
                i += blockLength - 1; // -1 car la boucle for va incrémenter i

                // Ajouter un espace blanc après le bloc si possible
                if (i < length - 1)
                {
                    tab[i + 1] = WHITE;
                }
            }
        }
    }

    // Retourner true si tous les blocs de la séquence ont été traités
    return seqIndex == seq_length;
}

/* Checks if a line or column can be colorised and proceeds to the appropriate action (colorisation or not)  */
bool color_decision(int *tab, int *seq, int length, int seq_length)
{
    int l = correct_length(seq);
    color_local(tab, seq, length, seq_length); // Partial colorisation of the line or column in question

    // returns false if it's impossible to color this line otherwise it returns true
    if (T(length - 1, l, tab, seq) == true)
    {
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


// Function to check if the line/column is colored correctly based on the sequence
bool is_valid(int *tab, int *seq, int length, int seq_length)
{
    int seq_index = 0;
    int block_length;

    for (int i = 0; i < length; i++)
    {
        if (seq_index < seq_length)
        {
            block_length = seq[seq_index];

            // Check if there's enough space for the current block
            if (i + block_length > length)
            {
                return false;
            }

            int black_count = 0;
            for (int j = i; j < i + block_length; j++)
            {
                if (tab[j] == BLACK)
                {
                    black_count++;
                }
                else if (tab[j] != WHITE)
                {
                    return false;
                }
            }

            if (black_count != block_length)
            {
                return false;
            }

            // Check for mandatory white space after the block
            if (i + block_length < length && tab[i + block_length] != WHITE)
            {
                return false;
            }

            seq_index++;
            i += block_length - 1; // Adjust for loop increment
        }
    }

    // Check if all blocks in the sequence are colored
    return seq_index == seq_length;
}

// Function to isolate a line from the grid
void isolate_line(int **grid, int row, int n_columns, int *line)
{
    for (int col = 0; col < n_columns; col++)
    {
        line[col] = grid[row][col];
    }
}

// Function to insert a colored line back into the grid
void insert_line(int **grid, int row, int n_columns, int *line)
{
    for (int col = 0; col < n_columns; col++)
    {
        grid[row][col] = line[col];
    }
}

// Function to isolate a column from the grid
void isolate_column(int **grid, int col, int n_rows, int *column)
{
    for (int row = 0; row < n_rows; row++)
    {
        column[row] = grid[row][col];
    }
}

// Function to insert a colored column back into the grid
void insert_column(int **grid, int col, int n_rows, int *column)
{
    for (int row = 0; row < n_rows; row++)
    {
        // Access the grid element using the correct row and column indices
        grid[row][col] = column[row];
    }
}

// Function to color a line/column recursively
bool color_grid_element(int **grid, int n_rows, int n_columns, int **rows, int **columns, int row, int col)
{
    int *element;
    int element_length;

    if (row < n_rows)
    {
        element = malloc(n_columns * sizeof(int));
        element_length = n_columns;
        isolate_line(grid, row, n_columns, element);
    }
    else
    {
        element = malloc(n_rows * sizeof(int));
        element_length = n_rows;
        isolate_column(grid, col - n_rows, n_rows, element);
    }

    if (color_decision(element, (row < n_rows) ? rows[row] : columns[col - n_rows], element_length, (row < n_rows) ? n_columns : n_rows))
    {
        if (row < n_rows)
        {
            insert_line(grid, row, n_columns, element);
        }
        else
        {
            insert_column(grid, col - n_rows, n_rows, element);
        }

        // Check next line/column recursively
        if (row < n_rows)
        {
            if (color_grid_element(grid, n_rows, n_columns, rows, columns, row + 1, col))
            {
                free(element);
                return true;
            }
        }
    }
    else
    { // Backtrack if coloring fails
        if (row < n_rows)
        {
            // Try different coloring possibilities for the line (if any)
            // ... (implementation for backtracking on lines)
        }
        else
        {
            // Try different coloring possibilities for the column (if any)
            // ... (implementation for backtracking on columns)
        }
    }
    free(element);
    return false;
}

// Function to color the entire grid
bool color_grid(int **grid, int n_rows, int n_columns, int **rows, int **columns)
{
    return color_grid_element(grid, n_rows, n_columns, rows, columns, 0, 0);
}

/* Coloeing the grid and making decisions */
// enum State color_grid(int **main_grid, int n_rows, int n_columns, int **rows, int **columns, int max_rows, int max_columns)
// {
//     bool response;

//     int **grid;
//     grid = malloc(n_rows * sizeof(int *));
//     if (columns == NULL)
//     {
//         allocation_error_print_general("grid");
//     }

//     for (int i = 0; i < n_rows; i++)
//     {
//         grid[i] = malloc(n_columns * sizeof(int));
//         if (grid[i] == NULL)
//         {
//             allocation_error_print_with_id("grid row", i);
//         }
//     }

//     copy_grid(main_grid, grid, n_rows, n_columns);

//     bool lines_to_see[n_rows];
//     init_to_see(lines_to_see, n_rows);
//     bool columns_to_see[n_columns];
//     init_to_see(columns_to_see, n_columns);

//     while (to_see_is_not_empty(lines_to_see, n_rows) || to_see_is_not_empty(columns_to_see, n_columns))
//     {
//         // TO BE VERFIED WITH EXACT ANNEXE'S ALGORITHM
//         for (int i = 0; i < n_rows; i++)
//         {

//             // Analysis of the line in question
//             int *tab;
//             tab = malloc(n_columns * sizeof(int)); // The number of columns is the length of the line in question
//             if (tab == NULL)
//             {
//                 fprintf(stderr, "\nFailed to allocate memory for tab.\n");
//                 exit(-1);
//             }

//             line_isolation(grid, i, n_columns, tab);
//             response = color_decision(tab, rows[i], n_columns, max_columns); // we take the ieme table of seqeunces for the ieme line in the analysis process

//             if (response == false)
//             {
//                 return FAIL;
//             }

//             line_to_grid(grid, i, tab, n_columns);
//             free(tab);

//             // setting that the current line was treated
//             lines_to_see[i] = false;
//         }
//         for (int i = 0; i < n_columns; i++)
//         {
//             // Analysis of the line in question
//             int *tab;
//             tab = malloc(n_rows * sizeof(int)); // The number of rows is the length of the column in question
//             if (tab == NULL)
//             {
//                 fprintf(stderr, "\nFailed to allocate memory for tab.\n");
//                 exit(-1);
//             }

//             column_isolation(grid, i, n_rows, tab);
//             response = color_decision(tab, columns[i], n_rows, max_rows);

//             if (response == false)
//             {
//                 return FAIL;
//             }

//             column_to_grid(grid, i, tab, n_rows);
//             free(tab);

//             // setting that the current column was treated
//             columns_to_see[i] = false;
//         }
//     }
//     copy_grid(grid, main_grid, n_rows, n_columns); // Copying the final result back to the main grid
//     if (grid_in_color(grid, n_rows, n_columns) == true)
//     {
//         return SUCCESS;
//     }
//     else
//     {
//         return NO_DECISION;
//     }
// }