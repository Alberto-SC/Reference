#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

const int M = 1e6;
const int mod = 998244353;

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
    calc();
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        int t = n/3;

        int ans = ncr(t,t/2);

        for(int i = 0;i<n;i+=3){
            vector<int> d;
            d.push_back(nums[i]);
            d.push_back(nums[i+1]);
            d.push_back(nums[i+2]);

            sort(d.begin(),d.end());
            if(d[0] == d[1]  && d[1]==d[2])
                ans*=3;
            else if(d[0] == d[1])
                ans*=2;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
