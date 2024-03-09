// #############################################################################
// # File algos.h
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#ifndef H_ALGOS
#define H_ALGOS

#include "constants.h"

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool T(int j, int l, int *tab, int *seq);

/* Returns true if LignesAVoir or ColonnesAVoir are not emtpy yet */
bool to_see_is_not_empty(bool *table, int n);

/* Colorizes the line once it knows that it can be colourised correctly */
void color_lineORcolumn(int *line, int *seq, int length);

/* Retruns the correct length of a sequence and not the maximum one */
int correct_length(int *seq);

//bool colorier(int *line, int line_length, int *seq, int seq_length);

bool color_local(int *tab, int *seq, int length, int seq_length);

/* Checks if a line or column can be colorised and proceeds to the appropriate action (colorisation or not)  */
bool color_decision(int *tab, int *seq, int length,  int seq_length);

/* Returns true if every cell of the grid is colorised */
bool grid_in_color(int **grid, int rows, int columns);


bool is_valid(int *tab, int *seq, int length, int seq_length);

void isolate_line(int **grid, int row, int n_columns, int *line);

void insert_line(int **grid, int row, int n_columns, int *line);

void isolate_column(int **grid, int col, int n_rows, int *column);

void insert_column(int **grid, int col, int n_rows, int *column);

bool color_grid_element(int **grid, int n_rows, int n_columns, int **rows, int **columns, int row, int col);

bool color_grid(int **grid, int n_rows, int n_columns, int **rows, int **columns);



/* Coloeing the grid and making decisions */
//enum State color_grid(int **main_grid, int n_rows, int n_columns, int **rows, int **columns, int max_rows, int max_columns);

#endif