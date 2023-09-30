#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second
const int maxn = 100000;
vector<pair<int, int>> g[maxn*51];
set<pair<int,int>> s;
vector<int> d(maxn*51);
int inf = 1e9+7;
void dijkstra(int n){
    for(int i = 0; i < n; ++i)
		d[i] = inf;
	d[0] = 0;
	s.insert(make_pair(d[0], 0));
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(auto c:g[v]){
            int u = c.first;
            int w = c.second;
            if (d[v] + w < d[u]) {
                s.erase(make_pair(d[u], u));
                d[u] = d[v]+  w;
                s.insert(make_pair(d[u], u));
            }
        }
    }
}

void addedge(int u,int v,int w){
    g[u*51].push_back({v*51+w,0});
    for(int last = 1;last<=50;last++)
        g[u*51+last].push_back({v*51,(last+w)*(last+w)});
}
signed main(){__
	int t= 1,n,m,u,v,w;
    cin>>n>>m;
    for (int i = 0; i<m; i++) {
        cin>>u>>v>>w;
        u--,v--;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    set<pair<int, int>> st;
    dijkstra(n*51);
    for (int i = 0; i < n; ++i) {
        if(d[i*51]==inf) 
            cout<<-1<<endl;
        else 
            cout<<d[i*51]<<" ";
    }
    return 0;
}  

 