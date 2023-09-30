#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int M = 1e6;
const lli mod = 1e9+7;
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

int main(){__
	int t= 1,n,a,b;
    calc();
    vector<lli> pre[10007];
    for(int i = 1;i<=10000;i++){
        pre[i].push_back(0);
        for(int j = 1;j<=i;j++){
            pre[i].push_back(ncr(i,j)+pre[i].back());
        }
    }
    cin>>t;
    while(t--){
        cin>>n>>a>>b;
        if(b>n)b = n;
        if(a>n)cout<<0<<endl;
        else{
            lli ans = pre[n][b]-pre[n][a-1];
            if(ans<0)ans+=mod;
            ans%=mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}  

