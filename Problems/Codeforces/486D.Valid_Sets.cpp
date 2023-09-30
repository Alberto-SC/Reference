#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int maxn = 2007;
const lli mod = (1e9)+ 7;
vector<int> graph[maxn];
vector<bool> vis(maxn);
lli f[maxn];
lli C[maxn];

int n,d;
void dfs(int u,int p){
    vis[u] = true;
    f[u] = 1;
    for(auto v:graph[u]){
        if(vis[v])continue;
        if(C[v]<C[p] || C[v]>C[p]+d)continue;
        if(C[v] == C[p] && v<p)continue;
        dfs(v,p);
        f[u]  = (f[u]*(f[v]+1))%mod; 
    }
}
int main(){
    int u,v;
    cin>>d>>n;
    for(int i = 0;i<n;i++)cin>>C[i];
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
    }
    lli ans = 0;
    for(int i  = 0;i<n;i++){
        for(int j = 0;j<n;j++)vis[j] = false,f[j] =0;
        dfs(i,i);
        ans = (ans+f[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}