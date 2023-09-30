#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

map<int,int> mp;
int N;
int dp[1ll<<17][17];

const int inf = 1e18;
vector<pair<int,int>> graph[17];
int solve(int mask,int u){
    if(mask == (1<<N)-1)return 0;
    int &x = dp[mask][u];
    if(x!=-1)return x;

    int ans = inf;
    for(auto v:graph[u]){
        if((mask>>v.first)&1)continue;
        ans = min(ans,solve(mask|(1<<v.first),v.first)+v.second);
    }
    return x = ans;
}

signed main(){__
    int m,x,u,v,w;
    cin>>N>>m>>x;
    int key = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<m;i++){
        cin>>u>>v>>w;
        if(!mp.count(u))
            mp[u] = key++;
        if(!mp.count(v))
            mp[v] = key++;
        graph[mp[u]].push_back({mp[v],w});
        graph[mp[v]].push_back({mp[u],w});
    }
    int ans = solve(1<<mp[x],mp[x]);
    if(ans ==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}

