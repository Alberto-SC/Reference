#include <bits/stdc++.h>
using namespace std;
const int maxn = 300007;
typedef long long int lli;
#define x first 
#define y second
vector<pair<int,int>> graph[maxn];
const lli INF = 1ll<<59;
void add_edge(int u,int v,int c){
    graph[v].push_back({u,c});
    graph[u].push_back({v,c});
}
lli D[maxn];
int P[maxn];

void dijsktra(int sr){
    for(int i = 0;i<maxn;i++)D[i] = INF;
    D[sr] = 0;
    P[sr] = sr;
    set<pair<lli,lli>> s;
    s.insert({D[sr],sr});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        for(auto pr:graph[u]){
            int v = pr.x;
            int c = pr.y;
            if(D[v]< D[u]+c)continue;
            s.erase({D[v],v});
            D[v] = D[u]+c;
            P[v] = u;
            s.insert({D[v],v});
        }
    }
}

map<pair<int,int>,int> mp;

int main(){
    int n,m,u,v,c,x;
    cin>>n>>m;
    int key = 0;
    vector<int> cost(m);
    for(int i = 0;i<m;i++){
        cin>>u>>v>>c;
        if(!mp.count({u,v})){
            mp[{u,v}] = key;
            mp[{v,u}] = key++;
        }
        cost[i] = c;
        add_edge(u,v,c);
    }
    cin>>x;
    dijsktra(x);
    vector<int> ans;
    lli cont = 0;

    for(int i = 1;i<=n;i++){
        if(P[i]== i|| P[i]== 0)continue;
        ans.push_back(mp[{i,P[i]}]+1);
        cont+= cost[mp[{i,P[i]}]];
    }
    cout<<cont<<endl;
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    return 0;
}