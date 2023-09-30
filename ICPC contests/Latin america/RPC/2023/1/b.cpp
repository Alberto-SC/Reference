#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;


const int INF = 1e18;

const int maxn = 10007;
vector<pair<int,int>> graph[maxn];


int dijkstra(int ini, int fin, int n){
    vector<int> dist(n,INF);
    dist[ini] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
    pq.push({0, ini}); 
    while (pq.size() != 0) {
        int minVal = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(dist[idx] < minVal)continue;
        for(auto arista: graph[idx]){
            int nuevaDist = dist[idx] + arista.second ;
            if(nuevaDist < dist[arista.first]){
                dist[arista.first] = nuevaDist;
                pq.push({nuevaDist, arista.first});
            }
        }
        // uncomment this if you only need the distance to one node
        if(idx == fin)return dist[fin];
    }
    return -1;
}


signed main(){__
    int T,n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &c:v)cin>>c;
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int test = 100;
    int s = n;
    int t = n+1;
    int ans = INF;
    while(test--){
        for(int i = 0;i<n;i++){
            int who = rand()%2;
            graph[i].push_back({s+who,v[i]});
            graph[s+who].push_back({i,v[i]});
        }
        int dis = dijkstra(s,t,n+2);
        if(dis != -1)ans = min(ans,dis);
        graph[s].clear();
        graph[t].clear();
        for(int i = 0;i<n;i++)graph[i].pop_back();
    }
    cout<<ans<<endl;
    return 0;
}

