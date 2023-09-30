#include <bits/stdc++.h>
using namespace std;
const int maxn = 307;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define x first
#define y second
const int INF = 1000000007;
set<pair<int,int>> graph[maxn];
void add_edge(int u,int v,int c){
    graph[u].insert({v,c});
    graph[v].insert({u,c});
}
vector<int> D(maxn);

void dijkstra(int sr){
    for(int i = 0;i<maxn;i++)D[i] = INF;
    D[sr] = 0;
    set<pair<int,int>> s;
    s.insert({D[sr],sr});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto pr:graph[u]){
            int v = pr.x;
            int c = pr.y;
            if(D[v]<= D[u]+c)continue;
            s.erase({D[v],v});
            D[v] = D[u]+c;
            s.insert({D[v],v});
        }
    }
}

int main(){__
    int n,x;
    cin>>n;
    vector<pair<pair<int,int>,int>> edges;
    vector<int> ans(n,INF);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>x;
            if(j!= i && x!= -1){
                add_edge(i,j,x);
                edges.push_back({{i,j},x});
            }   
        }
    }   
    map<pair<int,int>,int> mp;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].x.x;
        int v = edges[i].x.y;
        if(mp.count({v,u}))continue;
        mp[{u,v}] = 1;
        int c = edges[i].y;
        graph[u].erase({v,c});
        graph[v].erase({u,c});
        dijkstra(u);
        if(D[v]!= INF){
            ans[u] = min(ans[u],D[v]+c);
            ans[v] = min(ans[v],D[v]+c);
        }
        graph[u].insert({v,c});
        graph[v].insert({u,c});
    }
    for(auto c:ans)c==INF?cout<<-1<<endl:cout<<c<<endl;
    return 0;
}