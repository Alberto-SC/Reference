#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int M = 1e6+7;
const int mod = 1e9+7;
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
    calc();
    while(cin>>n>>k){
        int x =ncr(n-1,k);
        x*=2;
        x%=mod;
        cout<<x<<endl;
    }
    return 0;
}