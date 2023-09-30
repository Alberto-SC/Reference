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
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c,mp[c]++;
        if(n&1)
            cout<<"Second"<<endl;
        else{
            bool flag = true;j
            for(auto c:mp){
                if(c.second&1)flag = false;
            }
            if(!flag)cout<<"First"<<endl;
            else cout<<"Second"<<endl;
        }
    }
    return 0;
}