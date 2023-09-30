#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int M = 1e6;
const int mod = 998244353 ;
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



signed main(){
    int n,k;
    cin>>n>>k;
    int ans = 0;
    calc();
    for(int i = 1;i<=n;i++){
        int x = n/i;
        x--;
        ans+=ncr(x,k-1);
        ans%=mod;
    }
    cout<<ans<<endl;
}