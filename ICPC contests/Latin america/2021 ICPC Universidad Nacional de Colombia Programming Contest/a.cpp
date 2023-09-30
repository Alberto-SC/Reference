#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

 
const int INF = 1e9;
const int maxn = 507;
vector<int> d(maxn);
set<pair<int,int>> st;
vector<pair<int,int>> graph[maxn];

int dijkstra(int ini, int fin, int inc,int n){
    vector<int> vis(n, false);
    vector<int> dist(n,INF);
    dist[ini] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    pq.push({0, ini}); 
    while (pq.size() != 0) {
        int minVal = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        vis[idx] = true;
        if(dist[idx] < minVal)continue;
        for(auto arista: graph[idx]){
            if(vis[arista.first]) continue;
            int nuevaDist = dist[idx] + arista.second + inc;
            if(nuevaDist < dist[arista.first]){
                dist[arista.first] = nuevaDist;
                pq.push({nuevaDist, arista.first});
            }
        }
        if(idx == fin)return dist[fin]+inc;
    }
    return -1;
}
 
signed main (){__
    int m, q,u,v,w,n;
    cin>>n>>m>>q;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        u--; v--;
        graph[u].push_back({v, w});
    }
 
    for(int i = 0; i < q; i++){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;
        cout << dijkstra(u,v,w,n) << "\n";
    }
 
}
