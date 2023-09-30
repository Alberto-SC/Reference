#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
#define lli long long

struct MCMF {
	int N;
    const lli INF = numeric_limits<lli>::max();
	vector<vector<int>> ed, red;
	vector<vector<lli>> cap, flow, cost;
	vector<int> seen;
	vector<lli> dist, pi;
	vector<pair<int,int>> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, vector<lli>(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, lli cap, lli cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s) {
		fill(seen.begin(),seen.end(), 0);
		fill(dist.begin(),dist.end(), INF);
		dist[s] = 0; lli di;

		__gnu_pbds::priority_queue<pair<lli, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, lli cap, lli cost, int dir) {
			lli val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (int i : ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			for (int i : red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		for(int i = 0;i<N;i++) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<lli, lli> maxflow(int s, int t) {
		lli totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			lli fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		for(int i = 0;i<N;i++) for(int j = 0;j<N;j++) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(pi.begin(),pi.end(), INF); pi[s] = 0;
		int it = N, ch = 1; lli v;
		while (ch-- && it--)
			for(int i = 0;i<N;i++) if (pi[i] != INF)
				for (int to : ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};


signed main(){__
    int n;
    cin>>n;
    lli dist[n][n];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>dist[i][j];
    MCMF<long long> MC(n+2+(n&1?1:0));
    for(int i = 1;i<=n;i+=2){
        MC.addEdge(0,i,1,0);
        for(int j = 2;j<=n;j+=2){
            int cost = 0;
            if(j==2)cost= dist[i-1][j-1];
            else cost+=dist[i-1][j-1]+dist[i-1][j-3];
            MC.addEdge(i,j,1,cost);
        }
        if(n&1)
            MC.addEdge(i,n+1,1,dist[i-1][n-2]);
    }    
    for(int i=2;i<=n+(n&1?1:0);i+=2)
        MC.addEdge(i,n+1+(n&1?1:0),1,0);
    
    cout<<MC.maxflow(0,n+1+(n&1?1:0)).second<<endl;
    // cout<<min_cost_flow(n+2+(n&1?1:0),E,(n+1)/2,0,n+1+(n&1?1:0))<<endl;

    return 0;
}