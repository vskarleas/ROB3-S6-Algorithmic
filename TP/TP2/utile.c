#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utile.h"

void affiche_tab(int* tab, int n){
  int i;
  for(i = 0; i < n; ++i){
    printf("%d\t",tab[i]);
    }
  printf("\n");
}

void init_tab(int* tab, int n, int Bmin, int Bmax){
  int i;
  for(i=0; i<n; ++i){
      tab[i] = rand()%(Bmax-Bmin) + Bmin;
    }
}