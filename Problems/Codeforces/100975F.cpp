#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 lli mod_mult (lli a, lli b, lli mod)
{
  lli x = 0;
  while (b)
    {
      if (b & 1)
	x = (x + a) % mod;
      a = (a << 1) % mod;
      b >>= 1;
    }
  return x;
}

lli mod_pow (lli a, lli n, lli mod)
{
  lli x = 1;
  while (n)
    {
      if (n & 1)
	x = mod_mult (x, a, mod);
      a = mod_mult (a, a, mod);
      n >>= 1;
    }
  return x;
}

lli phi (lli n)
{
  lli result = n;
  for (int i = 2; i * i <= n; i++)
    {
      if (n % i == 0)
	{
	  while (n % i == 0)
	    n /= i;
	  result -= result / i;
	}
    }
  if (n > 1)
    result -= result / n;
  return result;
}

int
main ()
{
  lli n, k;
  cin >> n >> k;
  lli pk = phi (k);
  lli pow = mod_pow (2, n, pk);
  if (n <= 31 && ((1ll << n) < pk))
    {
	    
