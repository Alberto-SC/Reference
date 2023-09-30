#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
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
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> a(n),b(n);
        map<int,int>mp1;
        map<int,int>mpk1;
        map<int,int>mp2;
        map<int,int>mpk2;
        for(auto &c:a)cin>>c,mp1[c]++;
        for(auto &c:b)cin>>c,mp2[c]++;

        int key = 0;
        for(int i = 0;i<n;i++){
            if(!mpk1.count(a[i]))
                mpk1[a[i]] =key++;
        }
        key = 0;
        for(int i = 0;i<n;i++){
            if(!mpk2.count(b[i]))
                mpk2[b[i]] =key++;
        }
        dinic<int> dn(mp1.size()+mp2.size()+2);
        int N = mp2.size();
        int M = mp1.size();
        for(auto c: mp2){
            int x = c.first;
            while(x<=1e9){
                if(mp1.count(x)){
                    dn.add_edge(mpk2[c.first],N+mpk1[x],c.second);
                }
                x*=2;   
            }
            x = c.first/2;
            while(x){
                if(mp1.count(x)){
                    dn.add_edge(mpk2[c.first],N+mpk1[x],c.second);
                }
                x/=2;
            }
            dn.add_edge(N+M,mpk2[c.first],c.second);
        }
        for(auto c:mp1){
            dn.add_edge(N+mpk1[c.first],N+M+1,c.second);
        }
        int f = dn.max_flow(N+M,N+M+1);
        cout<<f<<endl;
        if(f == n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}