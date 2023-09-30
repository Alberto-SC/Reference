#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = (1e9)+7;
lli mod_mult(lli a, lli b){
	lli x = 0;
	while(b){
		if(b & 1)	x = (x + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return x;
}
lli pow_mod(lli a, lli n){
	lli x = 1;
	while(n){
		if(n & 1)	x = mod_mult(x, a);
		a = mod_mult(a, a);
		n >>= 1;
	}
	return x;
}

int main(){__
    lli t = 1,n;

    while(t--){
        cin>>n;
        lli ans = pow_mod(10,n)-pow_mod(9,n)-pow_mod(9,n)+pow_mod(8,n);
        ans%=mod;
        ans = (ans+mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}

