#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "utile.h"
#include "minmax.h"
#include "maxsubarray.h"
#include "median.h"

void test_exo_1(int N, int step, int Bmin, int Bmax)
{
  printf("\n In progess...\n");
  int i, n;
  float mean;
  int min;
  int max;
  clock_t temps_initial;
  clock_t temps_final;
  FILE *fichier = NULL;
  srand(time(NULL));
  fichier = fopen("exo1.txt", "w");
  if (fichier != NULL)
  {
    for (n = step; n < N; n += step)
    {
      fprintf(fichier, "%d\t", n);
      int *tab;
      tab = malloc(n * sizeof(int));

      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        temps_initial = clock();
        get_min_max_1(tab, n, &min, &max);
        temps_final = clock();
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\t", mean);
      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        temps_initial = clock();
        get_min_max_2(tab, n, &min, &max);
        temps_final = clock();
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\n", mean);

      free(tab);
    }
  }
  fclose(fichier);
}

void test_exo_2(int N, int step, int Bmin, int Bmax)
{
  printf("\n In progess...\n");
  int i, n;
  float mean;
  clock_t temps_initial;
  clock_t temps_final;
  FILE *fichier = NULL;
  srand(time(NULL));
  fichier = fopen("exo2.txt", "w");
  if (fichier != NULL)
  {
    for (n = step; n < N; n += step)
    {
      fprintf(fichier, "%d\t", n);
      int tab[n];
      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        temps_initial = clock();
        maxSubArraySum1(tab, n);
        temps_final = clock();
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\t", mean);

      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        temps_initial = clock();
        maxSubArraySum2(tab, n);
        temps_final = clock();
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\n", mean); // TO BE REPLACED FROM \n to \t

      /*
        mean = 0;
        for (i = 0; i < 20; i++)
        {
          init_tab(tab, n, Bmin, Bmax);
          temps_initial = clock();
          maxSubArraySum3(tab, n);
          temps_final = clock();
          mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
        }
        fprintf(fichier, "%f\t", mean);

        mean = 0;
        for (i = 0; i < 20; i++)
        {
          init_tab(tab, n, Bmin, Bmax);
          temps_initial = clock();
          maxSubArraySum4(tab, n);
          temps_final = clock();
          mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
        }
        fprintf(fichier, "%f\n", mean);
        */
    }
  }
  fclose(fichier);
}

void test_exo_3(int N, int step, int Bmin, int Bmax)
{
  printf("\n In progess...\n");
  int i, n;
  float mean;
  clock_t temps_initial;
  clock_t temps_final;
  FILE *fichier = NULL;
  srand(time(NULL));
  fichier = fopen("exo3.txt", "w");
  if (fichier != NULL)
  {
    for (n = step; n < N; n += step)
    {
      fprintf(fichier, "%d\t", n);
      int *tab;
      tab = malloc(n * sizeof(int));

      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        affiche_tab(tab, n, 1, "");
        temps_initial = clock();
        median(tab, n);
        temps_final = clock();
        affiche_tab(tab, n, 2, "Fusion");
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\t", mean);

      mean = 0;
      for (i = 0; i < 20; i++)
      {
        init_tab(tab, n, Bmin, Bmax);
        temps_initial = clock();
        median_2(tab, n);
        temps_final = clock();
        mean = mean + 1. / (i + 1) * (temps_final - temps_initial);
      }
      fprintf(fichier, "%f\n", mean); // TO BE REPLACED FROM \n to \t

      free(tab);
    }
  }
  fclose(fichier);
}

int main()
{
  init_nb_aleatoire();
  clearScreen();
  int main_choice = menu_mode();

  int N;
  int step = 100;
  int Bmin = 10;
  int Bmax = 100;
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  FILE *gnuplotPipe2 = popen("gnuplot -persistent", "w");

  switch (main_choice)
  {
  case 1:
    N = 10000;
    test_exo_1(N, step, Bmin, Bmax);
    clearScreen();
    char *commandsForGnuplot1[] = {"set title \"Min-and-Max Algorithms Comprison\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo1.txt' using 1:2 ls 2 title 'Algo 1' w lp", "replot 'exo1.txt' using 1:3 ls 1 title 'Algo 2' w lp"};
    // We are not printing 'data_insertion-sort_all.temp' using 1:2 ls 1 title 'one' with lines, \ because we can't see the differences of others on scale
    for (int i = 0; i < 5; i++)
    {
      fprintf(gnuplotPipe, "%s \n", commandsForGnuplot1[i]); // Send commands to gnuplot one by one.
    }
    printf("\n================================================\nProcess completed\n================================\n");
    break;

  case 2:
    N = 1000;
    test_exo_2(N, step, Bmin, Bmax);
    clearScreen();
    printf("\nWe have removed the MaxSubArray1 algo result from the graph because it was impossible to see what was going on with the other algorithms. However you can always use gnuplot command and plot the 1st and 2nd column of the exo2.txt file\n\n");
    char *commandsForGnuplot2[] = {"set title \"MaxSubArray Algorithms Comprison\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo2.txt' using 1:3 ls 1 title 'Algo 2' w lp"};
    // We are not printing 'data_insertion-sort_all.temp' using 1:2 ls 1 title 'one' with lines, \ because we can't see the differences of others on scale
    for (int i = 0; i < 4; i++)
    {
      fprintf(gnuplotPipe, "%s \n", commandsForGnuplot2[i]); // Send commands to gnuplot one by one.
    }

    char *commandsForGnuplot22[] = {"set title \"MaxSubArray Algo 1 Comprison\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo2.txt' using 1:2 ls 2 title 'Algo 1' w lp"};
    for (int i = 0; i < 4; i++)
    {
      fprintf(gnuplotPipe2, "%s \n", commandsForGnuplot22[i]); // Send commands to gnuplot one by one.
    }
    printf("\n================================================\nProcess completed\n================================\n");
    break;
    break;

  case 3:
    N = 10000;
    test_exo_3(N, step, Bmin, Bmax);
    clearScreen();
    char *commandsForGnuplot3[] = {"set title \"Median Algo 1\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo3.txt' using 1:2 ls 2 title 'Algo 1' w lp", "replot 'exo3.txt' using 1:3 ls 1 title 'Algo 2' w lp"};
    for (int i = 0; i < 5; i++)
    {
      fprintf(gnuplotPipe, "%s \n", commandsForGnuplot3[i]); // Send commands to gnuplot one by one.
    }
    break;

  default:
    fprintf(stderr, "An error occured!\n");
    exit(-2);
  }

  return 0;
}
