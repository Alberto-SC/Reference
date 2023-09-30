#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod_mult(lli a, lli b, lli mod){
	lli x = 0;
	while(b){
		if(b & 1)	x = (x + a) % mod;
		a = (a << 1) % mod;
		b >>= 1;
	}
	return x;
}
lli mod_pow(lli a, lli n, lli mod){
	lli x = 1;
	while(n){
		if(n & 1)	x = mod_mult(x, a, mod);
		a = mod_mult(a, a, mod);
		n >>= 1;
	}
	return x;
}
int main(){
    int t,n,c,e;
    cin>>t;
    while(t--){
        cin>>e>>n>>c;
        for(int i = 0;i<n;i++){
            // cout<<i<<"  "<<mod_pow(i,e,n)<<" "<<n%c<<endl;
            if(mod_pow(i,e,n) == c%n){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}