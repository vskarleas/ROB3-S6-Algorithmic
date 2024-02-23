#include <stdio.h>
#include <stdbool.h>
#include "utile.h"

// EXO2.1
void tri_taches_exo2(int *deb, int *fin, int nbTaches)
{
    int temp_start, temp_end;
    for (int i = 0; i < nbTaches - 1; i++) // otherwise we may end with a segmentation fault
    {
        for (int j = i + 1; j < nbTaches; j++) // starting from the next element
        {
            if (fin[j] < fin[i])
            {
                temp_end = fin[j];
                fin[j] = fin[i];
                fin[i] = temp_end;
                
                // exchanging fin needs to change the debut
                temp_start = deb[j];
                deb[j] = deb[i];
                deb[i] = temp_start;
        
            }
        }
    }
}

bool is_compatible(int i, int j, int *debut, int *fin)
{
    if (fin[i] <= debut[j] || fin[j] <= debut[i])
        {
            return true;
        }
        return false;
}

int calcule_OPT(int *deb, int *fin, int nbTaches)
{
    int der_j;
    bool found_compatible_pair = false;
    int i = 0;
    //base case here
    if (nbTaches == 0)
    {
        return 0;
    }
    else
    {
        while(i < nbTaches && !found_compatible_pair)
        {
            if (is_compatible(i, nbTaches - 1, deb, fin))
                {
                    der_j = i; // we have the max of i cases
                    found_compatible_pair = true;
                }
                i++;
        }
        

        return max(1 + calcule_OPT(deb, fin, der_j), calcule_OPT(deb, fin, nbTaches - 1)); // as explained on the TP paper
    }
    return 0;
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

    //same idea with the previous but here we use a static table to save the date called tacheSelected
    //This approch is close to the dynamc programming (programmation dynamique) of TD4
    for (int j = 0; j < nbTaches; j++)
    {
        if (deb[j] >= dispo)
        {
            k++;
            dispo = fin[j];
            tacheSelected[j] = true;
        }
        else
        {
            tacheSelected[j] = false;
        }
    }
}
