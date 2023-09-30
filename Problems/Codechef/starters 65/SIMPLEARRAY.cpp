#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;

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
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c,c%=k;
        vector<int> f(k);
        for(int i = 0;i<n;i++){
            f[nums[i]]++;
        }
        int ans = f[0]+1;
        int sz = 0;
        if(k&1){
            sz = k/2;
        }
        else{
            sz = (k/2)-1;
            ans*=f[k/2]+1;
        };
        for(int i = 1;i<=sz;i++){
            int x = ans;
            ans =((x*(mod_pow(2,f[i])+mod_pow(2,f[k-i]))%mod))-x;
            if(ans<0)ans+=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}