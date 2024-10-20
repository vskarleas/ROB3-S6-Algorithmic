#ifndef H_MEDIAN
#define H_MEDIAN

void fusion(int *tab, int deb1, int fin1, int deb2, int fin2);

void tri_fusion_bis(int *tab, int deb, int fin);

void tri_fusion(int *tab, int n);

void median(int *tab, int n);

int pivot_division(int *tab, int start, int finish);

int smallest_k(int *tab, int start, int finish, int k);

void median_2(int *tab, int n);

#endif