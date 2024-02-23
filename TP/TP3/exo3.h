#ifndef H_EXO3
#define H_EXO3

void fusion(int *deb, int *fin, int debut, int milieu, int finTab);

void tri_fusion(int *deb, int *fin, int debut, int finTab);

void tri_taches_exo3(int* deb, int* fin, int nbTaches);

void init_servers(int n, int *tab2);

int glouton(int* deb, int* fin, int nbTaches);

void fusion_extrem(int *tab, int debut, int milieu, int fin);

void tri_fusion_extrem(int *tab, int debut, int fin);

void tri(int* tab, int n);

int get_profondeur(int* deb, int* fin, int nbTaches);

#endif