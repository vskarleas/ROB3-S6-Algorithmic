#ifndef H_UTIL
#define H_UTIL

/*---- Cellule de la liste chainne ----*/
typedef struct Elt_ {
	int data;
	struct Elt_ *suiv;
}Elt;

/*---- le type liste chainee de point ----*/
typedef struct Liste_Point_
{
	unsigned int taille;		/* nombre d'�l�ments dans la liste */
	Elt *first; /* pointeur sur le premier �l�ment de la liste */
	Elt *last;	/* pointeur sur le dernier �l�ment de la liste */
								/* first = last = NULL et taille = 0 <=> liste vide */
} Liste_Point;

/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int taille; /* nombre d'�l�ments dans le tableau */
	int *data;		 /* (pointeur vers) le tableau des �l�ments */
} Tableau_Point;

/* Prints a givent table that is passed as argument */
void affiche_tab(int* tab, int n);

/* Initialising the parameter for random numbers creation */
void init_nb_aleatoire();

/* Returns a random number between min and max (inclus not-exclusif) */
int nb_random(int min, int max);

/* Initializes a table with n random numbers between Bmin and Bmax */
void init_tab(int* tab, int n, int Bmin, int Bmax);

void get_min_max(int* tab, int n, int* min, int* max);

void get_max(int* tab, int n, int* max);

/* Compte le nombre de chiffre dans un nombre */
int get_length(int n);

void clean(Liste_Point L);

/* cr�er une s�quence de points sous forme d'un tableau de points
   � partir de la liste de points L */
Tableau_Point sequence_points_liste_vers_tableau(Liste_Point L);

/* Clearing the terminal screen for more optimised visualisations */
void clearScreen();

/* Gives a user the choice of the exercise */
int menu_mode();

#endif
