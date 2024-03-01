#ifndef H_UTIL
#define H_UTIL

/* Printing the different arrays for testing purposes */
void print_table(int *tab, int n, int mode);

/* Initialiazing everything to DEFAULT (nothing) */
void initialize1D(int *tab, int n);

/* Gives a user the choice of the exercise */
int menu_mode();

/* Initialiazing everything on a 2D table to DEFAULT (nothing) */
void initialize2D(int **table, int rows, int cols);

#endif
