#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli INF = 10e15;
const int MAX = 1440007;
lli D[MAX], N; 
vector<pair<int,lli>> graph[MAX]; 
void add_edge(int u,int  v,lli cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}
// dijkstra with priority queue
void dijkstra(lli source){
    for(int i = 1; i <= N; i++) D[i] = INF;
    D[source] = 0;
    priority_queue<pair<int,lli>,vector<pair<int,lli>>,greater<pair<int,lli>>> q;
    q.push({0,source});
    while(!q.empty()){
        pair<lli,int> p = q.top();
        q.pop();
        int u = p.second;
        lli dist = p.first;
        if(dist > D[u]) continue;
        for(pair<int,int> pr : graph[u]){
            int v = pr.first;
            lli next_dist = dist + pr.second;
            if(next_dist < D[v]){
                D[v] = next_dist;
				p[v] = u;
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
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v1--;
		v2--;
		e[v1].push_back(make_pair(v2,w));
		e[v2].push_back(make_pair(v1,w));
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