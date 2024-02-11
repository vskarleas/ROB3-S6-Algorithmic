/* structure is used to return two values from minMax() */
#include<stdio.h>

//EXO1.1
void get_min_max_1(int* tab, int n, int* min, int* max){
//TODO
}

//EXO1.2
void get_min_max_rec(int* tab, int from, int to, int* min, int * max){
//TODO  
}

void get_min_max_2(int* tab, int n, int* min, int* max){
get_min_max_rec(tab, 0, n-1, min, max);
}
