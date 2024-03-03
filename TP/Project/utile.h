// #############################################################################
// # File utile.h
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#ifndef H_UTIL
#define H_UTIL

/* Printing the different arrays for testing purposes */
void print_table(int *tab, int n, int mode);

void table_content(int *tab, int n);

/* Initialiazing everything to DEFAULT (nothing) */
void initialize1D(int *tab, int n);

/* Gives a user the choice of the exercise */
int menu_mode();

/* Initialiazing everything on a 2D table to DEFAULT (nothing) */
void initialize2D(int **table, int rows, int cols);

/* Decoding an instance's file content */
void read_file(char *filename, int **lines, int **columns, int *n_rows, int *n_cols);

#endif
