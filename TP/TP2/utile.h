#ifndef H_UTIL
#define H_UTIL

void affiche_tab(int *tab, int n, int mode, char *methode);

void init_nb_aleatoire();

int nb_random(int min, int max);

void init_tab(int* tab, int n, int Bmin, int Bmax);

void clearScreen();

int menu_mode();

void get_max(int *tab, int n, int *max);

void swap(int *a, int *b);

#endif