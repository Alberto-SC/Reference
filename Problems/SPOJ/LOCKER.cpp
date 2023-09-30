#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli mod = 1000000007L;

map<lli,lli> res;


lli mod_pow(lli a, lli n, lli mod){
	lli x = 1;
    lli t = n;
    if(res[t])return res[t];
	while(n){
		if(n & 1)	x = (x*a) %mod;
		a = (a*a)%mod;
		n >>= 1;
	}
	return res[t] = x;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    lli t,n,n1,c,ans;
    cin>>t;
    while(t--){
        cin>>n;
        lli div = 0;
        if(n == 1){cout<<1<<endl;continue;}
        if(n == 0){cout<<0<<endl;continue;}

		lli c = n%3;
		if(c==2) n1 = (n-2)/3;
		else if(c==1) n1 = (n-4)/3;
		else n1 = n/3;
		ans = mod_pow(3,n1,mod);
		if(n%3==2) ans = (ans*2)%mod;
		else if(n%3==1)  ans = (ans*4)%mod;
        cout<<ans<<endl;
    }
    return 0;
}