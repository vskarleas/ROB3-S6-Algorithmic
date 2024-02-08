#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "tri.h"
#include "utile.h"

#define NUM_POINTS 14
#define NUM_COMMANDS 3
#define NUM_COMMANDS_ALL 7

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
    int lengths[NUM_POINTS] = {5, 25, 50, 100, 250, 500, 750, 1000, 10000, 35000, 50000, 80000, 120000, 150000};
    double xvals[NUM_POINTS] = {5, 25, 50, 100, 250, 500, 750, 1000, 10000, 35000, 50000, 80000, 120000, 150000};
    double yvals[NUM_POINTS];
    int index = 0;
    clock_t temps_initial; /* Temps initial en micro-secondes */
    clock_t temps_final;   /* Temps final en micro-secondes */
    float temps_cpu;       /* Temps total en secondes */
    char *msg[6] = {"Exercise 1 - Table initailisation", "Exercise 2 - Insertion Sort", "Exercise 3 - Fusion Sort", "Exercise 4 - Enumeration Sort", "Exercise 5 - Base (randix) Sort", "Exercise 4-V2 (with get_min_max) - Enumeration Sort"};

    if (main_choice == 1)
    {
        int algo_choice = menu_mode();
        clearScreen();
        printf("\n%s\n", msg[algo_choice - 1]);

        for (int i = 0; i < NUM_POINTS; i++) // creates the points automatically
        {
            length = lengths[index];
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
                temps_cpu = (temps_final - temps_initial) * 1e-6;

                yvals[index] = temps_cpu;

                printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "INSERTION Sort");
                }
                printf("%d %f ", length, temps_cpu);
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
                temps_cpu = (temps_final - temps_initial) * 1e-6;

                yvals[index] = temps_cpu;

                printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "FUSION Sort");
                }
                printf("%d %f ", length, temps_cpu);
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

                temps_cpu = (temps_final - temps_initial) * 1e-6;

                yvals[index] = temps_cpu;

                printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "ENUMARATION Sort");
                }
                printf("%d %f ", length, temps_cpu);
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
                temps_cpu = (temps_final - temps_initial) * 1e-6;

                yvals[index] = temps_cpu;

                printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "BASE Sort");
                }
                printf("%d %f ", length, temps_cpu);
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
                temps_cpu = (temps_final - temps_initial) * 1e-6;

                yvals[index] = temps_cpu;

                printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                if (length < 50 && length > 5)
                {
                    affiche_tab(tab, length, 0, "ENUMARATION Sort V2");
                }
                printf("%d %f ", length, temps_cpu);
                printf("\n================================================================\n");

                break;

            default:
                printf("\n\n=====================================================\nProgram has been terminared\n\n");
                break;
            }

            index++;
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
            char *commandsForGnuplot[] = {"set title \"INSERTION Sort\"", "set style line 1 lt 1 linecolor rgb 'green' lw 2 pt 1","plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_insertion-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 3)
        {
            char *commandsForGnuplot[] = {"set title \"FUSION Sort\"", "set style line 1 lt 1 linecolor rgb 'green' lw 2 pt 1","plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_fusion-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 4)
        {
            char *commandsForGnuplot[] = {"set title \"ENUMERATION Sort\"", "set style line 1 lt 1 linecolor rgb 'green' lw 2 pt 1","plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_enumeration-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 5)
        {
            char *commandsForGnuplot[] = {"set title \"BASE Sort\"", "set style line 1 lt 1 linecolor rgb 'green' lw 2 pt 1","plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_base-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
            }
            for (int i = 0; i < NUM_COMMANDS; i++)
            {
                fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
            }
        }
        else if (algo_choice == 6)
        {
            char *commandsForGnuplot[] = {"set title \"ENUMERATION Sort V2\"", "set style line 1 lt 1 linecolor rgb 'green' lw 2 pt 1","plot 'data_enumerationV2-sort.temp' using 1:2 ls 1 title '' with lines"};
            FILE *temp = fopen("data_enumerationV2-sort.temp", "w");
            for (int i = 0; i < NUM_POINTS; i++)
            {
                fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
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
        int algo;
        for (algo = 1; algo < 6; algo++)
        {
            printf("\n Algo %s\n", msg[algo]);
            index = 0;
            for (int i = 0; i < NUM_POINTS; i++) // creates the points automatically
            {
                length = lengths[index];
                int *tab_all;
                tab_all = malloc(length * sizeof(int));
                if (tab_all == NULL)
                {
                    clearScreen();
                    fprintf(stderr, "\nFailed to allocate memory for tab.\n");
                    exit(-1);
                }

                init_tab(tab_all, length, bmin, bmax);

                switch (algo + 1)
                {
                case 2:
                    temps_initial = clock();

                    tri_ins(tab_all, length);

                    temps_final = clock();
                    temps_cpu = (temps_final - temps_initial) * 1e-6;

                    yvals[index] = temps_cpu;

                    printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                    printf("%d %f ", length, temps_cpu);
                    printf("\n================================================================\n");

                    break;

                case 3:
                    temps_initial = clock();
                    tri_fusion(tab_all, length);
                    temps_final = clock();
                    temps_cpu = (temps_final - temps_initial) * 1e-6;

                    yvals[index] = temps_cpu;

                    printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                    printf("%d %f ", length, temps_cpu);
                    printf("\n================================================================\n");

                    break;

                case 4:
                    temps_initial = clock();
                    tri_enum(tab_all, length);
                    temps_final = clock();

                    temps_cpu = (temps_final - temps_initial) * 1e-6;

                    yvals[index] = temps_cpu;

                    printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                    printf("%d %f ", length, temps_cpu);
                    printf("\n================================================================\n");

                    break;

                case 5:
                    temps_initial = clock();
                    tri_base(tab_all, length);
                    temps_final = clock();
                    temps_cpu = (temps_final - temps_initial) * 1e-6;

                    yvals[index] = temps_cpu;

                    printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                    printf("%d %f ", length, temps_cpu);
                    printf("\n================================================================\n");

                    break;

                case 6:
                    temps_initial = clock();
                    tri_enum_v2(tab_all, length);
                    temps_final = clock();
                    temps_cpu = (temps_final - temps_initial) * 1e-6;

                    yvals[index] = temps_cpu;

                    printf("\n\e[0;36mProcess No %d | %d items OK\e[0m\n", index + 1, length);
                    printf("%d %f ", length, temps_cpu);
                    printf("\n================================================================\n");

                    break;

                default:
                    printf("\n\n=====================================================\nProgram has been terminared\n\n");
                    break;
                }

                index++;
                free(tab_all);
            }

            if (algo + 1 == 2)
            {
                FILE *temp = fopen("data_insertion-sort_all.temp", "w");
                for (int i = 0; i < NUM_POINTS; i++)
                {
                    fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
                }
            }
            else if (algo + 1 == 3)
            {
                FILE *temp = fopen("data_fusion-sort_all.temp", "w");
                for (int i = 0; i < NUM_POINTS; i++)
                {
                    fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
                }
            }
            else if (algo + 1 == 4)
            {
                FILE *temp = fopen("data_enumeration-sort_all.temp", "w");
                for (int i = 0; i < NUM_POINTS; i++)
                {
                    fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
                }
            }
            else if (algo + 1 == 5)
            {
                FILE *temp = fopen("data_base-sort_all.temp", "w");
                for (int i = 0; i < NUM_POINTS; i++)
                {
                    fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
                }
            }
            else if (algo + 1 == 6)
            {
                FILE *temp = fopen("data_enumerationV2-sort_all.temp", "w");
                for (int i = 0; i < NUM_POINTS; i++)
                {
                    fprintf(temp, "%.6f %.6f \n", xvals[i], yvals[i]); // Write the data to a temporary file
                }
            }
            else
            {
                printf("\n\nAn error occured!\n");
                exit(-2);
            }
        }
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");

        char *commandsForGnuplot[] = {"set title \"Sorting Algorithms Comprison\"", "set style line 1 lt 1 linecolor rgb 'yellow' lw 2 pt 1", "set style line 2 lt 1 linecolor rgb 'green' lw 2 pt 1", "set style line 3 lt 1 linecolor rgb 'blue' lw 2 pt 1", "set style line 4 lt 1 linecolor rgb 'cyan' lw 2 pt 1", "set style line 5 lt 1 linecolor rgb 'magenta' lw 2 pt 1","plot 'data_fusion-sort_all.temp' using 1:2 ls 2 title 'Fusion' with lines, \'data_enumeration-sort_all.temp' using 1:2 ls 3 title 'Enumeration' with lines, \'data_base-sort_all.temp' using 1:2 ls 4 title 'Base (Randix)' with lines, \'data_enumerationV2-sort_all.temp' using 1:2 ls 5 title 'EnumerationV2 (min,max)' with lines"};
        //We are not printing 'data_insertion-sort_all.temp' using 1:2 ls 1 title 'one' with lines, \ because we can't see the differences of others on scale
        for (int i = 0; i < NUM_COMMANDS_ALL; i++)
        {
            fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Send commands to gnuplot one by one.
        }
    }
    else
    {
        clearScreen();
        printf("An error occured :(");
        exit(-3);
    }

    return 0;
}
