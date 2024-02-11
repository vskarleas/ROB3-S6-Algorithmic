// A Divide and Conquer based program for maximum subarray sum problem
#include <stdio.h>
#include <limits.h>

//EXO2.1
int maxSubArraySum1(int* tab, int n) 
 {  
    int res=0;
    //TODO
    return res;
 }

//EXO2.2
int maxSubArraySum2(int* tab, int n) 
 {
    int res=0;
    //TODO
    return res;
 }

//EXO2.4
int maxSubArrayMid(int* tab, int from1, int to1, int from2, int to2) 
 {
    int res=0;
    //TODO
    return res;
 }


int maxSubArraySumRec(int* tab, int from, int to) 
 {
    int res=0;
    //TODO
    return res;
 }

int maxSubArraySum3(int* tab, int n) 
 {
    int res = maxSubArraySumRec(tab, 0, n-1);
    return res;
 }

//EXO2.6
void maxSubArraySumRec2(int* tab, int from, int to, int* stem, int* pref, int* suff, int* tota) 
 {
  //TODO
 }

int maxSubArraySum4(int* tab, int n) 
 {
    int res; int pref; int suff; int tota; 
    maxSubArraySumRec2(tab, 0, n-1,&res,&pref,&suff,&tota);
    return res;
 }

