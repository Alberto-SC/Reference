#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define x first 
#define y second
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int INF = 1e15;
const int maxn = 10000;
vector<int> D(maxn);
vector<vector<int>> P(maxn);

vector<pair<int,int>> graph[maxn]; 
void add_edge(int u,int  v,int cost){
    graph[u].push_back({v,cost});
    graph[v].push_back({u,cost});
}


int n;
void dijkstra(int sr){
  	for(int i = 0; i < n; i++)
		D[i] = INF;
	D[sr] = 0;
    set<pair<int,int> > s;
	s.insert(make_pair(D[sr], sr));
    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for(auto c:graph[v]){
            int u = c.first;
            int w = c.second;
            if (D[v] + w < D[u]) {
                s.erase(make_pair(D[u], u));
                D[u] = D[v]+  w;
                P[u].clear();
                P[u].push_back(v);
                s.insert(make_pair(D[u], u));
            }
            else if(D[v]+w==D[u])
                P[u].push_back(v);
        }
    }
}
vector<int> vis(maxn);
vector<int> cont(maxn);
vector<int> V[maxn];
int get_pass(int u){
    if(vis[u])return 0;
    vis[u] =true;
    int r = cont[u];
    for(auto c:V[u])
        r+=get_pass(c);
    return r; 
}
signed main(){__
	int t= 1,u,m,p,g,v,c;
    while(t--){
        cin>>n>>m>>p>>g;
        vector<int> people(p);
        for(auto &c:people)cin>>c,c--,cont[c]++;

        for(int i = 0;i<m;i++){
            cin>>u>>v>>c;
            u--,v--;
            add_edge(u,v,c);
        }

        dijkstra(0);
        for (int i = 0;i<n;i++) {
            for (int j=0;j<P[i].size();j++) {
                int k = P[i][j];
                V[k].push_back(i);
            }
        }
        int ans = 0,mn = 1e15;
        for(int i = 0;i<p;i++)
            ans+=D[people[i]];
        mn = ans;
        for(int i = 0;i<n;i++){
            vis.assign(n,false);
            int k = get_pass(i);
            int aux = ans;
            aux-=k*D[i];
            aux+=k*g;
            mn = min(mn,aux);
        }
        cout<<mn<<endl;
    }
    return 0;
}  
