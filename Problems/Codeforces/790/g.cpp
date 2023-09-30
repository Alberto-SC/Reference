#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


const int maxn = 4007;
vector<int> graph[maxn];

int W[maxn],B[maxn];

string color;
int ans = 0;
void dfs(int u,int p = -1){
    if(color[u]=='W')W[u]++;
    else B[u]++;
    for(auto &v:graph[u]){
        if(v== p)continue;
        dfs(v,u);
        W[u]+=W[v];
        B[u]+=B[v];
    }
    if(W[u]==B[u])ans++;
}

signed main(){__
  int t,n,p;
  cin>>t;
  while(t--){
    cin>>n;
    for(int i = 0;i<n;i++)
        W[i] = 0,B[i] = 0,graph[i].clear();
    for(int i = 0;i<n-1;i++){
        cin>>p;
        graph[p-1].push_back(i+1);
    }
    cin>>color;
    ans = 0;
    dfs(0);
    cout<<ans<<endl;
  }
  return 0;
}
