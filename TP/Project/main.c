// #############################################################################
// # File main.c
// # UE Infomatics for Robotics - Polytech Sorbonne - 2023/2024 - S6
// # Authors: Yannis Sadoun, Vasileios Filippos Skarleas - All rights reserved.
// #############################################################################

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utile.h"
#include "algos.h"
#include "constants.h"

#define DIRECTORY_PATH "TP/Project/instances"

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

        /* TEST No 1 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab1[1] = {DEFAULT};
        int seq1[1] = {1};

        print_table(tab1, sizeof(tab1) / sizeof(tab1[0]), 2);
        printf("The sequence is: ");
        table_content(seq1, sizeof(seq1) / sizeof(seq1[0]));
        if (T(sizeof(tab1) / sizeof(tab1[0]) - 1, sizeof(seq1) / sizeof(seq1[0]), tab1, seq1) == true)
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

        print_table(tab2, sizeof(tab2) / sizeof(tab2[0]), 2);
        printf("The sequence is: ");
        table_content(seq2, sizeof(seq2) / sizeof(seq2[0]));
        if (T(sizeof(tab2) / sizeof(tab2[0]) - 1, sizeof(seq2) / sizeof(seq2[0]), tab2, seq2) == true)
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

        print_table(tab3, sizeof(tab3) / sizeof(tab3[0]), 2);
        printf("The sequence is: ");
        table_content(seq3, sizeof(seq3) / sizeof(seq3[0]));
        if (T(sizeof(tab3) / sizeof(tab3[0]) - 1, sizeof(seq3) / sizeof(seq3[0]), tab3, seq3) == true)
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

        print_table(tab4, sizeof(tab4) / sizeof(tab4[0]), 2);
        printf("The sequence is: ");
        table_content(seq4, sizeof(seq4) / sizeof(seq4[0]));
        if (T(sizeof(tab4) / sizeof(tab4[0]) - 1, sizeof(seq4) / sizeof(seq4[0]), tab4, seq4) == true)
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

        print_table(tab5, sizeof(tab5) / sizeof(tab5[0]), 2);
        printf("The sequence is: ");
        table_content(seq5, sizeof(seq5) / sizeof(seq5[0]));
        if (T(sizeof(tab5) / sizeof(tab5[0]) - 1, sizeof(seq5) / sizeof(seq5[0]), tab5, seq5) == true)
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

        print_table(tab6, sizeof(tab6) / sizeof(tab6[0]), 2);
        printf("The sequence is: ");
        table_content(seq6, sizeof(seq6) / sizeof(seq6[0]));
        if (T(sizeof(tab6) / sizeof(tab6[0]) - 1, sizeof(seq6) / sizeof(seq6[0]), tab6, seq6) == true)
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

        print_table(tab7, sizeof(tab7) / sizeof(tab7[0]), 2);
        printf("The sequence is: ");
        table_content(seq7, sizeof(seq7) / sizeof(seq7[0]));
        if (T(sizeof(tab7) / sizeof(tab7[0]) - 1, sizeof(seq7) / sizeof(seq7[0]), tab7, seq7) == true)
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

        print_table(tab8, sizeof(tab8) / sizeof(tab8[0]), 2);
        printf("The sequence is: ");
        table_content(seq8, sizeof(seq8) / sizeof(seq8[0]));
        if (T(sizeof(tab8) / sizeof(tab8[0]) - 1, sizeof(seq8) / sizeof(seq8[0]), tab8, seq8) == true)
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

        print_table(tab9, sizeof(tab9) / sizeof(tab9[0]), 2);
        printf("The sequence is: ");
        table_content(seq9, sizeof(seq9) / sizeof(seq9[0]));
        if (T(sizeof(tab9) / sizeof(tab9[0]) - 1, sizeof(seq9) / sizeof(seq9[0]), tab9, seq9) == true)
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

        print_table(tab10, sizeof(tab10) / sizeof(tab10[0]), 2);
        printf("The sequence is: ");
        table_content(seq10, sizeof(seq10) / sizeof(seq10[0]));
        if (T(sizeof(tab10) / sizeof(tab10[0]) - 1, sizeof(seq10) / sizeof(seq10[0]), tab10, seq10) == true)
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

        print_table(tab11, sizeof(tab11) / sizeof(tab11[0]), 2);
        printf("The sequence is: ");
        table_content(seq11, sizeof(seq11) / sizeof(seq11[0]));
        if (T(sizeof(tab11) / sizeof(tab11[0]) - 1, sizeof(seq11) / sizeof(seq11[0]), tab11, seq11) == true)
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

        print_table(tab12, sizeof(tab12) / sizeof(tab12[0]), 2);
        printf("The sequence is: ");
        table_content(seq12, sizeof(seq12) / sizeof(seq12[0]));
        if (T(sizeof(tab12) / sizeof(tab12[0]) - 1, sizeof(seq12) / sizeof(seq12[0]), tab12, seq12) == true)
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

        print_table(tab13, sizeof(tab13) / sizeof(tab13[0]), 2);
        printf("The sequence is: ");
        table_content(seq13, sizeof(seq13) / sizeof(seq13[0]));
        if (T(sizeof(tab13) / sizeof(tab13[0]) - 1, sizeof(seq13) / sizeof(seq13[0]), tab13, seq13) == true)
        {
            printf("=>  TRUE\n---------------------\n");
        }
        else
        {
            printf("=>  FALSE\n---------------------\n");
        }
        test_id++;

        /* TEST No 14 (has to return true) */
        printf("\n\e[0;32mTest No %d\e[0m\n", test_id);
        int tab14[6] = {BLACK, DEFAULT, DEFAULT, WHITE, DEFAULT, BLACK};
        int seq14[2] = {3, 2};

        print_table(tab14, sizeof(tab14) / sizeof(tab14[0]), 2);
        printf("The sequence is: ");
        table_content(seq14, sizeof(seq14) / sizeof(seq14[0]));
        if (T(sizeof(tab14) / sizeof(tab14[0]) - 1, sizeof(seq14) / sizeof(seq14[0]), tab14, seq14) == true)
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

        print_table(tab15, sizeof(tab15) / sizeof(tab15[0]), 2);
        printf("The sequence is: ");
        table_content(seq15, sizeof(seq15) / sizeof(seq15[0]));
        if (T(sizeof(tab15) / sizeof(tab15[0]) - 1, sizeof(seq15) / sizeof(seq15[0]), tab15, seq15) == true)
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
        int tab16[6] = {DEFAULT, DEFAULT, WHITE, DEFAULT, DEFAULT, DEFAULT};
        int seq16[2] = {3, 2};

        print_table(tab16, sizeof(tab16) / sizeof(tab16[0]), 2);
        printf("The sequence is: ");
        table_content(seq16, sizeof(seq16) / sizeof(seq16[0]));
        if (T(sizeof(tab16) / sizeof(tab16[0]) - 1, sizeof(seq16) / sizeof(seq16[0]), tab16, seq16) == true)
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

        printf("What's the instance's file name: ");
        scanf("%s", filename);

        filename[strcspn(filename, "\n")] = '\0'; // make sure that the file is in correct format so that we can start counting nb_lines and nb_columns immediatly

        int n_rows, n_cols;
        int *lines;
        int *columns;

        read_file(filename, &lines, &columns, &n_rows, &n_cols);
        printf("NB Lines: %d\n", n_rows);
        printf("NB Columns: %d\n", n_cols);

        printf("Sequence lines: ");
        for (int i = 0; i < n_rows; i++)
        {
            printf("%d ", lines[i]);
        }
        printf("\n");
        printf("Sequence columns: ");
        for (int i = 0; i < n_cols; i++)
        {
            printf("%d ", columns[i]);
        }

        // free(grid);
        free(lines);
        free(columns);
    }
    else
    {
        fprintf(stderr, "An error occured with menu_mode. We are sorry for that! \n");
    }

    return 0;
}