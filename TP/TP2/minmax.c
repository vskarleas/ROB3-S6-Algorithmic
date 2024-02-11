/* structure is used to return two values from minMax() */
#include<stdio.h>

//EXO1.1
void get_min_max_1(int* tab, int n, int* min, int* max){
int max_local=tab[0];
int min_local = tab[0];

for (int i = 1; i<n; i++)
{
    if (tab[i] < min_local)
    { min_local = tab[i];}
    else if (tab[i] > max_local)
    { max_local = tab[i];
        }
}
*min = min_local;
*max = max_local;

}

//EXO1.2
void get_min_max_rec(int* tab, int from, int to, int* min, int * max){

if(from < to)
{
if(to - from == 2)
{if(tab[from]<tab[to]){*min = tab[from]; *max = tab[to];}}
else if(to-from != 2)
{
    int mid = (from + to) / 2;
    get_min_max_rec(tab, 0, mid, min, max);
    get_min_max_rec(tab, mid+1, n-1, min, max);
}
}

}

void get_min_max_2(int* tab, int n, int* min, int* max){
get_min_max_rec(tab, 0, n-1, min, max);
}
