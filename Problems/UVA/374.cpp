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
lli mod_pow(lli a,lli b, lli m){
    lli x=1;
    while(b){
        if(b&1) x = mod_mult(x,a,m);
        a = mod_mult(a,a,m);
        b>>=1;
    }
    return x;
}
int main(){
    long long B,P,M;
    while(cin>>B>>P>>M){
            cout<<mod_pow(B,P,M)<<endl;
    }
    return 0;
}