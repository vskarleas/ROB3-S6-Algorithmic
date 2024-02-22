#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "stdbool.h"
#include "utile.h"
#include "exo2.h"
#include "exo3.h"

void test_exo_2(int N,int step, int Fmax){
	int i,n; float mean1; float mean2;
	clock_t temps_initial; 
	clock_t temps_final; 
	FILE* fichier = NULL;

	//srand(time(NULL));  //WHY TWO TIMES ?
	fichier = fopen("exo2.txt", "w");
	int nbIterations = 20;
	if (fichier != NULL)
	{
		for(n = step;n < N; n+=step){
			fprintf(fichier, "%d\t", n);
			int debut [n]; int fin [n];
			mean1 = 0;
			mean2 = 0;

			for(i = 0;i <nbIterations; i++){
				
				generate_instances(debut, fin, n, Fmax);	
				printf("%d\n", i);
				temps_initial = clock();
				calcule_OPT(debut, fin, n);
				temps_final = clock();
				mean1 = mean1 + (temps_final - temps_initial)/(float)nbIterations;

				temps_initial = clock();
				calcule_OPT_glouton(debut, fin, n);
				temps_final = clock();
				mean2 = mean2 + (temps_final - temps_initial)/(float)nbIterations;

			}
			fprintf(fichier, "%f\t %f\n", mean1,mean2);
		}
	}
	fclose(fichier); 
}

void test_exo_3(int N,int step, int Fmax){
//TODO
}

int main(){
  int N = 200; int step = 20; int Fmax=100;
  init_nb_aleatoire();
  test_exo_2(N,step,Fmax);
  //test_exo_3(N,step,Fmax);
return 0;
}
