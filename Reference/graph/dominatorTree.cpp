/*
	Dominator Tree (Lengauer-Tarjan)

	Tested: SPOJ EN
	Complexity: O(m log n)
*/

struct graph
{
	int n;
	vector<vector<int>> adj, radj;

	graph(int n) : n(n), adj(n), radj(n) {}

	void add_edge(int src, int dst)
	{
		adj[src].push_back(dst);
		radj[dst].push_back(src);
	}

	vector<int> rank, semi, low, anc;

	int eval(int v)
	{
		if (anc[v] < n && anc[anc[v]] < n)
		{
			int x = eval(anc[v]);
			if (rank[semi[low[v]]] > rank[semi[x]])
				low[v] = x;
			anc[v] = anc[anc[v]];
		}
		return low[v];
	}

	vector<int> prev, ord;

	void dfs(int u)
	{
		rank[u] = ord.size();
		ord.push_back(u);
		for (auto v : adj[u])
		{
			if (rank[v] < n)
				continue;
			dfs(v);
			prev[v] = u;
		}
	}

	vector<int> idom; // idom[u] is an immediate dominator of u

	void dominator_tree(int r)
	{
		idom.assign(n, n);
		prev = rank = anc = idom;
		semi.resize(n);
		iota(semi.begin(), semi.end(), 0);
		low = semi;
		ord.clear();
		dfs(r);

		vector<vector<int>> dom(n);
		for (int i = (int) ord.size() - 1; i >= 1; --i)
		{
			int w = ord[i];
			for (auto v : radj[w])
			{
				int u = eval(v);
				if (rank[semi[w]] > rank[semi[u]])
					semi[w] = semi[u];
			}
			dom[semi[w]].push_back(w);
			anc[w] = prev[w];
			for (int v : dom[prev[w]])
			{
				int u = eval(v);
				idom[v] = (rank[prev[w]] > rank[semi[u]] 
					? u : prev[w]);
			}
			dom[prev[w]].clear();
		}

		for (int i = 1; i < (int) ord.size(); ++i)
		{
			int w = ord[i];
			if (idom[w] != semi[w])
				idom[w] = idom[idom[w]];
		}
	}

	vector<int> dominators(int u)
	{
		vector<int> S;
		for (; u < n; u = idom[u])
			S.push_back(u);
		return S;
	}
};


const int N = 2e5 + 9;

vector<int> g[N];
vector<int> t[N], rg[N], bucket[N]; //t = dominator tree of the nodes reachable from root
int sdom[N], par[N], idom[N], dsu[N], label[N];
int id[N], rev[N], T;
int find_(int u, int x = 0) {
  if(u == dsu[u]) return x ? -1 : u;
  int v = find_(dsu[u], x+1);
  if(v < 0)return u;
  if(sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
  dsu[u] = v;
  return x ? v : label[u];
}

void dfs(int u) {
  T++; id[u] = T;
  rev[T] = u; label[T] = T;
  sdom[T] = T; dsu[T] = T;
  for(int i = 0; i < g[u].size(); i++) {
    int w = g[u][i];
    if(!id[w]) dfs(w), par[id[w]] = id[u];
    rg[id[w]].push_back(id[u]);
  }
}

void build(int r, int n) {
  dfs(r);
  n = T;
  for(int i = n; i >= 1; i--) {
    for(int j = 0; j < rg[i].size(); j++) sdom[i] = min(sdom[i], sdom[find_(rg[i][j])]);
    if(i > 1) bucket[sdom[i]].push_back(i);
    for(int j = 0; j < bucket[i].size(); j++) {
      int w = bucket[i][j];
      int v = find_(w);
      if(sdom[v] == sdom[w]) idom[w] = sdom[w];
      else idom[w] = v;
    }
    if(i > 1) dsu[i] = par[i];
  }
  for(int i = 2; i <= n; i++) {
    if(idom[i] != sdom[i]) idom[i]=idom[idom[i]];
    t[rev[i]].push_back(rev[idom[i]]);
    t[rev[idom[i]]].push_back(rev[i]);
  }
}

int st[N], en[N];
void yo(int u, int pre = 0) {
  st[u] = ++T;
  for(auto v: t[u]) {
    if(v == pre) continue;
    yo(v, u);
  }
  en[u] = T;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n >> m) {
    vector<pair<int, int>> ed;
    for(int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      ed.push_back({u, v});
    }
    build(1, n);
    T = 0;
    yo(1);
    vector<int> ans;
    for(int i = 0; i < m; i++) {
      int u = ed[i].first, v = ed[i].second;
      if(st[u] && !(st[v] <= st[u] && en[u] <= en[v])) ans.push_back(i);
    }
    yo(1);
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x + 1 << ' ';
    cout << '\n';
    T = 0;
    for(int i = 0; i <= n; i++) {
      t[i].clear(), g[i].clear(), rg[i].clear(), bucket[i].clear();
      sdom[i] = par[i] = idom[i] = dsu[i] = label[i] = id[i] = rev[i] = st[i] = en[i] = 0;
    }
  }
  return 0;
}