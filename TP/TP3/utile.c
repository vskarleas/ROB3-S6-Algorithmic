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

/* Starting the random engine */
void init_nb_aleatoire()
{
    srand(time(0));
}

/*Generates random numbers min and max given as arguments*/
int nb_random(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

void generate_instances(int *debut, int *fin, int n, int Fmax){
  for (int i = 0; i < n; ++i)
  {
    debut[i] = nb_random(0, Fmax); //taking any number on the intervalle
    fin[i] = debut[i] + nb_random(1, Fmax - debut[i]); //starting from the beginning of the interval we add minimum 1 up to maximum - start time (in order to remain on the Fmax limit)
  }
}



