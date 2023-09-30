/**
 * Author: Simon Lindholm
 * Date: 2015-06-23
 * License: CC0
 * Source: own work
 * Description: Sum of aritmetic floor division
 *
 * \texttt{f(a, b, c, n)} = $\sum_{i=0}^{\mathrm{n}}{\lfloor \frac{(a i + b)}{c} \rfloor }$.
 * Time: $\log(a)$, 
 * Status: Tested for all |k|,|c|,to,m <= 50, and on kattis:aladin
 */
#pragma once

int f(int a, int b, int c, int n){
	int m = (a*n + b)/c;
	if(n==0 || m==0) return b/c;
	if(n==1) return b/c + (a+b)/c;
	if(a<c && b<c) return m*n - f(c, c-b-1, a, m-1);
	else return (a/c)*n*(n+1)/2 + (b/c)*(n+1) + f(a%c, b%c, c, n);
}

// $\sum_{k=1}^{n}{\lfloor \frac{n}{k} \rfloor)}$
int floor_sum(int n) {
  int sum = 0;
  for (int i = 1, last; i <= n; i = last + 1) {
    last = n / (n / i);
    sum += (n / i) * (last - i + 1);
  }
  return sum;
}