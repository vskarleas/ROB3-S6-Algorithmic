// A Divide and Conquer based program for maximum subarray sum problem
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "maxsubarray.h"
#include "utile.h"

// EXO2.1
int maxSubArraySum1(int *tab, int n)
{
   int max;
   get_max(tab, n, &max);
   int temp = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = i; j < n; j++)
      {
         for (int k = i; k <= j; k++)
         {
            temp = temp + tab[k];
         }
         if (temp > max)
         {
            max = temp;
         }
      }
   }
   
   return max;
}

// EXO2.2
int maxSubArraySum2(int *tab, int n)
{
   int max_current = tab[0], res = tab[0];
    for (int i = 1; i < n; i++) {
        /*if tab[i] > max_current + tab[i] then we don't get into another loop 
          (meaning that we don;t have boucles imbriques - we just search the table 
          leanearily and we see if we can do the sum of the current element + local_maximum 
          (max_current), if the conditions are met)*/
        if (tab[i] > max_current + tab[i])
        {
         max_current = tab[i];
        }
        else
        {
         max_current = max_current + tab[i];
        } //comparison between the global maximum (res) and the current maximum (max_current)
        if (res < max_current)
        {
         res = max_current;
        }
    }
    return res;
}

// EXO2.4
int maxSubArrayMid(int *tab, int from1, int to1, int from2, int to2)
{
   int res = 0;
   // TODO
   return res;
}

int maxSubArraySumRec(int *tab, int from, int to)
{
   int res = 0;
   // TODO
   return res;
}

int maxSubArraySum3(int *tab, int n)
{
   int res = maxSubArraySumRec(tab, 0, n - 1);
   return res;
}

// EXO2.6
void maxSubArraySumRec2(int *tab, int from, int to, int *stem, int *pref, int *suff, int *tota)
{
   // TODO
}

int maxSubArraySum4(int *tab, int n)
{
   int res;
   int pref;
   int suff;
   int tota;
   maxSubArraySumRec2(tab, 0, n - 1, &res, &pref, &suff, &tota);
   return res;
}
