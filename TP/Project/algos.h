// #############################################################################
// # File algos.h
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#ifndef H_ALGOS
#define H_ALGOS

#include "constants.h"

bool is_subset(int *arr1, int *arr2, int m, int n);

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool T(int j, int l, int *tab, int *seq, int total_length);

/* Returns true if LignesAVoir or ColonnesAVoir are not emtpy yet */
bool to_see_is_not_empty(bool *table, int n);

/* Colorizes the line once it knows that it can be colourised correctly */
void color_lineORcolumn(int *line, int *seq, int length);

/* Retruns the correct length of a sequence and not the maximum one */
int correct_length(int *seq, int size);

/* Checks if a line or column can be colorised and proceeds to the appropriate action (colorisation or not)  */
bool color_decision(int *tab, int *seq, int length, int maximum);

/* Returns true if every cell of the grid is colorised */
bool grid_in_color(int **grid, int rows, int columns);

/* Counts how many cells exist on the grid that are not colourised yet */
int grid_defaults_count(int **grid, int rows, int columns);

/* Coloeing the grid and making decisions */
enum State color_grid_v1(int **main_grid, int n_rows, int n_columns, int **rows, int **columns, int maximum);

/* Finding the next not-colorised cell */
void recalculation(int **grid, int n_rows, int n_columns, int *x_updated, int *y_updated);

/* Coloring the grid and making decisions */
enum State color_grid_v2(int **grid, int n_rows, int n_columns, int **rows_columns, int maximum);

/* Completing the colorisation process with recursion */
int color_grid_complet(int **grid, int **rows_columns, int n_rows, int n_columns, int i, int j, int maximum);

/* Final version that colourises and calls recursivly in order to examine all the possible cases */
/* NOTA BENE: Same logic with v2 but more elaborated */
enum State color_grid_v3(int **grid, int n_rows, int n_columns, int **rows_columns, int maximum);

#endif