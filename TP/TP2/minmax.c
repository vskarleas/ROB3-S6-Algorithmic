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
void get_min_max_rec(int* tab, int from, int to, int* min, int* max) {
    if (from == to) {
        // Base case: single element
        *min = *max = tab[from];
    } else if (from < to - 1) { // Corrected condition: to - from > 1
        int mid = (from + to) / 2;
        get_min_max_rec(tab, from, mid, min, max);
        get_min_max_rec(tab, mid + 1, to, min, max);
    } else { // Handle two elements
        if (tab[from] < tab[to]) {
            *min = tab[from];
            *max = tab[to];
        } else {
            *min = tab[to];
            *max = tab[from];
        }
    }
}

void get_min_max_2(int* tab, int n, int* min, int* max){
    *min = INT_MIN;
    *max = INT_MAX;
get_min_max_rec(tab, 0, n-1, min, max);
}

/* Yes, the complexity of your corrected algorithm for finding the minimum and maximum using divide and conquer is indeed **(3/2)n - 2**. Here's why:

* **Break down of operations:**
    * Each recursive call divides the problem size in half, leading to **log(n)** recursive calls in total.
    * In each call, you either compare two elements (in the base case) or make three comparisons (one for dividing the problem and two for recursive calls).
    * Therefore, the total number of comparisons is approximately **3 * log(n)** for the recursive calls and **n - 2** for the base cases (comparing two elements) if n is a power of 2.
* **Overall complexity:**
    * Considering the total number of comparisons, the complexity becomes **3 * log(n) + (n - 2)**.
    * Since log(n) grows slower than n, we can ignore the constant term in the log term for large values of n.
    * Therefore, the dominant term becomes **3 * log(n)**, which simplifies to **(3/2)n - 2**.

However, it's important to note that:

* This complexity holds true only for arrays with lengths that are powers of 2. For non-powers-of-2 lengths, the actual number of comparisons might be slightly higher.
* While your algorithm has a better asymptotic complexity (O(n log n)) compared to a simple linear search (O(n)), it might not always be the fastest choice in practice due to the overhead of function calls and context switching.

If you're dealing with very large arrays and performance is critical, you might consider other, more optimized algorithms specifically designed for finding minimum and maximum values.*/
