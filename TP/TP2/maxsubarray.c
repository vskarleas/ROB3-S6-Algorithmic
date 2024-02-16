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
         temp = 0;
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
   /* Initialisations */
   int max_current = tab[0]; // max local
   int res = tab[0];         // max global (sur le tableau)
   for (int i = 1; i < n; i++)
   {
      if (tab[i] > max_current + tab[i]) // second elemenet is greater than second + first element | third element...
      {
         max_current = tab[i];
      }
      else
      {
         max_current = max_current + tab[i];
      } // comparison between the global maximum (res) and the current maximum (max_current)
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
   int max_left = tab[to1];
   int max_right = tab[from2];

   int res = 0;
   // from right to left
   for (int i = to1; i >= from1; i--)
   {
      res = res + tab[i];
      if (res > max_left)
         max_left = res;
   }

   res = 0;
   // from left to right
   for (int i = from2; i <= to2; i++)
   {
      res = res + tab[i];
      if (res > max_right)
         max_right = res;
   }

   return max_left + max_right;
}

int maxSubArraySumRec(int *tab, int from, int to)
{
   if (to == from) // there is one single element - base case
   {
      return tab[from];
   }

   int res = 0;
   if (from < to)
   {
      int mid = (from + to) / 2;
      int stm1 = maxSubArraySumRec(tab, from, mid);
      int stm3 = maxSubArrayMid(tab, from, mid, mid + 1, to);
      int stm2 = maxSubArraySumRec(tab, mid + 1, to);

      // we find the max between stm1, stm2, stm3
      if (stm1 < stm2)
      {
         res = stm2;
      }
      else
      {
         res = stm1;
      }
      if (res < stm3)
      {
         res = stm3;
      }
   }

   return res;
}

int maxSubArraySum3(int *tab, int n)
{
   int res = maxSubArraySumRec(tab, 0, n - 1);
   return res;
}

// EXO2.6
void maxSubArraySumRec2(int *tab, int from, int to, int *stm, int *pref, int *suff, int *tota)
{
   if (from == to) // One signe element - our base case
   {
      *stm = *pref = *suff = *tota = tab[from];
   }
   else
   {
      int mid = (from + to) / 2;

      // local variables
      int stm1, pref1, suff1, tota1, stm2, pref2, suff2, tota2;

      maxSubArraySumRec2(tab, from, mid, &stm1, &pref1, &suff1, &tota1);
      maxSubArraySumRec2(tab, mid + 1, to, &stm2, &pref2, &suff2, &tota2);

      // Updating global variables
      if (stm1 > stm2)
      {
         *stm = stm1;
      }
      else
      {
         *stm = stm2;
      }

      /* Now testing the suffixes and prefixes */
      if (suff1 + pref2 > *stm)
      {
         *stm = suff1 + pref2;
      }

      if (pref1 > (tota1 + pref2))
      {
         *pref = pref1;
      }
      else
      {
         *pref = tota1 + pref2;
      }

      if (suff2 > (suff1 + tota2))
      {
         *suff = suff2;
      }
      else
      {
         *suff = suff1 + tota2;
      }

      // lastly we are updating the total global variable
      *tota = tota1 + tota2;
   }
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
