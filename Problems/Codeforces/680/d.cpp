#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
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
int main(){__
    int t = 1,n;
    cin>>n;
    calc();
    vector<int> nums(2*n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    lli sum = 0;
    for(int i = 0;i<n;i++){
        (sum+=abs(nums[i]-nums[i+n]))%=mod;
    }
    lli ans = ncr(2*n,n);
    (ans*=sum)%=mod;
    cout<<ans<<endl;
    return 0;
}

