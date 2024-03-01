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

#define WHITE 1
#define BLACK 0
#define UNKNOWN -1
#define DEFAULT -2

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool verify(int tab[], int seq[], int j, int l)
{

    if (l == 0)
    {
        return true;
    }
    else if (l >= 1)
    {
        if (j < seq[l - 1] - 1)
        { // Return false directly when j is out of bounds
            return false;
        }
        else if (j == seq[l - 1] - 1)
        {
            if (l == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else // for j > seq[l] - 1
        {
            return (verify(tab, seq, j - 1, l) || verify(tab, seq, j - seq[l - 1] - 1, l - 1));
        }
    }

    return false;
}

/* updates the states of the cells in a specific line to white, black, or default (could mean undefinied or not treated yet) */
void colorize(int l, int j, int *tab, int *seq)
{
    // verification -> meaning that we can not colourize that cell
    if (!verify(tab, seq, j, l))
    {
        if (l > 0 && j < tab[0] - seq[l - 1] - 1)
        {
            // Explicit check for gap between blocks, set cell to white
            tab[j] = WHITE;
        }
        return;
    }

    // treating the rest of the cases
    switch (l)
    {
    case 0:
        break; // No block, nothing to color
    case 1:
        for (int i = j; i >= j - seq[0] + 1; i--)
        {
            tab[i] = BLACK; // Color the block
        }
        break;
    default:
        if (j < 0)
        {
            return; // Base case for j negative
        }
        if (j == seq[l - 1] - 1)
        {
            tab[j] = BLACK; // Coloring the last cell of the block
        }
        else
        {
            colorize(l, j - 1, tab, seq);
            if (verify(tab, seq, j - seq[l - 1] - 1, l - 1))
            {
                colorize(l - 1, j - seq[l - 1] - 1, tab, seq); // Cell black and block placed
            }
            else
            {
                tab[j] = WHITE; // Explicitly set to white if the black option fails
            }
        }
    }
    return;
}