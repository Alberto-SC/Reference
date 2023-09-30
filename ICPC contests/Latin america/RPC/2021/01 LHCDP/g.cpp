#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9;
lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

int main(){__
	lli t= 1,n,x,q;
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<q;i++){
            cin>>x;
            lli who = x%n;
            lli pot = x/n;
            lli ans = mod_pow(nums[who],pot+1);
            if(ans<0)ans+=mod;
            ans%=mod;
            cout<<ans<<endl;
        }
    }
    return 0;
}  

