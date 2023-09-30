#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod = 10000007;

lli mod_pow(lli a, lli n){
	lli x = 1;
	while(n){
		if(n & 1)	x = (x*a)%mod;
		a = (a*a)%mod;
		n >>= 1;
	}
	return x;
}

int main(){
    lli n,k,s1,s2,s3,s4;
    while(cin>>n>>k){
        if(n == 0&& k == 0)break;
        s1 = mod_pow(n,k);
        s2 = mod_pow(n,n);
        s3 = (2*mod_pow(n-1,k))%mod;
        s4 = (2*mod_pow(n-1,n-1))%mod;
        cout<<(s1+s2+s3+s4)%mod<<endl;    
    }
    return 0;
}