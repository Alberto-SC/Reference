#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

struct Bipartite_Matching{
    vector<vector<int>> es;
    vector<int> d, match;
    vector<bool> used, used2;
    const int n, m;
    Bipartite_Matching(int n, int m) : es(n), d(n), match(m), used(n), used2(n), n(n), m(m) {}

    Bipartite_Matching(int n, int m,vector<vector<int>> g) : es(n), d(n), match(m), used(n), used2(n), n(n), m(m) {
      es = g;
    }

    void add_edge(int u, int v){
        es[u].push_back(v);
    }

    void bfs(){
        fill(begin(d), end(d), -1);
        queue<int> que;
        for(int i = 0; i < n; i++){
            if(!used[i]) que.emplace(i), d[i] = 0;
        }
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(auto &e: es[i]){
                int j = match[e];
                if(j != -1 && d[j] == -1){
                    que.emplace(j), d[j] = d[i]+1;
                }
            }
        }
    }

    bool dfs(int now){
        used2[now] = true;
        for(auto &e: es[now]){
            int u = match[e];
            if(u == -1 || (!used2[u] && d[u] == d[now]+1 && dfs(u))){
                match[e] = now, used[now] = true;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching(){
        fill(begin(match), end(match), -1), fill(begin(used), end(used), false);
        int ret = 0;
        while(true){
            bfs();
            fill(begin(used2), end(used2), false);
            int flow = 0;
            for(int i = 0; i < n; i++){
                if(!used[i] && dfs(i)) flow++;
            }
            if(flow == 0) break;
            ret += flow;
        }
        return ret;
    }
};

vector<int> cover(vector<vector<int>>& g, int n, int m) {
	  //From maximum matrching de minimun vertex cover is the nodes not matched for the left side 
    // and the nodes visited in the right part if we run a dfs from no matched nodes in the left j
    // Nodes from right are numbered from n to (n+m)-1
    
    Bipartite_Matching BM(n,m,g);
    int res = BM.bipartite_matching();
    vector<int> match = BM.match;
		vector<bool> lfound(n, true), seen(m);
		for (int it : match) if (it != -1) lfound[it] = false;
		vector<int> q, cover;
		for(int i = 0;i<n;i++) if (lfound[i]) q.push_back(i);

		while (!q.empty()) {
			int i = q.back(); q.pop_back();
			lfound[i] = 1;
			for (int e : g[i]) if (!seen[e] && match[e] != -1) {
				seen[e] = true;
				q.push_back(match[e]);
			}
		}
		for(int i = 0;i<n;i++) if (!lfound[i]) cover.push_back(i);
		for(int i = 0;i<m;i++) if (seen[i]) cover.push_back(n+i);
		assert(cover.size() == res);
		return cover;
}


signed main(){
  int n,m,p;
  cin>>n>>m>>p;
  vector<vector<int>> g(n);
  for(int i = 0;i<p;i++){
    int u,v;
    cin>>u>>v;
    u--,v--;
    g[u].push_back(v);
  }

  vector<int> cv = cover(g,n,m);
  for(auto c:cv)cout<<c<<" ";
  cout<<endl;
  cout<<cv.size()<<endl;
  return 0;
}
