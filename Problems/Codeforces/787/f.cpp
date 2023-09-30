#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 200007;
vector<int> graph[maxn];
vector<int> sz(maxn);

int dist,x,y;
void dfsSz(int u,int p = -1,int d = 0){
  if(u == y)dist = d;
  for(auto v:graph[u]){
    if(v==p)continue;
    dfsSz(v,u,d+1);
    sz[u]+=sz[v];
  }
}

int dfs(int u,int p = -1){
  int ans = 0;
  for(auto v:graph[u]){
    if(v==p)continue;
    if(sz[v])ans +=dfs(v,u)+2;
  }
  return ans;
}

signed main(){__
    int T = 1,n,k,u,v;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cin>>x>>y;
        for(int i = 0;i<n;i++)graph[i].clear(),sz[i] = 0;
        x--,y--;
        for(int i = 0;i<k;i++){
          int z;
          cin>>z;
          z--;
          sz[z] = 1;
        }
        sz[y] = 1;
        for(int i = 0;i<n-1;i++){
          cin>>u>>v;
          u--,v--;
          graph[u].push_back(v);
          graph[v].push_back(u);
        }
        dfsSz(x);
        int ans = dfs(x);
        ans-=dist;
        cout<<ans<<endl;
    }
    return 0;
}