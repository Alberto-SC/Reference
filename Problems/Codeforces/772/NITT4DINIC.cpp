#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
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

signed main(){__
    int n,m,b,u,v;
    cin>>n>>m>>b;
    vector<vector<int>> grid(n,vector<int>(m,1));

    for(int i = 0;i<b;i++){
        cin>>u>>v;
        grid[u][v] =0;
    }

    vector<int> fx = {+1,-1,+0,+0};
    vector<int> fy = {+0,+0,+1,-1};
    auto isValid = [&](int x,int y){
        if(x<0 || y<0 || x>=n || y>=m)return false;
        return true;
    };
    auto getN = [&](int x,int y){
        return (x*m)+y;
    };
    dinic<int> DN((n*m)+2);   
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j]==0)continue;
            if((i+j)&1)
                DN.add_edge(n*m,getN(i,j),1);
            else    
                DN.add_edge(getN(i,j),(n*m)+1,1);
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(isValid(nx,ny)&&  grid[nx][ny]==1){
                    if((i+j)&1)
                        DN.add_edge(getN(i,j),getN(nx,ny),1);
                    else
                        DN.add_edge(getN(nx,ny),getN(i,j),1);
                }
            }
        }   
    }

    int mx = DN.max_flow(n*m,(n*m)+1)*2;
    int z= ((m*n)-b)-mx;
    if(mx == (n*m)-b)cout<<"Yes"<<endl;
    else cout<<"No"<<" "<<z<<endl;
};