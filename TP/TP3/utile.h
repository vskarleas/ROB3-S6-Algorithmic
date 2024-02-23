#ifndef H_UTIL
#define H_UTIL

void affiche_tab(int *tab, int n, int mode, char *methode);

void init_nb_aleatoire();

int nb_random(int min, int max);

void generate_instances(int *debut, int *fin, int n, int Fmax);

int menu_mode();

int max(int x, int y);

#endif