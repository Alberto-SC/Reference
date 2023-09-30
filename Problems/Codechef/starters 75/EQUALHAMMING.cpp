#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

const int M = 1e6;
vector<int> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
int ncr(int n, int r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = (int)fact[i-1] * i % mod;
		inv[i] = mod - (int)inv[mod % i] * (mod / i) % mod;
		invfact[i] = (int)invfact[i-1] * inv[i] % mod;
	}
}


signed main(){__
    int T = 1,n;
    cin>>T;
    calc();
    while(T--){
        cin>>n;
        string s,t;
        cin>>s>>t;
        int cont = 0,diff = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== t[i])cont++;
            else diff++;
        }

        if(diff&1){
            cout<<0<<endl;
        }
        else{
            int ans = mod_pow(2,cont);
            int y = ncr(diff,diff/2);
            ans*=y;
            ans%=mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}