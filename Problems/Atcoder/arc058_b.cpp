#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int M = 1e6;
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


signed main(){__
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  int ans = 0;
  calc();
  for(int i = 1;i<=h-a;i++){
    int x = ncr((i+b)-2,i-1);
    int y = ncr((h-(i-1))+(w-b)-2,(h-(i-1))-1);
    ans+=(x*y)%mod;
    ans%=mod;
  }
  cout<<ans<<endl;
  return 0;
}
