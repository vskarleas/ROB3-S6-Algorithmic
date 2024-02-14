#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fusion(int *tab, int deb1, int fin1, int deb2, int fin2)
{
  int n1 = fin1 - deb1 + 1; //How many on the left part
  int n2 = fin2 - deb2 + 1; //and how about the right part

  int temp[n1 + n2]; // Temporary array to save the process

  int i = 0;
  int j = 0;
  int k = 0;

  // Comparison and merging on the same time
  while (i < n1 && j < n2)
  {
    if (tab[deb1 + i] <= tab[deb2 + j]) //we are before the merge "interclassement" of the two tables so we are on the left part right now
    {
      temp[k++] = tab[deb1 + i];
      i++;
    }
    else //otherwise we are on the right part
    {
      temp[k++] = tab[deb2 + j];
      j++;
    }
  }


  // Copying any remaining elements
  while (i < n1)
  {
    temp[k++] = tab[deb1 + i];
    i++;
  }

  while (j < n2)
  {
    temp[k++] = tab[deb2 + j];
    j++;
  }

  for (i = 0; i < n1 + n2; i++)
  {
    tab[deb1 + i] = temp[i]; // we need every time to start form where we had stopped the treatment of every sub-array the previous time. Meaning like when we finish the treatment of a branch, starting from his start we sorted the elements and we copy the previous branches that were not treated yet in order to get treated on anoher reccursif itteration
  }
}

void tri_fusion_bis(int *tab, int deb, int fin)
{
  if (deb < fin)
  {
    int mid = (deb + fin) / 2;
    tri_fusion_bis(tab, deb, mid);       // Sorting the left part
    tri_fusion_bis(tab, mid + 1, fin);   // now the right part
    fusion(tab, deb, mid, mid + 1, fin); // Merging the sorted subarrays
  }
}

void tri_fusion(int *tab, int n)
{
  tri_fusion_bis(tab, 0, n - 1);
}

void median(int *tab, int n)
{
    tri_fusion(tab, n);
    if (n % 2 == 0)
    {
        printf("Median number are: %d and %d\n", tab[(n/2)-1], tab[n/2]);
    }
    else
    {
        printf("Median number is: %d\n", tab[n/2]);
    }
}
