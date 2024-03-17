// #############################################################################
// # File main.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yanis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "utile.h"
#include "algos.h"
#include "constants.h"

int main(int argc, char **argv)
{
    int choice = menu_mode();
    printf("================================================\n");
    if (choice == 2)
    {
        int test_id = 1;
        // int *tab;
        // tab = malloc(M * sizeof(int));
        // if (tab == NULL)
        // {
        //     fprintf(stderr, "\nFailed to allocate memory for tab.\n");
        //     exit(-1);
        // }

        // initialize1D(tab, M);
        printf("\n\n\e[0;36mBasic cases\e[0m\n");

        // /* TEST No 1 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab1[1] = {DEFAULT};
        int seq1[1] = {1};

        print_table(tab1, sizeof(tab1) / sizeof(tab1[0]));
        printf("The sequence is: ");
        table_content(seq1, sizeof(seq1) / sizeof(seq1[0]));
        if (T_v2(sizeof(tab1) / sizeof(tab1[0]) - 1, sizeof(seq1) / sizeof(seq1[0]), tab1, seq1) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 2 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab2[1] = {WHITE};
        int seq2[1] = {1};

        print_table(tab2, sizeof(tab2) / sizeof(tab2[0]));
        printf("The sequence is: ");
        table_content(seq2, sizeof(seq2) / sizeof(seq2[0]));
        if (T_v2(sizeof(tab2) / sizeof(tab2[0]) - 1, sizeof(seq2) / sizeof(seq2[0]), tab2, seq2) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 3 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab3[1] = {BLACK};
        int seq3[1] = {1};

        print_table(tab3, sizeof(tab3) / sizeof(tab3[0]));
        printf("The sequence is: ");
        table_content(seq3, sizeof(seq3) / sizeof(seq3[0]));
        if (T_v2(sizeof(tab3) / sizeof(tab3[0]) - 1, sizeof(seq3) / sizeof(seq3[0]), tab3, seq3) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 4 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab4[3] = {BLACK, DEFAULT, DEFAULT};
        int seq4[1] = {3};

        print_table(tab4, sizeof(tab4) / sizeof(tab4[0]));
        printf("The sequence is: ");
        table_content(seq4, sizeof(seq4) / sizeof(seq4[0]));
        if (T_v2(sizeof(tab4) / sizeof(tab4[0]) - 1, sizeof(seq4) / sizeof(seq4[0]), tab4, seq4) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        printf("\n\n\e[0;36mMore complex cases\e[0m\n");
        /* TEST No 5 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab5[3] = {BLACK, DEFAULT, DEFAULT};
        int seq5[1] = {4};

        print_table(tab5, sizeof(tab5) / sizeof(tab5[0]));
        printf("The sequence is: ");
        table_content(seq5, sizeof(seq5) / sizeof(seq5[0]));
        if (T_v2(sizeof(tab5) / sizeof(tab5[0]) - 1, sizeof(seq5) / sizeof(seq5[0]), tab5, seq5) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 6 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab6[3] = {BLACK, DEFAULT, WHITE};
        int seq6[1] = {2};

        print_table(tab6, sizeof(tab6) / sizeof(tab6[0]));
        printf("The sequence is: ");
        table_content(seq6, sizeof(seq6) / sizeof(seq6[0]));
        if (T_v2(sizeof(tab6) / sizeof(tab6[0]) - 1, sizeof(seq6) / sizeof(seq6[0]), tab6, seq6) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 7 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab7[3] = {WHITE, DEFAULT, DEFAULT};
        int seq7[1] = {2};

        print_table(tab7, sizeof(tab7) / sizeof(tab7[0]));
        printf("The sequence is: ");
        table_content(seq7, sizeof(seq7) / sizeof(seq7[0]));
        if (T_v2(sizeof(tab7) / sizeof(tab7[0]) - 1, sizeof(seq7) / sizeof(seq7[0]), tab7, seq7) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 8 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab8[3] = {WHITE, DEFAULT, DEFAULT};
        int seq8[1] = {3};

        print_table(tab8, sizeof(tab8) / sizeof(tab8[0]));
        printf("The sequence is: ");
        table_content(seq8, sizeof(seq8) / sizeof(seq8[0]));
        if (T_v2(sizeof(tab8) / sizeof(tab8[0]) - 1, sizeof(seq8) / sizeof(seq8[0]), tab8, seq8) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 9 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab9[3] = {WHITE, DEFAULT, DEFAULT};
        int seq9[0] = {};

        print_table(tab9, sizeof(tab9) / sizeof(tab9[0]));
        printf("The sequence is: ");
        table_content(seq9, sizeof(seq9) / sizeof(seq9[0]));
        if (T_v2(sizeof(tab9) / sizeof(tab9[0]) - 1, sizeof(seq9) / sizeof(seq9[0]), tab9, seq9) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        printf("\n\n\e[0;36mHigh complexity cases\e[0m\n");
        /* TEST No 10 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab10[5] = {DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT};
        int seq10[3] = {2, 1, 1};

        print_table(tab10, sizeof(tab10) / sizeof(tab10[0]));
        printf("The sequence is: ");
        table_content(seq10, sizeof(seq10) / sizeof(seq10[0]));
        if (T_v2(sizeof(tab10) / sizeof(tab10[0]) - 1, sizeof(seq10) / sizeof(seq10[0]), tab10, seq10) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 11 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab11[6] = {DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT};
        int seq11[2] = {3, 2};

        print_table(tab11, sizeof(tab11) / sizeof(tab11[0]));
        printf("The sequence is: ");
        table_content(seq11, sizeof(seq11) / sizeof(seq11[0]));
        if (T_v2(sizeof(tab11) / sizeof(tab11[0]) - 1, sizeof(seq11) / sizeof(seq11[0]), tab11, seq11) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 12 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab12[6] = {DEFAULT, DEFAULT, DEFAULT, WHITE, DEFAULT, DEFAULT};
        int seq12[2] = {3, 2};

        print_table(tab12, sizeof(tab12) / sizeof(tab12[0]));
        printf("The sequence is: ");
        table_content(seq12, sizeof(seq12) / sizeof(seq12[0]));
        if (T_v2(sizeof(tab12) / sizeof(tab12[0]) - 1, sizeof(seq12) / sizeof(seq12[0]), tab12, seq12) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 13 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab13[6] = {WHITE, DEFAULT, DEFAULT, WHITE, DEFAULT, DEFAULT};
        int seq13[2] = {3, 2};

        print_table(tab13, sizeof(tab13) / sizeof(tab13[0]));
        printf("The sequence is: ");
        table_content(seq13, sizeof(seq13) / sizeof(seq13[0]));
        if (T_v2(sizeof(tab13) / sizeof(tab13[0]) - 1, sizeof(seq13) / sizeof(seq13[0]), tab13, seq13) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 14 (has to return true) */ // HERE
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab14[6] = {BLACK, DEFAULT, DEFAULT, WHITE, DEFAULT, BLACK};
        int seq14[2] = {3, 2};

        print_table(tab14, sizeof(tab14) / sizeof(tab14[0]));
        printf("The sequence is: ");
        table_content(seq14, sizeof(seq14) / sizeof(seq14[0]));
        if (T_v2(sizeof(tab14) / sizeof(tab14[0]) - 1, sizeof(seq14) / sizeof(seq14[0]), tab14, seq14) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 15 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab15[6] = {BLACK, WHITE, DEFAULT, WHITE, DEFAULT, BLACK};
        int seq15[2] = {3, 2};

        print_table(tab15, sizeof(tab15) / sizeof(tab15[0]));
        printf("The sequence is: ");
        table_content(seq15, sizeof(seq15) / sizeof(seq15[0]));
        if (T_v2(sizeof(tab15) / sizeof(tab15[0]) - 1, sizeof(seq15) / sizeof(seq15[0]), tab15, seq15) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 16 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab16[5] = {WHITE, DEFAULT, WHITE, DEFAULT, DEFAULT};
        int seq16[1] = {3};

        print_table(tab16, sizeof(tab16) / sizeof(tab16[0]));
        printf("The sequence is: ");
        table_content(seq16, sizeof(seq16) / sizeof(seq16[0]));
        if (T_v2(sizeof(tab16) / sizeof(tab16[0]) - 1, sizeof(seq16) / sizeof(seq16[0]), tab16, seq16) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 17 (has to return false) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab17[4] = {BLACK, BLACK, DEFAULT, DEFAULT};
        int seq17[2] = {1, 2};

        print_table(tab17, sizeof(tab17) / sizeof(tab17[0]));
        printf("The sequence is: ");
        table_content(seq17, sizeof(seq17) / sizeof(seq17[0]));
        if (T_v2(sizeof(tab17) / sizeof(tab17[0]) - 1, sizeof(seq17) / sizeof(seq17[0]), tab17, seq17) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 18 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab18[5] = {DEFAULT, DEFAULT, DEFAULT, DEFAULT, DEFAULT};
        int seq18[1] = {3};

        print_table(tab18, sizeof(tab18) / sizeof(tab18[0]));
        printf("The sequence is: ");
        table_content(seq18, sizeof(seq18) / sizeof(seq18[0]));
        if (T_v2(sizeof(tab18) / sizeof(tab18[0]) - 1, sizeof(seq18) / sizeof(seq18[0]), tab18, seq18) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 19 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab19[5] = {DEFAULT, DEFAULT, BLACK, WHITE, DEFAULT};
        int seq19[1] = {3};

        print_table(tab19, sizeof(tab19) / sizeof(tab19[0]));
        printf("The sequence is: ");
        table_content(seq19, sizeof(seq19) / sizeof(seq19[0]));
        if (T_v2(sizeof(tab19) / sizeof(tab19[0]) - 1, sizeof(seq19) / sizeof(seq19[0]), tab19, seq19) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 20 (has to return true) */ // HERE
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab20[4] = {BLACK, DEFAULT, DEFAULT, DEFAULT};
        int seq20[1] = {3};

        print_table(tab20, sizeof(tab20) / sizeof(tab20[0]));
        printf("The sequence is: ");
        table_content(seq20, sizeof(seq20) / sizeof(seq20[0]));
        if (T_v2(sizeof(tab20) / sizeof(tab20[0]) - 1, sizeof(seq20) / sizeof(seq20[0]), tab20, seq20) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 21 (has to return true) */ // HERE
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab21[5] = {WHITE, WHITE, BLACK, BLACK, WHITE};
        int seq21[1] = {3};

        print_table(tab21, sizeof(tab21) / sizeof(tab21[0]));
        printf("The sequence is: ");
        table_content(seq21, sizeof(seq21) / sizeof(seq21[0]));
        if (T_v2(sizeof(tab21) / sizeof(tab21[0]) - 1, sizeof(seq21) / sizeof(seq21[0]), tab21, seq21) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }

        printf("The test 1.2 has been successfully completed\n");
    }
    else if (choice == 3)
    {
        char filename[100];

        printf("Partial version of the code (propagation test). What's the instance's file name: ");
        scanf("%s", filename);

        filename[strcspn(filename, "\n")] = '\0'; // make sure that the file is in correct format so that we can start counting nb_lines and nb_columns immediatly

        int n_rows, n_cols, max_rows, max_columns;

        /* First analysis of the instance */
        decode_file(filename, &n_rows, &n_cols, &max_rows, &max_columns);

        printf("\nNB Lines: %d\n", n_rows);
        printf("Max Lines: %d\n", max_rows);
        printf("NB Columns: %d\n", n_cols);
        printf("Max Columns: %d\n\n", max_columns);

        int maximum = max(max_columns, max_rows);

        /* Main Memory allocation */
        int **rows;
        rows = malloc(n_rows * sizeof(int *));
        if (rows == NULL)
        {
            allocation_error_print_general("rows");
        }

        for (int i = 0; i < n_rows; i++)
        {
            rows[i] = malloc(maximum * sizeof(int));
            if (rows[i] == NULL)
            {
                allocation_error_print_with_id("rows row", i);
            }
        }

        int **columns;
        columns = malloc(n_cols * sizeof(int *));
        if (columns == NULL)
        {
            allocation_error_print_general("columns");
        }

        for (int i = 0; i < n_cols; i++)
        {
            columns[i] = malloc(maximum * sizeof(int));
            if (columns[i] == NULL)
            {
                allocation_error_print_with_id("columns row", i);
            }
        }

        /* Instance decoding */
        read_file_v2(filename, rows, columns, n_rows, n_cols, maximum);

        /* Concatenating rows and columsn sequences in a single table to simplify the treatment process */
        int **rows_columns = malloc(sizeof(int *) * (n_rows + n_cols));

        for (int i = 0; i < n_rows; i++)
        {
            rows_columns[i] = rows[i]; // Copy the entire row pointer
        }

        for (int i = 0; i < n_cols; i++)
        {
            rows_columns[n_rows + i] = columns[i]; // Copy to subsequent rows
        }

        printf("\nLines sequences\n");
        // printing_grid(rows, n_rows, max_rows, 1);
        printing_grid(rows, n_rows, maximum, 1);

        printf("\nColumns sequences\n");
        // printing_grid(columns, n_cols, max_columns, 1);
        printing_grid(columns, n_cols, maximum, 1);

        /* Grid creation and initialization */
        int **grid;
        grid = malloc(n_rows * sizeof(int *));
        if (columns == NULL)
        {
            allocation_error_print_general("grid");
        }

        for (int i = 0; i < n_rows; i++)
        {
            grid[i] = malloc(n_cols * sizeof(int));
            if (grid[i] == NULL)
            {
                allocation_error_print_with_id("grid row", i);
            }
        }

        initialize2D(grid, n_rows, n_cols);

        /* Result */
        enum State result;
        clock_t temps_initial;
        clock_t temps_final;
        float temps_cpu = 0.0;
        int time = midle_menu();

        if (time == 1)
        {
            temps_initial = clock();
            result = color_grid_v2(grid, n_rows, n_cols, rows_columns, maximum);
            temps_final = clock();

            temps_cpu = (temps_final - temps_initial) * 1e-6; // Total time in seconds
            clearScreen();
            printf("\nThe time passed is %f seconds\n", temps_cpu);
        }
        else if (time == 2)
        {
            result = color_grid_v2(grid, n_rows, n_cols, rows_columns, maximum);
            clearScreen();
        }
        else
        {
            exit(-6);
        }

        switch (result)
        {
        case SUCCESS:
            printf("\n\e[0;32mSUCCESS\e[0m");
            printf("\nThe colourised grid is:\n");
            printing_grid(grid, n_rows, n_cols, 4);
            break;
        case FAIL:
            printf("\n\e[0;31mThe provided puzzle can NOT BE SOLVED\e[0m\n");
            break;
        case NO_DECISION:
            printf("\n\e[0;36mThere is NO DECISION for the provided puzzle\e[0m\n");
            printf("\nThe grid is:\n");
            printing_grid(grid, n_rows, n_cols, 4);
            break;
        default:
            printf("An error occured on enum State response\n");
            break;
        }
    }
    else if (choice == 4)
    {
        char filename[100];

        printf("Complet version of the code. What's the instance's file name: ");
        scanf("%s", filename);

        filename[strcspn(filename, "\n")] = '\0'; // make sure that the file is in correct format so that we can start counting nb_lines and nb_columns immediatly

        int n_rows, n_cols, max_rows, max_columns;

        /* First analysis of the instance */
        decode_file(filename, &n_rows, &n_cols, &max_rows, &max_columns);

        int maximum = max(max_columns, max_rows);

        /* Main Memory allocation */
        int **rows;
        rows = malloc(n_rows * sizeof(int *));
        if (rows == NULL)
        {
            allocation_error_print_general("rows");
        }

        for (int i = 0; i < n_rows; i++)
        {
            rows[i] = malloc(maximum * sizeof(int));
            if (rows[i] == NULL)
            {
                allocation_error_print_with_id("rows row", i);
            }
        }

        int **columns;
        columns = malloc(n_cols * sizeof(int *));
        if (columns == NULL)
        {
            allocation_error_print_general("columns");
        }

        for (int i = 0; i < n_cols; i++)
        {
            columns[i] = malloc(maximum * sizeof(int));
            if (columns[i] == NULL)
            {
                allocation_error_print_with_id("columns row", i);
            }
        }

        /* Instance decoding */
        read_file_v2(filename, rows, columns, n_rows, n_cols, maximum);

        /* Concatenating rows and columsn sequences in a single table to simplify the treatment process */
        int **rows_columns = malloc(sizeof(int *) * (n_rows + n_cols));

        for (int i = 0; i < n_rows; i++)
        {
            rows_columns[i] = rows[i]; // Copy the entire row
        }

        for (int i = 0; i < n_cols; i++)
        {
            rows_columns[n_rows + i] = columns[i]; // Copy to subsequent rows
        }

        // printf("\nLines sequences\n");
        // // printing_grid(rows, n_rows, max_rows, 1);
        // printing_grid(rows, n_rows, maximum, 1);

        // printf("\nColumns sequences\n");
        // // printing_grid(columns, n_cols, max_columns, 1);
        // printing_grid(columns, n_cols, maximum, 1);

        /* Grid creation and initialization */
        int **grid;
        grid = malloc(n_rows * sizeof(int *));
        if (columns == NULL)
        {
            allocation_error_print_general("grid");
        }

        for (int i = 0; i < n_rows; i++)
        {
            grid[i] = malloc(n_cols * sizeof(int));
            if (grid[i] == NULL)
            {
                allocation_error_print_with_id("grid row", i);
            }
        }

        initialize2D(grid, n_rows, n_cols);

        /* Result */
        enum State result;
        clock_t temps_initial;
        clock_t temps_final;
        float temps_cpu = 0.0;
        int time = midle_menu();

        if (time == 1)
        {
            temps_initial = clock();
            result = color_grid_v3(grid, n_rows, n_cols, rows_columns, maximum);
            temps_final = clock();

            temps_cpu = (temps_final - temps_initial) * 1e-6; // Total time in seconds
            clearScreen();
            printf("The time passed is %f seconds\n", temps_cpu);
        }
        else if (time == 2)
        {
            result = color_grid_v3(grid, n_rows, n_cols, rows_columns, maximum);
            clearScreen();
        }
        else
        {
            exit(-6);
        }

        switch (result)
        {
        case SUCCESS:
            printf("\n\e[0;32mSUCCESS\e[0m");
            printf("\nThe colourised grid is:\n");
            printing_grid(grid, n_rows, n_cols, 2);
            break;
        case FAIL:
            printf("\n\e[0;31mThe provided puzzle can NOT BE SOLVED\e[0m\n");
            break;
        case NO_DECISION:
            printf("\n\e[0;36mThere is NO DECISION for the provided puzzle\e[0m\n");
            printf("\nThe grid is:\n");
            printing_grid(grid, n_rows, n_cols, 2);
            break;
        default:
            printf("An error occured on enum State response\n");
            break;
        }
    }
    else
    {
        fprintf(stderr, "An error occured with menu_mode. We are sorry for that! \n");
        exit(-5);
    }

    return 0;
}