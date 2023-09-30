#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int mod = 1e9+7;

int modPow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int gcd = 0;
        for(auto &c:nums)cin>>c,gcd=__gcd(gcd,c);

        int ans = 1;
        for(int i = 0;i<n;i++){
            (ans*=modPow(nums[i],gcd))%=mod; 
        }
        cout<<ans<<endl;
    }
    return 0;
}   