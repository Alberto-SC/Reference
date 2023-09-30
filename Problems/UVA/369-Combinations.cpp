#include <stdio.h>
#define MAXN    100
unsigned long int t[MAXN+1][MAXN+1];
int main (void) {
    int n, k;

    for (k = 0; k<=MAXN; k++) t[0][k] = 0;
    for (n = 1; n<=MAXN; n++) t[n][0] = 1;

    t[1][1] = 1;
    for (n = 2; n<=MAXN; n++) {
        for (k = 1; k < n; k++)
            t[n][k] = t[n-1][k-1] + t[n-1][k];
        t[n][n] = 1;
    }

    while (scanf ("%d %d", &n, &k), (n || k))
        printf ("%d things taken %d at a time is %lu exactly.\n", n, k, t[n][k]);

    return 0;
}