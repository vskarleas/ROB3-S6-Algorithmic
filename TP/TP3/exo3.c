#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include "exo2.h"
#include "utile.h"

// EXO3.1

void tri_taches_exo3(int *deb, int *fin, int nbTaches)
{
	tri_fusion(deb, fin, 0, nbTaches - 1);
}

void init_servers(int n, int *tab)
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = -1;
	}
	return;
}

int glouton(int *deb, int *fin, int nbTaches)
{
	int p = 0;			   // servers working currently
	int servers[nbTaches]; // maximum number of machines is the number of requests

	init_servers(nbTaches, servers);

	for (int j = 0; j < nbTaches; j++)
	{
		int i = 0;
		bool need_new_server = true;
		while (i < p && need_new_server) // we test every server that is working if it has finished the task or not
		{
			{
				if (servers[i] <= deb[j])
				{
					servers[i] = fin[j];
					need_new_server = false;
				}
				i++;
			}
		}

		if (need_new_server) // every server is working. We add a new one on the network
		{
			servers[p] = fin[j];
			p++;
		}
	}

	return p;
}

// EXO3.2
void fusion_extrem(int *tab, int debut, int milieu, int fin)
{
	int n1 = milieu - debut + 1; // Longueur du premier sous-tableau
	int n2 = fin - milieu;		 // Longueur du second sous-tableau

	// Création de tableaux temporaires
	int L[n1], R[n2];

	// Copie des données dans les tableaux temporaires
	for (int i = 0; i < n1; i++)
		L[i] = tab[debut + i];
	for (int j = 0; j < n2; j++)
		R[j] = tab[milieu + 1 + j];

	// Fusion des tableaux temporaires
	int i = 0, j = 0, k = debut;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			tab[k] = L[i];
			i++;
		}
		else
		{
			tab[k] = R[j];
			j++;
		}
		k++;
	}

	// Copie des éléments restants
	while (i < n1)
	{
		tab[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		tab[k] = R[j];
		j++;
		k++;
	}
}

// Fonction de tri fusion pour trier un tableau.
void tri_fusion_extrem(int *tab, int debut, int fin)
{
	if (debut < fin)
	{
		int milieu = debut + (fin - debut) / 2;
		tri_fusion_extrem(tab, debut, milieu);	 // Tri de la première moitié
		tri_fusion_extrem(tab, milieu + 1, fin); // Tri de la seconde moitié
		fusion_extrem(tab, debut, milieu, fin);	 // Fusion des deux moitiés
	}
}

void tri(int *tab, int n)
{
	tri_fusion_extrem(tab, 0, n - 1);
}

int get_profondeur(int *deb, int *fin, int nbTaches)
{
	// sorting according to the end of every task for deb and fin table
	tri(deb, nbTaches);
	tri(fin, nbTaches);

	int depth = 0;
	int p = 0;
	int i = 0;
	int j = 0;

	while (i < nbTaches && j < nbTaches)
	{
		if (deb[i] < fin[j])
		{
			p++;
			i++;
		}
		else
		{
			p--;
			j++;
		}
		
		depth = max(p, depth);
	}

	return depth; // Retourner la profondeur maximale trouvée
}