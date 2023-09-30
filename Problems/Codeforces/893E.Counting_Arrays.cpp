#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;
lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
const int M = (1e6) +200;
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
const int N = 10000000;
int lp[N+1];
vector<int> primes;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back (i);
        }
        for (int j=0; j<(int)primes.size() && primes[j]<=lp[i] && i*primes[j]<=N; ++j)
            lp[i * primes[j]] = primes[j];
    }
}

map<int,int> factors;
void factorize(int n){
    while(n>1){
        factors[lp[n]]++;
        n/=lp[n];
    }
}
int main(){
    int t,x,y;
    calc();
    criba();
    cin>>t;
    while(t--){
        cin>>x>>y;
        factors.clear();
        factorize(x);
        lli ans = mod_pow(2,y-1);
        for(auto c:factors)
            (ans*=ncr(c.second+y-1,y-1))%=mod;
        
        cout<<ans<<endl;
    }

    return 0;
}