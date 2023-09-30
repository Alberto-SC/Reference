#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn =1007;
vector<int> graph[maxn];
vector<int> d(maxn);
int ans = 0;
vector<bool> vis(maxn);
void dfs(int u){
    vis[u]= true;
    d[u] = 1;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
        d[u] = max(d[u],d[v]+1);
    }
    ans = max(ans,d[u]);
}
signed main(){__
	int t= 1,n,m;
    cin>>n>>m;
    vector<int> nums[m];
    vector<int> pos[m];
    for(int i = 0;i<m;i++){
        nums[i].resize(n);
        pos[i].resize(n+1);
        for(auto &c:nums[i])cin>>c;
        for(int j = 0;j<n;j++)
            pos[i][nums[i][j]] = j;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i == j)continue;
            bool flag = true;
            for(int k = 0;k<m;k++){
                if(pos[k][i]>pos[k][j])flag = false;
            }
            if(flag)
                graph[i].push_back(j);
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++)
        if(!vis[i])
            dfs(i);
    
    cout<<ans<<endl;
}  
