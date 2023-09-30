#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;

vector<int> graph[maxn];
vector<int> in(maxn);
vector<int> out(maxn);
vector<int> dp(maxn,-1);

int dfs(int u){
    if(out[u]<=1)return dp[u] = 1;
    dp[u] = 1;
    int mx = 0;
    for(auto v:graph[u]){
        if(in[v]>1){
            if(dp[v]!=-1)mx = max(mx,dp[v]);
            else mx = max(mx,dfs(v));
        }
    }
    dp[u]+=mx;
    return dp[u];
}

signed main(){__
    int T = 1,n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        in[v]++;
        out[u]++;
    }

    for(int i = 0;i<n;i++){
        if(dp[i]==-1){
            dfs(i);
        }
    }

    int ans = 0;
    for(auto c:dp)ans = max(ans,c);
    cout<<ans<<endl;

    return 0;
}