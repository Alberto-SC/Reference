#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod  = 1e9+7;

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
signed main(){__
	int t= 1,n,x,q;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        cin>>q;
        for(int i = 0;i<q;i++){
            cin>>x;
            vector<int> nw(nums.begin(),nums.end());
            for(auto c:nums)nw.push_back(c);
            nums = nw;
            int ans = 0;
            for(int i = 0;i<nw.size();i++){
                ans+=nw[i];
                ans%=mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}  
