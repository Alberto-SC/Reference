#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 1e6;
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

signed main(){__
	int t= 1,n;
    calc();
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> dp(n+1);
    dp[1]  = 1;
    dp[2] = 2;
    for(int i = 3;i<=n;i++){
        for(int j = 1;j<=i-1;j++){
            cout<<"j: "<<j<<" "<<ncr(i-1,j-1)<<" "<<endl;
            dp[i]+=ncr(i-1,j-1)*dp[j];
        }
        cout<<endl;
    }
    cout<<dp[n]<<endl;
    return 0;
}  
