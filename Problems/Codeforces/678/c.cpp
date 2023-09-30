#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int M = 2000;
const lli mod = 1e9+7;
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
    int t = 1,n,x,pos;
    calc();
    while(t--){
        cin>>n>>x>>pos;
        vector<int> a(n);
        int mn = 0,mx = 0;
        iota(a.begin(),a.end(),0);
        int l = 0,r = n;
        while(l<r){
            int mid = (l+r)>>1;
            if(a[mid] <= pos){
                if(a[mid] < pos)
                    mn++;
                l = mid+1;
            }
            else{
                r = mid;
                mx++;
            }
        }
        lli ans = ncr(x-1,mn);
        (ans*= fact[mn])%=mod;
        (ans*= ncr(n-x,mx))%=mod;
        (ans*= fact[mx])%=mod;
        (ans*= fact[n-(mn+1+mx)])%=mod;
        cout<<ans<<endl;
    }
    return 0;
}

