#ifndef H_MAXSUBARRAY
#define H_MAXSUBARRAY

int maxSubArraySum1(int* tab, int n);

int maxSubArraySum2(int* tab, int n);

int maxSubArrayMid(int* tab, int from1, int to1, int from2, int to2);

int maxSubArraySumRec(int* tab, int from, int to);

int maxSubArraySum3(int* tab, int n);

void maxSubArraySumRec2(int* tab, int from, int to, int* stem, int* pref, int* suff, int* tota);

int maxSubArraySum4(int* tab, int n); 

#endif