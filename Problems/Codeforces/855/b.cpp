#include <bits/stdc++.h>
#define ing long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        string s;
        cin>>s;
        map<char,pair<int,int>> mp;
        for(auto c:s){
            if(c <='z' && c>='a')
                mp[c].first++;
            else 
                mp[tolower(c)].second++;
        }

        int ans = 0;
        for(auto &c:mp){
            int can = abs(c.second.first-c.second.second)/2;
            int x = min(can,m);
        
            ans+=min(c.second.first,c.second.second)+x;
            m-=x;
        }
        cout<<ans<<endl;
    }
    
}

