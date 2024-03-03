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
            if (tab[j] == WHITE && T(j - seq[l - 1] - 1, l - 1, tab, seq)) // we check the previous combination [I AM NOT SURE FOR THE SECOND CONDITION]
            {
                return (T(j - 1, l, tab, seq));
            }
            return (T(j - 1, l, tab, seq) || T(j - seq[l - 1] - 1, l - 1, tab, seq));
        }
    }
    return false;
}

// void color_grid(int **grid, int n_rows, int n_cols, int *lines, int *columns)
// {
//     bool changed = true;
//     while (changed)
//     {
//         changed = false;
//         for (int i = 0; i < n_rows; i++)
//         {
//             for (int j = 0; j < n_cols; j++)
//             {
//                 if ((*grid)[i * n_cols + j] == DEFAULT)
//                 { 
//                     // Teste si la case peut être blanche
//                     bool white_possible = T(j, lines[i], *grid + i * n_cols, lines);
//                     if (white_possible)
//                     {
//                         (*grid)[i * n_cols + j] = WHITE;
//                         changed = true;
//                     }
//                     // Teste si la case peut être noire
//                     bool black_possible = T(j, columns[j], *grid + j, columns);
//                     if (black_possible)
//                     {
//                         (*grid)[i * n_cols + j] = BLACK;
//                         changed = true;
//                     }
//                     // Si aucun des deux n'est possible, le puzzle n'a pas de solution
//                     if (!white_possible && !black_possible)
//                     {
//                         printf("Le puzzle n'a pas de solution\n");
//                         return;
//                     }
//                 }
//             }
//         }
//     }
// }