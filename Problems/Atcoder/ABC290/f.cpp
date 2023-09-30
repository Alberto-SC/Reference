#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define lli long long
using namespace std;



const int M = 1e6;
const lli mod = 998244353;
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

signed main(){__
		int T = 1,n;
		cin>>T;
		calc();
		while(T--){
				cin>>n;
				
				if(n == 2){
						cout<<1<<endl;
						continue;
				}
				int ans = 0;
				for(int x = 2;x<n;x++){
						int y = (n-x)+1;
						/* cout<<y<<" "; */
						int z = ncr(n-3,n-x-1);
						/* cout<<z<<endl; */
						(y*=z)%=mod;
						(y*=ncr(n,x))%=mod;
						/* (y*=fact[n])%=mod; */
						/* (y*=invfact[x])%=mod; */
						(ans+=y)%=mod;
				}
				cout<<ans<<endl;
		}
}
