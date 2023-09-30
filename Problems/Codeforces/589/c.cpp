#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;
const int mod = 1000000007;
const lli MAXN = 1000000000000000000;
map<lli,lli> fact;
lli mod_pow(lli a, lli n,lli mod){
	lli x = 1;
	while(n){
		if(n & 1)	x = (x* a)% mod;
		a = (a*a)% mod;
		n >>= 1;
	}
	return x;
}
void trial_division2(lli n) {
    while (n % 2 == 0) {
        fact[2]++;
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2) {
        while (n % d == 0) {
            fact[d]++;
            n /= d;
        }
    }
    if (n > 1)
        fact[n]++;
}
int main(){
    lli x,n;
    cin>>x>>n;
    trial_division2(x);
    lli ans =1;
    for(auto c:fact){
        lli pot = 0;
        lli i = 1;
        lli anterior = c.first;
        while(anterior<=(lli)(MAXN/c.first)){
            anterior = mod_pow(c.first,i,MAXN); 
            pot+=(lli)(n/anterior);
            i++;
        }
        ans = (ans*mod_pow(c.first,pot,mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
