#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "utile.h"

#define NUM_POINTS 14
#define NUM_COMMANDS 3
#define NUM_COMMANDS_ALL 5

int main(int argc, char **argv)
{
    init_nb_aleatoire();
    clearScreen();
    int bmin, bmax, length;
    printf("\nPlease enter the minimum for the random generator: ");
    scanf("%d", &bmin);
    printf("Now the maximum for the random generator: ");
    scanf("%d", &bmax);
    clearScreen();
    int main_choice = main_menu();
    clock_t temps_initial;                                                                   /* Temps initial en micro-secondes */
    clock_t temps_final;                                                                     /* Temps final en micro-secondes */
    float temps_cpu_exo2, temps_cpu_exo3, temps_cpu_exo4, temps_cpu_exo5, temps_cpu_exo4_v2; /* Temps total en secondes */
    char *msg[6] = {"Exercise 1 - Table initailisation", "Exercise 2 - Insertion Sort", "Exercise 3 - Fusion Sort", "Exercise 4 - Enumeration Sort", "Exercise 5 - Base (randix) Sort", "Exercise 4-V2 (with get_min_max) - Enumeration Sort"};
    FILE *temp = fopen("all-sortings.temp", "w");

    if (main_choice == 1)
    {
        int algo_choice = menu_mode();
        clearScreen();
        printf("\n%s\n", msg[algo_choice - 1]);

        for (length = 50; length < 150000; length += 2000) // creates the points automatically
        {
            int *tab;
            tab = malloc(length * sizeof(int));
            if (tab == NULL)
            {
                clearScreen();
                fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                exit(-1);
            }

            if (algo_choice != 1)
            {
                init_tab(tab, length, bmin, bmax);
            }

            switch (algo_choice)
            {
            case 1:
                init_tab(tab, length, bmin, bmax);
                affiche_tab(tab, length, 1, ""); // one here for message "generated". Otherwise it prints "treated"

                break;

            case 2:
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 1, "");
                }
                temps_initial = clock();

                tri_ins(tab, length);

                temps_final = clock();
                temps_cpu_exo2 = (temps_final - temps_initial) * 1e-6;

                printf("\n\e[0;36m%d items OK\e[0m\n", length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "INSERTION Sort");
                }
                printf("%d %f ", length, temps_cpu_exo2);
                printf("\n================================================================\n");

                break;

            case 3:
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 1, "");
                }

                temps_initial = clock();
                tri_fusion(tab, length);
                temps_final = clock();
                temps_cpu_exo3 = (temps_final - temps_initial) * 1e-6;

                printf("\n\e[0;36m%d items OK\e[0m\n", length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "FUSION Sort");
                }
                printf("%d %f ", length, temps_cpu_exo3);
                printf("\n================================================================\n");

                break;

            case 4:
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 1, "");
                }

                temps_initial = clock();
                tri_enum(tab, length);
                temps_final = clock();

                temps_cpu_exo4 = (temps_final - temps_initial) * 1e-6;

                printf("\n\e[0;36m%d items OK\e[0m\n", length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "ENUMARATION Sort");
                }
                printf("%d %f ", length, temps_cpu_exo4);
                printf("\n================================================================\n");

                break;

            case 5:
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 1, "");
                }

                temps_initial = clock();
                tri_base(tab, length);
                temps_final = clock();
                temps_cpu_exo5 = (temps_final - temps_initial) * 1e-6;

                printf("\n\e[0;36m%d items OK\e[0m\n", length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "BASE Sort");
                }
                printf("%d %f ", length, temps_cpu_exo5);
                printf("\n================================================================\n");

                break;

            case 6:
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 1, "");
                }

                temps_initial = clock();
                tri_enum_v2(tab, length);
                temps_final = clock();
                temps_cpu_exo4_v2 = (temps_final - temps_initial) * 1e-6;

                printf("\n\e[0;36m%d items OK\e[0m\n", length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "ENUMARATION Sort V2");
                }
                printf("%d %f ", length, temps_cpu_exo4_v2);
                printf("\n================================================================\n");

                break;

            default:
                printf("\n\n=====================================================\nProgram has been terminared\n\n");
                break;
            }

            free(tab);
        }

        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

        if (algo_choice == 1)
        {
            printf("Gnuplot is not supported for this section of code\n");
            exit(-1);
        }
        else if (algo_choice == 2)
        {
            char *commandsForGnuplot[] = {"set title \"INSERTION Sort\"", "set style line 1 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'data_insertion-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_insertion-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6d %.6f \n", length, temps_cpu_exo2); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 3)
        {
            char *commandsForGnuplot[] = {"set title \"FUSION Sort\"", "set style line 1 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'data_fusion-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_fusion-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6d %.6f \n", length, temps_cpu_exo3); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 4)
        {
            char *commandsForGnuplot[] = {"set title \"ENUMERATION Sort\"", "set style line 1 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'data_enumeration-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_enumeration-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6d %.6f \n", length, temps_cpu_exo4); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 5)
        {
            char *commandsForGnuplot[] = {"set title \"BASE Sort\"", "set style line 1 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'data_base-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_base-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6d %.6f \n", length, temps_cpu_exo5); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 6)
        {
            char *commandsForGnuplot[] = {"set title \"ENUMERATION Sort V2\"", "set style line 1 lt 1 linecolor rgb 'blue' lw 2 pt 1", "plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_enumerationV2-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6d %.6f \n", length, temps_cpu_exo4_v2); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else
        {
            printf("\n\nAn error occured!\n");
            exit(-2);
        }
    }
    else if (main_choice == 2)
    {
        int index=1;
        for (int length = 500; length < 150000; length += 2000) // creates the points automatically
        {
            printf("\n================================================================");
            printf("\n========================= Process No %d ========================", index);
            printf("\n================================================================\n");
            printf("\n\e[0;36mFor %d numbers\e[0m\n", length);
            int *tab_all;
            tab_all = malloc(length * sizeof(int));
            if (tab_all == NULL)
            {
                clearScreen();
                fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                exit(-1);
            }

            init_tab(tab_all, length, bmin, bmax);

            printf("\n\e[0;33m************** Fusion **********\e[0m");
            temps_initial = clock();
            tri_fusion(tab_all, length);
            temps_final = clock();
            temps_cpu_exo3 = (temps_final - temps_initial) * 1e-6;
            printf("%d %f ", length, temps_cpu_exo5);
            printf("\n================================================================\n");

            printf("\n\e[0;33m***************** Enum *********\e[0m");
            temps_initial = clock();
            tri_enum(tab_all, length);
            temps_final = clock();
            temps_cpu_exo4 = (temps_final - temps_initial) * 1e-6;
            printf("%d %f ", length, temps_cpu_exo4);
            printf("\n================================================================\n");

            printf("\n\e[0;33m************** Base ************\e[0m");
            temps_initial = clock();
            tri_base(tab_all, length);
            temps_final = clock();
            temps_cpu_exo5 = (temps_final - temps_initial) * 1e-6;
            printf("%d %f ", length, temps_cpu_exo5);
            printf("\n================================================================\n");

            printf("\n\e[0;33m************** Enum V2 ************\e[0m");
            temps_initial = clock();
            tri_enum_v2(tab_all, length);
            temps_final = clock();
            temps_cpu_exo4_v2 = (temps_final - temps_initial) * 1e-6;
            printf("%d %f ", length, temps_cpu_exo4_v2);
            printf("\n================================================================\n");

            index++;
            free(tab_all);

            fprintf(temp, "%.6d %.6f %.6f %.6f %.6f\n", length, temps_cpu_exo3, temps_cpu_exo4, temps_cpu_exo5, temps_cpu_exo4_v2);
        }
        char *commandsForGnuplot[] = {"set title \"Sort Algorithms\"", "plot 'all-sortings.temp' using 1:2 title 'Fusion' w lp", "replot 'all-sortings.temp' using 1:3 title 'Enumeration' w lp", "replot 'all-sortings.temp' using 1:4 title 'Base' w lp", "replot 'all-sortings.temp' using 1:5 title 'Enumeration V2' w lp"};
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

        for (int i = 0; i < NUM_COMMANDS_ALL; i++)
        {
            fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
        }
        printf("\nThe tri insertion is not included because that way we can't see the graphs of the other algorithms");
    }
    else
    {
        clearScreen();
        printf("An error occured :(");
        exit(-3);
    }

    return 0;
}
