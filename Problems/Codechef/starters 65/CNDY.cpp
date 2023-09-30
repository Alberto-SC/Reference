#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(2*n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        bool flag = true;
        for(auto c:mp){
            if(c.second>2)flag = false;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}