#include <bits/stdc++.h>
using namespace std;
template<typename flow_type>
struct dinic{
	struct edge{
		size_t src, dst, rev;
		flow_type flow, cap;
	};
 
	int n;
	vector<vector<edge>> adj;
	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}
 
	void add_edge(size_t src, size_t dst, flow_type cap, flow_type rcap = 0){
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
 
	flow_type augment(int source, int sink, flow_type flow){
		if (source == sink) return flow;
		for (; it[source] != adj[source].size(); ++it[source]){
			edge &e = adj[source][it[source]];
			if (e.flow < e.cap && level[e.dst] + 1 == level[source]){
				flow_type delta = augment(e.dst, sink, 
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
 
	flow_type max_flow(int source, int sink){
		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;
		flow_type flow = 0;
		flow_type oo = numeric_limits<flow_type>::max();
		while (bfs(source, sink)){
			fill(it.begin(), it.end(), 0);
			for (flow_type f; (f = augment(source, sink, oo)) > 0;)
				flow += f;
		} 
		return flow;
	}
};

int main(){
    int t,n,m,x,k;
    cin>>t;
    while(t--){
        cin>>n>>m;
        dinic<int> dn(n+m+2);
        for(int i = 0;i<m;i++){
            cin>>k;
            for(int j = 0;j<k;j++){
                cin>>x;
                x--;
                dn.add_edge(i,x+m,1);
            }
            dn.add_edge(n+m,i,1);
        }
        for(int i =0;i<n;i++)
            dn.add_edge(i+m,n+m+1,(m+1)/2);
        int mx = dn.max_flow(n+m,n+m+1);
        if(mx<m){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        for(int i = 0;i<m;i++)
            for(int j = 0;j<dn.adj[i].size();j++)
                if(dn.adj[i][j].flow==1)cout<<(dn.adj[i][j].dst-m)+1<<" ";
            

        cout<<endl;

    }
    return 0;
}