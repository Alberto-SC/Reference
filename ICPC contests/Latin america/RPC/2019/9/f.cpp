#include <bits/stdc++.h>
using namespace std;

struct graph
{
	int L, R;
	vector<vector<int>> adj;

	graph(int L, int R) : L(L), R(R), adj(L + R) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v + L);
		adj[v + L].push_back(u);
	}

	int maximum_matching()
	{
		vector<int> visited(L), mate(L + R, -1);
		function<bool(int)> augment = [&](int u)
		{
			if (visited[u]) return false;
			visited[u] = true;
			for (int w : adj[u])
			{
				int v = mate[w];
				if (v < 0 || augment(v))
				{
					mate[u] = w;
					mate[w] = u;
					return true;
				}
			}
			return false;
		};
		int match = 0;
		for (int u = 0; u < L; ++u)
		{
			fill(visited.begin(), visited.end(), 0);
			if (augment(u))
				++match;
		}
		return match;
	}
};
int main(){
    int n,m,k,s,d;
    graph g = graph(n,m);
    for(int i =0;i<k;i++){
        cin>>s>>d;
        g.add_edge(s,d);
    }
    int mx = g.maximum_matching();
    for(int i= 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i == j)continue;
            for(int k = 0;k<g.adj[i].size();k++){
                for(int l = 0;l<g.adj[j].size();l++)
                    if(g.adj[i][k]== g.adj[j][l])return cout<<mx+2<<endl,0;
            }
        }
    }
    if(mx ==n)
        cout<<mx<<endl;
    else cout<<mx+1<<endl;
    return 0;
}