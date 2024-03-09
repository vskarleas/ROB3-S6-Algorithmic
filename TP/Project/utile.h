// #############################################################################
// # File utile.h
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#ifndef H_UTIL
#define H_UTIL

/* Printing the different arrays for testing purposes */
void print_table(int *tab, int n);

void table_content(int *tab, int n);

/* Initialiazing everything to DEFAULT (nothing) */
void initialize1D(int *tab, int n);

/* Gives a user the choice of the exercise */
int menu_mode();

/* Initialiazing everything on a 2D table to DEFAULT (nothing) */
void initialize2D(int **table, int rows, int cols);

/* Returns the max of two numbers */
int max(int x, int y);

/* Saving the nb of lines, columsn as well as the maximum length of a sequence of a line and a sequence of a collumn */
void decode_file(char *filename, int *n_rows, int *n_cols, int *max_rows, int *max_cols);

/* Caracter to int */
int ctoi(int c);

/* Reverses an array of numbers */
void reverse(int l, int h, int *arr);

/* Decoding an instance's file content */
void read_file(char *filename, int **lines, int **columns, int n_rows, int n_cols, int max_lines, int max_columns);

/* Printing error message for allocating memory with corresponding general */
void allocation_error_print_general(char reference[512]);

/* Printing error message for allocating memory with corresponding ID */
void allocation_error_print_with_id(char reference[512], int i);

/* Simple printing function for visualisations puproses */
void printing_grid(int **grid, int lines, int columns, int mode);

/* Copying date from gridA to gridB */
void copy_grid(int **grid, int **final, int rows, int columns);

/* Copying date from tabA to tabB */
void copy_tab(int *grid, int *final, int length);

/* Initializing the LignesAVoir abd the ColonnesAVoir tables */
void init_to_see(bool *tab, int n);

/* Isolating a specific line from the grid */
void line_isolation(int **grid, int line_id, int length, int *returned);

/* Values from a seperate table (represents a line) are copied to the 2D grid */
void line_to_grid(int **grid, int line_id, int *line, int length);

/* Values from a seperate table (represents a column here) are copied to the 2D grid */
void column_to_grid(int **grid, int column_id, int *column, int length);

/* Isolating a specific column from the grid */
void column_isolation(int **grid, int column_id, int length, int *returned);

void print_line(int *tab, int n);

#endif
