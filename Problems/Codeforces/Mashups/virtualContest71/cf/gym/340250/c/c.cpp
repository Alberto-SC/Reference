#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 50007;
vector<int> graph[maxn];
int k,ans;
int dp[maxn][507];

void dfs(int u,int p = -1){
    dp[u][0] = 1;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u);
        for(int i = 1;i<=k;i++)
            ans+=dp[u][i-1]*dp[v][k-i];
        for(int i= 1;i<=k;i++)
            dp[u][i] +=dp[v][i-1];
    }
}
signed main(){__
	int t= 1,n,u,v;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}  
