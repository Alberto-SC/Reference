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
int trail(lli a,lli b,int n){
    lli ntrail = pow(10,n);
    return mod_pow(a,b,ntrail);
} 
int leading(lli a,lli b,lli n){
    n--;
    lli nleading = mod_pow(10,n,10000000000);
    return (int)(pow(10, fmod(b*log10(a), 1))*nleading);
}
int main(){
    int a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int tr =  trail(a,b,3);
        int le = leading(a,b,3);
        // cout<<log10(a)<<"  ";
        // cout<<fmod(b*log10(a), 1)<<"  ";
        // cout<<pow(10, fmod(b*log10(a), 1))<<endl;
        printf("%d...%03d\n",le,tr);
    }
    return 0;
}