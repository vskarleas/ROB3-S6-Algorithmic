#include <stdbool.h>

#ifndef H_EXO2
#define H_EXO2

void fusion(int *deb, int *fin, int debut, int milieu, int finTab);

void tri_fusion(int *deb, int *fin, int debut, int finTab);

void tri_taches_exo2(int* deb, int* fin, int nbTaches);

bool is_compatible(int i, int j, int* debut, int* fin);

int dernier_compatible(int j, int *deb, int *fin);

int calcule_OPT(int* deb, int* fin, int nbTaches);

int calcule_OPT_glouton(int* deb, int* fin, int nbTaches);

void calcule_OPT_glouton2(int* deb, int* fin, int nbTaches, bool* tacheSelected);

#endif
