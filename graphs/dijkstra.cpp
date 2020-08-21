#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli INF = 10e15;
const int MAX = 1440007;
lli D[MAX];
lli P[MAX];
lli N;

vector<pair<int,lli>> graph[MAX]; 
void add_edge(int u,int  v,lli cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
// dijkstra with priority queue
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
void dijkstra(lli mxw){
    for(int i=1;i<n;i++)D[i] = INF;
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<lli,lli> p = q.top();
        q.pop();
        int u = p.y;
        lli dist = p.x;
        if(dist > D[u]) continue;
        for(auto pr: graph[u]){
            int v = pr.x;
            lli next_dist = dist + pr.y;
            if(next_dist < D[v]){
                D[v] = next_dist;
                P[v] = u;
                q.push({next_dist,v});
            }

        }   
    }
}
const lli inf = 10000000000000ll;
vector<pair<int,int> > e[100000];
set<pair<lli,int> > s;
lli d[100000];
int p[100000];
int main(){
	int n,m,u,v,w;
	cin>>n>>m;
	for(int i = 0;i<m;i++) {
		cin>>u>>v>>w;
		u--;
		v--;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i = 0; i < n; ++i)
		d[i] = inf;
	d[0] = 0;
	// dijkstra with set
	s.insert(make_pair(d[0], 0));
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(auto c:e[v]){
            int u = c.first;
            int w = c.second;
            if (d[v] + w < d[u]) {
                s.erase(make_pair(d[u], u));
                d[u] = d[v]+  w;
                p[u] = v;
                s.insert(make_pair(d[u], u));
            }
        }
    }
}