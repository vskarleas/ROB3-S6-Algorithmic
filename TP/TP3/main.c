#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "stdbool.h"
#include "exo2.h"
#include "exo3.h"
#include "utile.h"

void test_exo_2(int N, int step, int Fmax)
{
	int i, n;
	float mean1, mean2, mean3;
	clock_t temps_initial;
	clock_t temps_final;
	FILE *fichier = NULL;

	fichier = fopen("exo2.txt", "w");
	int nbIterations = 20;
	if (fichier != NULL)
	{

		// ONLY FOR INDIVIDUAL TESTING
		/*
		int deb[] = {1, 3, 0, 5, 8, 5};
		int fin[] = {2, 4, 6, 7, 9, 9};

		tri_taches_exo2(deb, fin, 6);

		int length = sizeof(deb) / sizeof(deb[0]);

		int maxTaches = calcule_OPT(deb, fin, length - 1);
		printf("Nombre maximum de tâches compatibles : %d\n", maxTaches);
		*/

		for (n = step; n < N; n += step)
		{
			fprintf(fichier, "%d\t", n);
			int debut[n];
			int fin[n];
			bool tacheSelected[n];

			mean1 = 0;
			mean2 = 0;
			mean3 = 0;

			for (i = 0; i < nbIterations; i++)
			{

				generate_instances(debut, fin, n, Fmax);

				tri_taches_exo2(debut, fin, n); // on the aleartory case here we need to tri beforehand

				temps_initial = clock();
				calcule_OPT(debut, fin, n);
				temps_final = clock();
				mean1 = mean1 + (temps_final - temps_initial) / (float)nbIterations;

				temps_initial = clock();
				calcule_OPT_glouton(debut, fin, n);
				temps_final = clock();
				mean2 = mean2 + (temps_final - temps_initial) / (float)nbIterations;

				temps_initial = clock();
				calcule_OPT_glouton2(debut, fin, n, tacheSelected);
				temps_final = clock();
				mean3 = mean3 + (temps_final - temps_initial) / (float)nbIterations;
			}
			fprintf(fichier, "%f\t %f\t %f\n", mean1, mean2, mean3);
		}
	}
	fclose(fichier);
}

void test_exo_3(int N, int step, int Fmax)
{
	int i, n;
	float mean1;
	clock_t temps_initial;
	clock_t temps_final;
	FILE *fichier = NULL;

	fichier = fopen("exo3.txt", "w");
	int nbIterations = 20;
	if (fichier != NULL)
	{

		// ONLY FOR INDIVIDUAL TESTING
		/*
		int deb[] = {1, 3, 0, 5, 8, 5};
		int fin[] = {2, 4, 6, 7, 9, 9};

		tri_taches_exo3(deb, fin, 6);
		int length = sizeof(deb) / sizeof(deb[0]);

		int minMachines = glouton(deb, fin, length);
		printf("Servers needed : %d\n", minMachines);
		*/

		for (n = step; n < N; n += step)
		{
			fprintf(fichier, "%d\t", n);
			int debut[n];
			int fin[n];

			mean1 = 0;

			for (i = 0; i < nbIterations; i++)
			{

				generate_instances(debut, fin, n, Fmax);

				tri_taches_exo3(debut, fin, n); // on the aleartory case here we need to tri beforehand

				temps_initial = clock();
				glouton(debut, fin, n);
				temps_final = clock();
				mean1 = mean1 + (temps_final - temps_initial) / (float)nbIterations;
			}
			fprintf(fichier, "%f\n", mean1);
		}
	}
	fclose(fichier);
}

void test_exo_3_2()
{
	//============ Example 1 ==============
	int deb1[] = {1, 2, 4, 6, 8};
	int fin1[] = {3, 5, 7, 9, 10};

	int length, nb_servers, depth;

	length = sizeof(deb1) / sizeof(deb1[0]);

    depth = get_profondeur(deb1, fin1, length);
	nb_servers = glouton(deb1, fin1, length);
    printf("Depth : %d\n", depth);
	printf("Servers needed : %d\n", nb_servers);


	//============ Example 2 ==============
	int deb2[] = {1, 3, 0, 5, 8, 5};
	int fin2[] = {2, 4, 6, 7, 9, 9};

	length = sizeof(deb2) / sizeof(deb2[0]);

	depth = get_profondeur(deb2, fin2, length);
	nb_servers = glouton(deb2, fin2, length);
    printf("\n=============\nDepth : %d\n", depth);
	printf("Servers needed : %d\n", nb_servers);
}

int main()
{
	int N = 110;
	int step = 10;

	/* Used only on Case 1 */
	int n = 10;
	int d[n], f[n];

	int Fmax = 100;
	FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
	FILE *gnuplotPipe2 = popen("gnuplot -persistent", "w");

	init_nb_aleatoire();
	int main_choice = menu_mode();

	switch (main_choice)
	{
	case 1:

		generate_instances(d, f, n, Fmax);

		// Affichage des tâches
		printf("Taches générées :\n");
		for (int i = 0; i < n; i++)
		{
			printf("Tache %d : Debut = %d, Fin = %d\n", i, d[i], f[i]);
		}

		break;

	case 2:
		test_exo_2(N, step, Fmax);
		char *commandsForGnuplot2[] = {"set title \"Exo 2 - Algos Gloutoniens\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 3 lt 1 linecolor rgb 'green' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo2.txt' using 1:2 ls 1 title 'Algo 1' w lp", "replot 'exo2.txt' using 1:3 ls 2 title 'Algo 2' w lp"};
		for (int i = 0; i < 6; i++)
		{
			fprintf(gnuplotPipe, "%s \n", commandsForGnuplot2[i]); // Send commands to gnuplot one by one.
		}

		char *commandsForGnuplot22[] = {"set title \"Exo 2 - Algos Gloutoniens\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 3 lt 1 linecolor rgb 'green' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'green' lw 2 pt 1", "plot 'exo2.txt' using 1:3 ls 1 title 'Algo 2' w lp", "replot 'exo2.txt' using 1:4 ls 2 title 'Algo 3' w lp"};
		for (int i = 0; i < 6; i++)
		{
			fprintf(gnuplotPipe2, "%s \n", commandsForGnuplot22[i]); // Send commands to gnuplot one by one.
		}
		break;

	case 3:
		test_exo_3(N, step, Fmax);
		char *commandsForGnuplot[] = {"set title \"Exo 3 - Algos Gloutoniens\"", "set style line 1 lt 1 linecolor rgb 'magenta' lw 2 pt 1", "set style line 3 lt 1 linecolor rgb 'green' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'exo3.txt' using 1:2 ls 1 title 'Algo 1' w lp"};
		for (int i = 0; i < 5; i++)
		{
			fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
		}
		break;

	case 4:
		test_exo_3_2();
		break;

	default:
		printf("An error occured\n");
		exit(1);
		break;
	}
	return 0;
}
