/**
 * Author: Alberto Silva
 * Description: Calculates shortest paths from $s$ in a graph 
 * Time: O(V \log E)
 * Status: Tested on kattis:shortestpath3
 */
const int INF = 1e9;
const int MAX = 1440007;
int D[MAX];
int P[MAX];
int N;

vector<pair<int,int>> graph[MAX]; 
void add_edge(int u,int  v,int cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
void dijkstra(int n,int Source){
    set<pair<int,int> > s;
    for(int i = 0; i < n; ++i)
        D[i] = INF;
    D[Source] = 0;
    s.insert(make_pair(D[0], Source));
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(auto c:e[v]){
            int u = c.first;
            int w = c.second;
            if (D[v] + w < D[u]) {
                s.erase(make_pair(D[u], u));
                D[u] = D[v]+  w;
                p[u] = v;
                s.insert(make_pair(D[u], u));
            }
        }
    }
}
// A bit faster
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
            int newDist = dist[idx] + arista.second ;
            if(newDist < dist[arista.first]){
                dist[arista.first] = newDist;
                pq.push({newDist, arista.first});
            }
        }
        // uncomment this if you only need the distance to one node
        //if(idx == fin)return dist[fin]+inc;
    }
    return -1;
}
