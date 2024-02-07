#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "utile.h"
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

void affiche_tab(int *tab, int n)
{
    printf("Table: \n");
    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf(" %d |", tab[i]);
    }
    printf("%d \n", tab[i + 1]);
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

/*EXERCICE 1*/
void init_tab(int *tab, int n, int Bmin, int Bmax)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = nb_random(Bmin, Bmax);
    }
}

/*EXERCICE 4*/
void get_min_max(int *tab, int n, int *min, int *max)
{
    /*TODO*/
}

/*EXERCICE 5*/
void get_max(int *tab, int n, int *max)
{
    /*TODO*/
}

int get_length(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

/* suppression de tous les �l�ments de la liste chainne, renvoie la liste L vide */
Liste_Point clean(Liste_Point L)
{
    Elt *el = L.first;

    while (el)
    {
        Elt *suiv = el->suiv;
        free(el);
        el = suiv;
    }
    L.first = L.last = NULL;
    L.taille = 0;
    return L;
}

/* cr�er une s�quence de points sous forme d'un tableau de points
   � partir de la liste de points L */
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L)
{
    Tableau_Point T;

    /* taille de T = taille de L */
    T.taille = L.taille;

    /* allocation dynamique du tableau de Point */
    T.data = malloc(sizeof(int) * T.taille);
    if (T.data == NULL)
    {
        /* allocation impossible : arret du programme avec un message */
        fprintf(stderr, "sequence_points_liste_vers_tableau : ");
        fprintf(stderr, " allocation impossible\n");
#ifdef __APPLE__
        system("killall afplay");
#endif
        exit(-1);
    }

    /* remplir le tableau de points T en parcourant la liste L */
    int k = 0;         /* indice de l'�l�ment dans T.tab */
    Elt *el = L.first; /* pointeur sur l'�l�ment dans L */
    while (el)
    {
        T.data[k] = el->data;
        k++;           /* incr�menter k */
        el = el->suiv; /* passer � l'�lement suivant dans la liste chainee */
    }

    return T;
}

/* Clearing the terminal screen for more optimised visualisations */
void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

/* Gives a user the choice of the exercise */
int menu_mode()
{
    char userInput[20];
    char *msg[1] = {"Choose an option (Exo1, Exo2, Exo3, Exo4, Exo5 or Exo6). Your choice: "};
    char *msg_attention[1] = {"You can only choose from Exo1, Exo2, Exo3, Exo4, Exo5 or Exo6."};

    while (true)
    {
        printf("\n%s ", msg[0]);
        scanf("%s", userInput);

        // Convert input to lowercase for case-insensitive comparison and returns
        for (int i = 0; i < strlen(userInput); i++)
        {
            userInput[i] = tolower(userInput[i]);
        }

        if (strcmp(userInput, "exo1") == 0)
        {
            return 1;
        }
        else if (strcmp(userInput, "exo2") == 0)
        {
            return 2;
        }
        else if (strcmp(userInput, "exo3") == 0)
        {
            return 3;
        }
        else if (strcmp(userInput, "exo4") == 0)
        {
            return 4;
        }
        else if (strcmp(userInput, "exo5") == 0)
        {
            return 5;
        }
        else if (strcmp(userInput, "exo6") == 0)
        {
            return 6;
        }
        else
        {
            clearScreen();
            printf("\n\033[0;33mATTENTION!\033[1;0m: %s\n", msg_attention[0]);
        }
    }
    return 0;
}