#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int lli;
const int md  = 998244353;
// #define MOD(a) fmod(fmod(a,md)+md,md)
#define MOD(n) ( ( ((n) % (md)) + (md) ) % (md))
vector<lli> nums;
lli mod_pow(lli a, lli b, lli m) {
    lli res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}
lli inverse(lli a, lli m){
    return mod_pow(a,m-2,m);
}
const int maxn = 200007;
vector<lli> inv(maxn);

void precalc(lli n){
    for(lli i = 1;i<=n;i++){
        for(lli j = 1;j<=n;j++){
            if(j == i)continue;
            lli x = i-j;
            inv[((x<0) *n) + abs(x)] = inverse(x,md);
        }
    }
}
int N;
lli Lagrange(lli n){
    lli res = 0;
    for(lli i = 1;i<=n;i++){
        lli  res2 = 1;
        for(lli j = 1;j<=n;j++){
            if(j != i){
                lli k = i-j;
                lli x = MOD(MOD(-j)*MOD(inv[((k<0) *N) + abs(k)])); 
                res2 = MOD(MOD(res2)*MOD(x));
            }
        }
        lli z = MOD(res2);
        lli y = MOD(z*nums[i-1]);
        res= MOD(res+y);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    lli n;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    lli mn = min(1007ll,n);
    N = mn;
    precalc(mn);
    lli real = Lagrange(mn);
    
    lli l = 1,r = mn;
    while(l<=r){
        lli m = (l+r)>>1;
        if(Lagrange(m) == real){
            r = m-1;
        }
        else 
            l = m+1;
    }
    cout<<fixed<<setprecision(0);
    cout<<r+1<<" ";
    cout<<real<<endl;
    // cout<<fmod(-10,md);
    return 0;
}

