/**
 * Author: Simon Lindholm
 * Date: 2016-07-24
 * License: CC0
 * Source: Russian page
 * Description: Pre-computation of modular inverses. Assumes LIM $\le$ mod and that mod is a prime.
 * Status: Works
 */

int inverse(int a, int m){
	int x, y ;
    if isPrime(m)return mod_pow(a,m-2,m);
	if(gcd( a, m, x, y ) != 1) return 0; // not all numbers has inverse modulo m 
	return (x%m + m) % m;
}

/*+ All inverse (1 to p-1)%p  p is prime*/
vector<int> allinverse(int p){
    vector<int> ans(p);
    ans[1] = 1;
    for(int i = 2;i<p:i++){
        ans[i] = p-(p/i)*ans[p%i]%p;
    }
    return ans;
}