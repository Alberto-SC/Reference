#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 10007;
vector<int> graph[maxn];

vector<int> bfs(int ini,int n){
    vector<int> dist(n, 1e9);
    dist[ini] = 0; 
    queue<int> q;
    q.push(ini);
    while(q.size() != 0) {
        int u = q.front();
        q.pop();
        for(auto v: graph[u]){
            int nuevaDist = dist[u] + 1;
            if(nuevaDist < dist[v]){
                dist[v] = nuevaDist;
                q.push(v);
                parent[v].clear();
                parent[v].push_back(u);
            }
            if(nuevaDist == dist[v]){
              parent[v].push_back(u);
            }
        }
    }
    return dist;
}

all_paths()

signed main(){__
  int T,n,m,u,v;
  cin>>T;
  while(T--){
    cin>>n>>m;
    for(int i = 0;i<n;i++)graph[i].clear();
    for(int i = 0;i<m;i++){
      cin>>u>>v;
      u--,v--;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    vector<int> dist = bfs(0,n);
    int f,k;
    cin>>f;
    vector<int> friends(f);
    for(auto &c:friends)cin>>c;
    cin>>k;
    vector<int> need(k);
    for(auto &c:need)cin>>c,c--;


    vector<int> dists[k];
    for(int i = 0;i<k;i++){
      dists[i] = bfs(friends[need[i]],n);
    } 
    vector<int>  graph2[n];
    for(auto c:need){
      int house = friends[c];
      int D = dist[house];

      for(int i =0;i<f;i++){
        if(i == c)continue;
        int FHouse = friends[i];
        if(D+dists[c][FHouse] == dist[FHouse]){
          graph2[c].push_back(i);
        }
      }
    }
    for(int i = 0;i<n;i++){
      cout<<"I: "<<i<<" ";
      for(auto c:graph2[i]){
        cout<<c<<" ";
      }
      cout<<endl;
    }
  }
  
  return 0;
}

