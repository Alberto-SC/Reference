#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<int> graph[maxn];
vector<int> dist(maxn);

const int inf = 1e9;

void bfs(int s,int n){
  for(int i = 0;i<n;i++){
    dist[i] = inf;
  }
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto v:graph[u]){
      if(dist[u]+1<dist[v]){
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }

}
signed main(){__
  int T,n,x;
  freopen("jumping.in", "r", stdin);
  cin>>T;
  while(T--){
    cin>>n;
    for(int i = 0;i<n;i++)graph[i].clear();
    for(int i = 0;i<n;i++){
      cin>>x;
      if(i+x<n){
        graph[i+x].push_back(i);
      }
      if(i-x>=0){
        graph[i-x].push_back(i);
      }
    }

    bfs(n-1,n);
    for(int i = 0;i<n;i++){
      if(dist[i]==inf)cout<<-1<<endl;
      else cout<<dist[i]<<endl;
    }
  }
}

