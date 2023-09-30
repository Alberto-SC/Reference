/**
 * Author: Marckess
 * Source: http://en.wikipedia.org/wiki/Bellman-Ford_algorithm
 * Description: Calculates  the kth shortest paths from $s$ in a graph 
 * Usage: adj.resize(n + 1);rev.resize(n + 1);	adj[u].pb(new Edge(v, w));
            rev[v].pb(new Edge(u, w));
            adj[u].back()->rev = rev[v].back();
            rev[v].back()->rev = adj[u].back();
            vector<int> res = k_shortest_paths(1, n, k); 1 indexed
 */ 
 
const int inf = 1e18;
 
struct Edge {
	int to, w;
	Edge *rev;
	
	Edge (int to, int w) : to(to), w(w) {}
};
 
pair<vector<int>, vector<Edge*>> dijkstra (vector<vector<Edge*>> gra, int s) {
	vector<int> dis(gra.size(), inf);
	vector<Edge*> par(gra.size(), nullptr);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	pq.emplace(0, s);
	dis[s] = 0;
	
	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		
		if (dis[u] < d) continue;
		
		for (auto *e : gra[u]) {
			ll w = d + e->w;
			if (w < dis[e->to]) {
				par[e->to] = e->rev;
				pq.emplace(dis[e->to] = w, e->to);
			}
		}
	}
	
	return {dis, par};
}
 
vector<vector<Edge*>> adj, rev;
 
vector<int> k_shortest_paths (int s, int t, int k) {
	auto [dis, par] = dijkstra(rev, t);
	vector<int> res;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.emplace(dis[s], s);
	
	while (k && pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		
		res.push_back(d);
		k--;
		
		while (1) {
			for (Edge *e : adj[u]) {
				int v = e->to;
				if (e != par[u]) {
					ll w = d - dis[u] + e->w + dis[v];
					pq.emplace(w, v);
				}
			}
			
			if (!par[u])
				break;
			u = par[u]->to;
		}
	}
	
	while (k) {
		res.push_back(-1);
		k--;
	}
	
	return res;
}
 
void main_() {
	int n, m, k;
	cin >> n >> m >> k;
	adj.resize(n + 1);
	rev.resize(n + 1);	
	for(int i = 0;i<m;i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(new Edge(v, w));
		rev[v].pb(new Edge(u, w));
		adj[u].back()->rev = rev[v].back();
		rev[v].back()->rev = adj[u].back();
	}
	vector<int> res = k_shortest_paths(1, n, k);
	for (ll r : res)
		cout << r << " ";
	cout << endl;
}
 