#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utile.h"
#include "minmax.h"
#include "maxsubarray.h"

void test_exo_1(int N,int step, int Bmin, int Bmax){
  int i,n; float mean; int min; int max;
  clock_t temps_initial; clock_t temps_final; FILE* fichier = NULL;
  srand(time(NULL));
  fichier = fopen("exo1.txt", "w");
  if (fichier != NULL)
    {
      for(n = step;n < N; n+=step){
        fprintf(fichier, "%d\t", n);
	int tab [n];        
	mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin, Bmax);
          temps_initial = clock();
          get_min_max_1(tab, n, &min, &max);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\t", mean);
        mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin,Bmax);
          temps_initial = clock();
          get_min_max_2(tab, n, &min, &max);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\n", mean);
      }
    }
  fclose(fichier); 
}

void test_exo_2(int N,int step, int Bmin, int Bmax){
  int i,n; float mean;
  clock_t temps_initial; clock_t temps_final; FILE* fichier = NULL;
  srand(time(NULL));
  fichier = fopen("exo2.txt", "w");
  if (fichier != NULL)
    {
      for(n = step;n < N; n+=step){
        fprintf(fichier, "%d\t", n);
  	int tab [n];
        mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin, Bmax);	
          temps_initial = clock();
          maxSubArraySum1(tab, n);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\t", mean);
        
	mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin,Bmax);
          temps_initial = clock();
          maxSubArraySum2(tab, n);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\t", mean);
	
	mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin,Bmax);
          temps_initial = clock();
          maxSubArraySum3(tab, n);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\t", mean);
	
	mean =0;
        for(i = 0;i <20; i++){
          init_tab(tab, n, Bmin,Bmax);
          temps_initial = clock();
          maxSubArraySum4(tab, n);
          temps_final = clock();
          mean = mean + 1./(i+1)*(temps_final - temps_initial);
        }
        fprintf(fichier, "%f\n", mean);
      }
    }
  fclose(fichier); 

}


int main(){
  int N = 10000; int step = 100; int Bmin=10; int Bmax=100;
  srand(time(NULL));
  test_exo_1(N,step,Bmin,Bmax);
  test_exo_2(N,step,Bmin,Bmax);
return 0;
}
