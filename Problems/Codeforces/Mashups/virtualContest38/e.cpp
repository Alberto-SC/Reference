#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


struct dinic{
	struct edge{
		size_t src, dst, rev;
		int flow, cap;
	};
 
	int n;
	vector<vector<edge>> adj;
	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}
 
	void add_edge(size_t src, size_t dst, int cap, int rcap = 0){
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap});
		if (src == dst) adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, rcap});
	}
 
	vector<int> level, q, it;
 
	bool bfs(int source, int sink){
		fill(level.begin(), level.end(), -1);
		for (int qf = level[q[0] = sink] = 0, qb = 1; qf < qb; ++qf){
			sink = q[qf];
			for (edge &e : adj[sink]){
				edge &r = adj[e.dst][e.rev];
				if (r.flow < r.cap && level[e.dst] == -1)
					level[q[qb++] = e.dst] = 1 + level[sink];
			}
		}
		return level[source] != -1;
	}
 
	int augment(int source, int sink, int flow){
		if (source == sink) return flow;
		for (; it[source] != adj[source].size(); ++it[source]){
			edge &e = adj[source][it[source]];
			if (e.flow < e.cap && level[e.dst] + 1 == level[source]){
				int delta = augment(e.dst, sink, 
								  min(flow, e.cap - e.flow));
				if (delta > 0){
					e.flow += delta;
					adj[e.dst][e.rev].flow -= delta;
					return delta;
				}
			}
		}
		return 0;
	}
 
	int max_flow(int source, int sink){
		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;
		int flow = 0;
		int oo = numeric_limits<int>::max();
		while (bfs(source, sink)){
			fill(it.begin(), it.end(), 0);
			for (int f; (f = augment(source, sink, oo)) > 0;)
				flow += f;
		}
		return flow;
	}
};


signed main(){__
	int t= 1,n,x,y,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        dinic mxfl(n+m+2);
        for(int i = 0;i<m;i++){
            cin>>x;
            for(int j = 0;j<x;j++){
                cin>>y;
                mxfl.add_edge(y,n+i+1,1);        
            }
            mxfl.add_edge(n+1+i,n+m+1,1);
        }
        for(int i = 0;i<n;i++)
            mxfl.add_edge(0,i+1,(m+1)/2);
        int flow = mxfl.max_flow(0,n+m+1);
        if(flow<m)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(int i = 0;i<m;i++){
                for(auto v:mxfl.adj[i+n+1]){
                    if(v.flow==-1){cout<<v.dst<<" ";break;}
                }
            }
            cout<<endl;
        }
    }
    return 0;
}  
