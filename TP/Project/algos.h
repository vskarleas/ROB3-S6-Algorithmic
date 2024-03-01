#ifndef H_ALGOS
#define H_ALGOS

/* It verifies the decisions regarding a line according to its sequence and the rules of the puzzle */
bool verify(int tab[], int seq[], int j, int l);

/* updates the states of the cells in a specific line to white, black, or default (could mean undefinied or not treated yet) */
void colorize(int l, int j, int *tab, int *seq);

#endif