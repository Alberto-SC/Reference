#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
/*
    Modular exponentitation utility function
*/
lli mod_pow(lli a,lli n){
    lli ans = 1;
    while(n){
        if(n&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        n>>=1;
    }
    return ans;
}


/********************************************************
    Binomial coeficients
 *  Computes C(n,k)
 *  Tested [?]
*********************************************************
 O(n) solutions
    Based in DP 
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
/*
    O(k) solution
    Only calc C(n,k)
*/
int binomial_Coeff_3(int n, int k){ 
    vector<int> C(k+1,0); 
    C[0] = 1;  // nC0 is 1 
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
/*******************************************************
 *   Factorial modulo P
    If only need one factorial 
    O(P logp n)
 *  Tested [?]
********************************************************/
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


/**************************************************************
    Lucas Theorem
 *  Computes C(N,R)%p in O(log(n)) if P is prime
 *  Tested [Codeforces D - Sasha and Interesting Fact from Graph Theory]

***************************************************************
/*
    Precalc 
        -Inverse modular to n
        -Factorial modulo p
        -Inverse modular of factorial 
*/
const int M = 1e6;
const lli mod = 986444681;
vector<lli> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
lli ncr(lli n, lli r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(int m){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (lli)fact[i-1] * i % mod;
		inv[i] = mod - (lli)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (lli)invfact[i-1] * inv[i] % mod;
	}
}


/*
    Lucas Theorem
*/
lli Lucas(lli N,lli R){
	if(R<0||R>N)
		return 0;
	if(R==0||R==N)
		return 1ll;
	if(N>=mod)
		return (1ll*Lucas(N/mod,R/mod)*Lucas(N%mod,R%mod))%mod;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
/*
    Using calc() we can also calculate P(n,k) (permutations)  
*/
lli permutation(int n,int k){
    return (1ll*fact[n]* invfact[n-k])%mod;
}

//   Computes C(N,R)%p 
lli power(lli x, lli y, lli p) { 
    lli res = 1;      
    x = x % p;   
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 

lli modInverse(lli n, lli p) { 
    return power(n, p-2, p); 
} 
  
lli nCrModPFermat(lli n, lli r, lli p) { 
   if (r==0) 
      return 1; 
    lli fac[n+1]; 
    fac[0] = 1; 
    for (lli i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p;   
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

/***********************************************************************
 *  Cayley's formula
 *  Computes all posibles trees whit n nodes
 *  Tested [Codeforces D - Sasha and Interesting Fact from Graph Theory]
************************************************************************/
lli cayley(int n ,int k){
    if(n-k-1<0)
        return (1ll*k*mod_pow(n,mod-2))%mod;
    return (1ll*k*mod_pow(n,n-k-1))%mod;
}

int main(){

    return 0;
}