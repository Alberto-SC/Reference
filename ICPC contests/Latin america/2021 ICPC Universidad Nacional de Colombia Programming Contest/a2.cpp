#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
typedef vector<pair<int, ll>> vpill;
typedef vector<vpill> vvpill;
 
const ll INF = 1e9;
 
ll N;
 
ll dijkstra(vvpill & list, int ini, int fin, int inc){
    
    vi vis(N, false);
    vi dist(N, INF);
    dist[ini] = 0; 
    priority_queue<pair<int, int>, vpill, greater<pair<int, int>> > pq;
    
    pq.push({0, ini});
 
    while (pq.size() != 0) {
 
        ll minVal = pq.top().first;
        int idx = pq.top().second;
 
        //cout<<minVal<<" "<<idx<<"\n";
 
        pq.pop();
        vis[idx] = true;
 
        if(dist[idx] < minVal)continue;
 
        for(auto arista: list[idx]){
 
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
 
int main (){
 
    ios_base::sync_with_stdio(false),cin.tie(NULL);
 
    int m, q;
    cin>>N>>m>>q;
    vvpill list(N);
 
    //cout << N << m << q << endl;
    for(int i = 0; i < m; i++){
        int u, v, w; cin>>u>>v>>w;
        u--; v--;
        list[u].push_back({v, w});
    }
 
    for(int i = 0; i < q; i++){
        int u, v, w; cin>>u>>v>>w;
        u--, v--;
        cout << dijkstra(list, u, v, w) << "\n";
    }
 
}