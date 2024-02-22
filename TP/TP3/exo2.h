#ifndef H_EXO2
#define H_EXO2

void tri_taches_exo2(int* deb, int* fin, int nbTaches);

bool is_compatible(int i, int j, int* debut, int* fin);

int calcule_OPT(int* deb, int* fin, int nbTaches);

int calcule_OPT_glouton(int* deb, int* fin, int nbTaches);

void calcule_OPT_glouton2(int* deb, int* fin, int nbTaches, bool* tacheSelected);

#endif
