/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Sparse table is similar to segment tree but don´t allows updates
 * Time: $O(1)$ per query, $O(N \log N)$ build
 * Status: stress-tested
 */

#define MAXN 1000000
#define MAXPOWN 1048576		// 2^(ceil(log_2(MAXN)))
#define MAXLEV 21			// ceil(log_2(MAXN)) + 1
int n, P, Q;
int A[MAXPOWN];
int table[MAXLEV][MAXPOWN];
int maxlev, siz

size = n;
maxlev = __builtin_clz(n) ^ 31;		// floor(log_2(n))
if( (1<<maxlev) != n)
    size = 1<<++maxlev;

void build(int level=0,int l=0, int r=size){
  int m = (l+r)/2;
  
  table[level][m] = A[m]%P;
  for(int i=m-1;i>=l;i--)
    table[level][i] = (long long)table[level][i+1] * A[i] % P;
    
  if(m+1 < r) {
    table[level][m+1] = A[m+1]%P;
    for(int i=m+2;i<r;i++)
      table[level][i] = (long long)table[level][i-1] * A[i] % P;
  }
  if(l + 1 != r)		// r - l > 1
  {
    build(level+1, l, m);
    build(level+1, m, r);
  }
}

int query(int x, int y)
{
  if(x == y)
    return A[x]%P;
  int k2 = __builtin_clz(x^y) ^ 31;
  int lev = maxlev - 1 - k2;
  int ans = table[lev][x];
  if(y & ((1<<k2) - 1))	// y % (1<<k2)
    ans = (long long)ans *  table[lev][y] % P;
  return ans;
}