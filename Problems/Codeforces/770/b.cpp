#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(x&1){
            if(y&1 &&s%2==0)cout<<"Alice"<<endl;
            else if(y%2==0 && s&1)cout<<"Bob"<<endl;
        }       
        else{
            
        }

    }
    return 0;
}