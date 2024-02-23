#include <stdio.h>
#include <stdbool.h>
#include "utile.h"

void fusion(int *deb, int *fin, int debut, int milieu, int finTab)
{
    int n1 = milieu - debut + 1;
    int n2 = finTab - milieu;

    int Ldeb[n1], Lfin[n1], Rdeb[n2], Rfin[n2];

    for (int i = 0; i < n1; i++)
    {
        Ldeb[i] = deb[debut + i];
        Lfin[i] = fin[debut + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Rdeb[j] = deb[milieu + 1 + j];
        Rfin[j] = fin[milieu + 1 + j];
    }

    int i = 0, j = 0, k = debut;
    while (i < n1 && j < n2)
    {
        if (Lfin[i] <= Rfin[j])
        {
            deb[k] = Ldeb[i];
            fin[k] = Lfin[i];
            i++;
        }
        else
        {
            deb[k] = Rdeb[j];
            fin[k] = Rfin[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        deb[k] = Ldeb[i];
        fin[k] = Lfin[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        deb[k] = Rdeb[j];
        fin[k] = Rfin[j];
        j++;
        k++;
    }
}

void tri_fusion(int *deb, int *fin, int debut, int finTab)
{
    if (debut < finTab)
    {
        int milieu = debut + (finTab - debut) / 2;
        tri_fusion(deb, fin, debut, milieu);
        tri_fusion(deb, fin, milieu + 1, finTab);
        fusion(deb, fin, debut, milieu, finTab);
    }
}

// EXO2.1
void tri_taches_exo2(int *deb, int *fin, int nbTaches)
{
    tri_fusion(deb, fin, 0, nbTaches - 1);
}

bool is_compatible(int i, int j, int *debut, int *fin)
{
    if (fin[i] <= debut[j])
    {
        return true;
    }
    else
    {
        return false;
    }

    // or even
    // return (fin[i] <= debut[j])
}

int calcule_OPT(int *deb, int *fin, int j)
{
    if (j < 0)
    {
        return 0;
    }
    else
    {
        int der_j = -1;
        // Trouver la dernière tâche compatible avec la tâche j
        for (int i = 0; i < j; i++)
        {
            if (is_compatible(i, j, deb, fin))
            {
                der_j = i;
            }
        }

        // Calculer récursivement l'OPT en incluant ou excluant la tâche j
        return max(1 + calcule_OPT(deb, fin, der_j), calcule_OPT(deb, fin, j - 1));
    }
}

// EXO2.2
int calcule_OPT_glouton(int *deb, int *fin, int nbTaches)
{
    int dispo = 0;
    int k = 0;

    for (int j = 0; j < nbTaches; j++)
    {
        if (deb[j] >= dispo)
        {
            k++;
            dispo = fin[j];
        }
    }
    return k;
}

void calcule_OPT_glouton2(int *deb, int *fin, int nbTaches, bool *tacheSelected)
{
    int dispo = 0;
    int k = 0;

    // same idea with the previous but here we use a static table to save the date called tacheSelected
    // This approch is close to the dynamc programming (programmation dynamique) of TD4
    for (int j = 0; j < nbTaches; j++)
    {
        if (deb[j] >= dispo)
        {
            k = k + 1;
            dispo = fin[j];
            tacheSelected[j] = true;
        }
        else
        {
            tacheSelected[j] = false;
        }
    }
}
