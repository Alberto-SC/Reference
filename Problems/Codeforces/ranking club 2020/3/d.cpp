#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 998244353;
const int MAXN =2000007;
lli inv[MAXN];
lli fact[MAXN];
lli invfact[MAXN];
void calc(int m){
    inv[0] = inv[1] = 1;
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i <= m; ++i) {
        inv[i] = (inv[mod % i]* (mod - (mod/i)))%mod;
        fact[i] = (fact[i - 1]* i)%mod;
        invfact[i] = (invfact[i - 1]* inv[i])%mod;
    }
}
/*
    Lucas Theorem
*/
lli Lucas(lli N,lli R){
	if(R<0||R>N)
		return 0;
	if(R==0||R==N)
		return 1ll;
	if(N>=mod)
		return (1ll*Lucas(N/mod,R/mod)*Lucas(N%mod,R%mod))%mod;
	return (1ll* fact[N]*((invfact[N-R]*invfact[R])%mod))%mod;
}
lli modulo(lli a) { return (a % mod + mod) % mod; }
int main(){
    lli n,x,a,b;
    cin>>n>>x>>a>>b;
    vector<lli> nums(n);
    calc(2000000);
    for(auto &c:nums)cin>>c;
    for(int i = 0;i<n;i++){
        if(nums[i]<a && x-(a-nums[i])>=0)x-=a-nums[i],nums[i] = a;
        else if(nums[i]<a && x-(a-nums[i])<0)return cout<<0<<endl,0;
    }
    lli ans1 = Lucas(n+x-1,x);
    for(int i = 0;i<n;i++){
        if(nums[i]<b && x-(b-nums[i])>=0){x-=b-nums[i];nums[i] = b;}
        else if(nums[i]<b && x-(b-nums[i])<0)return cout<<ans1<<endl,0;
    }
    lli ans2 = Lucas(n+x-1,x);
    lli ans = modulo(ans1-ans2);
    cout<<ans<<endl;
    return 0;
}