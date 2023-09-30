#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int sz = 100007;
signed main(){__
	int t= 1,n,w,wr;
    cin>>t;
    while(t--){
        cin>>n>>w>>wr;
        vector<int> nums(n);
        w-=wr;
        map<int,int>mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        for(auto d:mp){
            w-= d.first*d.second;
            if(d.second&1)w+=d.first;
        }
        if(w<=0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  
