#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int M = 2e6;
const int mod = 1e9+7;
vector<int> fact(M+1, 1), inv(M+1, 1), invfact(M+1, 1);
int ncr(int n, int r){
	if(r < 0 || r > n) return 0;
	return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}
void calc(){
   	for(int i = 2; i <= M; ++i){
		fact[i] = fact[i-1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		invfact[i] = invfact[i-1] * inv[i] % mod;
	}
}

int mod_pow(int a,int b){
  int x = 1;
  while(b){
    if(b&1)(x*=a)%=mod;
    (a*=a)%=mod;
    b>>=1;
  }
  return x;
}

signed main(){__
  int T,k,n;
  freopen("galactic.in", "r", stdin);
  cin>>T;
  calc();
  while(T--){
    cin>>n>>k;
    if(n<k){
      cout<<0<<endl;
      continue;
    }
    int ans = fact[k]*mod_pow(n-k,k);
    cout<<n-k<<endl;
    cout<<fact[k]<<" "<<mod_pow(n-k,k)<<endl;
    ans%=mod;
    cout<<ans<<endl;
  }

}

