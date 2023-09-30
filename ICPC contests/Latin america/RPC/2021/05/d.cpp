#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> c(maxn);
vector<int> w(maxn);
vector<int> dp(maxn);
int ans = 0;
void dfs(int u,int p = -1){
    if(p!=-1)
        dp[u] = c[u]-w[u]+max(0ll,dp[p]-c[u]);
    ans = min(ans,dp[u]);
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u);
    }
}

signed main(){__
	int t= 1,n,p,need;
    while(t--){
        cin>>n>>need;
        dp[0] = need;
        ans = need;
        for(int i = 1;i<=n;i++){
            cin>>p>>c[i]>>w[i];
            graph[i].push_back(p);
            graph[p].push_back(i);
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}  
