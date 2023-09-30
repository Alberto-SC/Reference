#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
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
	int t= 1,n;
    calc();
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        int x = (1ll<<32)-1;
        for(auto &c:nums)cin>>c,x&=c,mp[c]++;
        int ans = fact[n-2];
        (ans*=ncr(mp[x],2))%=mod;
        (ans*=2)%=mod;
        cout<<ans<<endl;
    }
    return 0;
}  
