#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <ncurses.h>
#include "utile.h"


/* Printing the table (for visualisation and test porpuses) */
void affiche_tab(int *tab, int n, int mode, char *methode)
{
    if (mode == 1)
    {
        printf("\nTable generated: \n");
    }
    else
    {
        printf("\nTable after treatment with %s: \n", methode);
    }
    int i;
    for (i = 0; i < n - 1; i++)
    {
        printf(" %d |", tab[i]);
    }
    printf(" %d \n", tab[n - 1]);
}

/* Starting the random engine */
void init_nb_aleatoire()
{
  srand(time(0));
}

/* Generates random numbers min and max given as arguments */
int nb_random(int min, int max)
{
  return min + rand() % (max + 1 - min);
}

/* Rand tasks (instances) generation */
void generate_instances(int *debut, int *fin, int n, int Fmax)
{
  for (int i = 0; i < n; ++i)
  {
    debut[i] = nb_random(0, Fmax);                     // taking any number on the intervalle
    fin[i] = debut[i] + nb_random(1, Fmax - debut[i]); // starting from the beginning of the interval we add minimum 1 up to maximum - start time (in order to remain on the Fmax limit)
  }
}

/* Choose exercise testing for main program */
int menu_mode()
{
  char userInput[20];
  char *msg[1] = {"Choose an option (Exo1, Exo2, Exo3, Exo3.2). Your choice: "};
  char *msg_attention[1] = {"You can only choose from Exo1, Exo2, Exo3 or Exo3.2 ."};

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
    else if (strcmp(userInput, "exo3.2") == 0)
    {
      return 4;
    }
    else
    {
      printf("\n\033[0;33mATTENTION!\033[1;0m: %s\n", msg_attention[0]);
    }
  }
  return 0;
}

/* Simply returns the maximum between two numbers (inputs) */
int max(int x, int y)
{
  if (x > y)
  {
    return x;
  }
  else
  {
    return y;
  }
}
