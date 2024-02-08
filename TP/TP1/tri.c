#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tri.h"
#include "utile.h"

/* EXERCICE 2 : TRI PAR INSERTION */
void tri_ins(int *tab, int n)
{
  int key, index;
  /* The idea is simple: If key is greater than the current element in the sorted sub-array, move forward.
     If key is smaller than the current element, shift all elements from this position onwards one position
     to the right to create a space for key. */
  for (int i = 1; i < n; i++)
  { // Change to `i < n` to include the last element
    key = tab[i];
    index = i - 1;
    while (index >= 0 && tab[index] > key)
    {
      tab[index + 1] = tab[index];
      index--;
    }
    tab[index + 1] = key;
  }
}

/*EXERCICE 3 : TRI FUSION */
/* Structure of the functions: The fusion function handles the merging of two sorted subarrays.
   The tri_fusion_bis function recursively divides the array into smaller subarrays and calls
   fusion to merge them and tri_fusion function starts the sorting process by calling tri_fusion_bis
   for the entire table. */
void fusion(int *tab, int deb1, int fin1, int deb2, int fin2)
{
  int n1 = fin1 - deb1 + 1; // Number of elements in the first part
  int n2 = fin2 - deb2 + 1; // Number of elements in the second part

  int temp[n1 + n2]; // Temporary array to save the merging process

  int i = 0, j = 0, k = 0; // Indices for the subarrays and temporary array

  // Comparison and merging on the same time
  while (i < n1 && j < n2)
  {
    if (tab[deb1 + i] <= tab[deb2 + j])
    {
      temp[k++] = tab[deb1 + i];
      i++;
    }
    else
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

  /* The merged elements in the temporary array need to be copied back to the original
     array tab at their correct positions, starting from deb1 (explanation below) */
  for (i = 0; i < n1 + n2; i++)
  {
    tab[deb1 + i] = temp[i]; // we need every time to start form where we had stopped the treatment of every sub-array the previous time. Meaning like when we finish the treatment of a branch, starting from his start we sorted the elements and we copy the previous branches that were not treated yet in order to get treated on anoher reccursif itteration
  }
}

/* Process: It divides to table to sub-tables (branches) by giving their start and end point.
   If the table passed on argument has more than one element we find the middle amd we call the
   function recursively on that - until we reach the limit (one element) and we merge while
   sorting on the opposite direction */
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

/*EXERCICE 4 : TRI PAR ENUMERATION */
/* The idea is: In this algorithm, we count every element in an array to
 find out how many elements in an array are less than the current element.
 From that, we can get the position of the current element in a sorted array.
 Then, we put this element in that position. We repeat this process for all
 elements in an array to get a sorted array. */
void tri_enum(int *tab, int n)
{
  int key = tab[0]; // the we wil compare with that we consider as our maximum
  for (int i = 1; i < n; i++)
  {
    if (tab[i] > key)
    {
      key = tab[i]; // finding the "correct" max
    }
  }

  int counts[key + 1]; //
  for (int i = 0; i <= key; i++)
  {
    counts[i] = 0; // Intializing the counts table
  }

  // This essentially counts how many times each unique value appears in the original array.
  for (int i = 0; i < n; i++)
  {
    counts[tab[i]]++;
  }

  // Calculating the final position for each element
  /* How it works: This is done by iterating through the counts table created above.

    For each element counts[i], the algorithm adds the previous count counts[i-1] to it. This is
    accumulating the count of all elements less than or equal to the current value i.
    By the end of this iteration, each element counts[i] in the counts array now represents
    the total number of elements that are strictly less than i in the original array (that exist before it). */
  for (int i = 1; i <= key; i++)
  {
    counts[i] += counts[i - 1];
  }

  // Temporary table for treatment
  int sorted[n];
  for (int i = n - 1; i >= 0; i--) //We start from the end and we go back to the beginning
  {
    int position = counts[tab[i]] - 1;
    sorted[position] = tab[i]; //placing the element on the final position that was found beforehand
    counts[tab[i]]--; //in case that we have more times the same item in the table, we need to increment 
    //the number_of_times that we saw it in order to be placed on the correct position (otherwise we 
    //would place it always on the same position and that would have no effect on sorting)
  }

  // Copying sorted results back to our main table passed as argument
  for (int i = 0; i < n; i++)
  {
    tab[i] = sorted[i];
  }
}

/*EXERCICE 5 : TRI PAR BASE */
void tri_base(int *tab, int n)
{
  /*TODO*/
}
