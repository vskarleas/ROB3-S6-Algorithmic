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

int main(int argc, char **argv)
{
    int choice = menu_mode();
    printf("================================================\n");
    if (choice == 1)
    {
        int M = 6;
        int *tab;
        tab = malloc(M * sizeof(int));
        if (tab == NULL)
        {
            fprintf(stderr, "\nFailed to allocate memory for tab.\n");
            exit(-1);
        }
        int seq[2] = {2, 1};

        initialize1D(tab, M);

        colorize(sizeof(seq) / sizeof(seq[0]), M - 1, tab, seq);
        print_table(tab, M, verify(tab, seq, M - 1, sizeof(seq) / sizeof(seq[0])));
    }
    else
    {
        fprintf(stderr, "An error occured with menu_mode. We are sorry for that! \n");
    }

    return 0;
}