#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: A few ways to calc a binomial coeficient with diferent complexityes
 * Time:  Varios complexities
 */

/********************************************************
    Binomial coeficients
 *  Computes ${N}\choose{k}$
*********************************************************
/*+ If you can know that the result don´t overflow and don´t need MOD */
long binomial_Coeff_without_MOD(int n,int r){
    long ans = 1;
    for(int i = 1;i<=min(n-k,k);i++){
        ans = (ans* (n-(i-1)))/i;
    }
    return ans;
}
/* O(n) solutions
    Based in the prof of C(n,k) = C(n-1,k-1) + C(n-1,k)
    Also calc all C(n,i) for 0<=i<=n
*/

long binomial_Coeff(int n,int m){ 
	int i,j;
	long bc[MAXN][MAXN];
	for (i=0; i<=n; i++) bc[i][0] = 1;
	for (j=0; j<=n; j++) bc[j][j] = 1;
	for (i=1; i<=n; i++)
	    for (j=1; j<i; j++)
	        bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return bc[n][m];
}

/*
    O(k) solution
    Only calc C(n,k)
*/
int binomial_Coeff_2(int n, int k)  {  
    int res = 1;  
    if ( k > n - k )  
        k = n - k;  
    for (int i = 0; i < k; ++i){  
        res *= (n - i);  
        res /= (i + 1);  
    }  
    return res;  
}
/*   Factorial modulo P */
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
/*+ O(1) binomial coeficient with precalc in O(n) */
const int M = 1e6;
const lli mod = 986444681;
vector<lli> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
lli ncr(lli n, lli r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (lli)fact[i-1] * i % mod;
		inv[i] = mod - (lli)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (lli)invfact[i-1] * inv[i] % mod;
	}
}
/*+ Lucas Theorem: Computes C(N,R)%p in O(log(n)) if P is prime */
/*+ call calc() first */


lli Lucas(lli N,lli R){
	if(R<0||R>N)
		return 0;
	if(R==0||R==N)
		return 1ll;
	if(N>=mod)
		return (1ll*Lucas(N/mod,R/mod)*Lucas(N%mod,R%mod))%mod;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
/* Using calc() we can also calculate P(n,k) (permutations)  */
lli permutation(int n,int k){
    return (1ll*fact[n]* invfact[n-k])%mod;
}

/*+  Cayley's formula: Computes all posibles trees whit n nodes */
lli cayley(int n ,int k){
    if(n-k-1<0)
        return (1ll*k*modpow(n,mod-2))%mod;
    return (1ll*k*modpow(n,n-k-1))%mod;
}
