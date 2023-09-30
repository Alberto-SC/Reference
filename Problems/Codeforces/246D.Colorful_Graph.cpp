#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,m,u,v;
    cin>>n>>m;
    map<int,set<int>> mp;
    vector<int> c(n);
    for(auto &x:c)cin>>x;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        if(c[u]!= c[v])mp[c[u]].insert(c[v]),mp[c[v]].insert(c[u]);
    }
    int ans = 100007,mx = -1;
    for(auto c:mp){
        if((int )c.second.size()>mx){
            mx = c.second.size();
            ans =c.first;
        }
        if((int )c.second.size() == mx && c.first<ans){
            ans = c.first;
        }
    }
    if(ans == 100007)cout<<*min_element(c.begin(),c.end());
    else cout<<ans<<endl;
    return 0;
}