#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
typedef long long int lli; 
const int maxn = 100007;
vector<pair<lli,lli>> graph[maxn];
vector<lli> p(maxn);
vector<lli> sz(maxn,1);
void add_edge(lli u,lli v,lli c){
    graph[u].push_back({v,c});
}
lli ans = 0;
vector<pair<lli,lli>> edg;
vector<lli> stations;
lli n = 0;
bool comp(pair<pair<lli,lli>,lli> A ,pair<pair<lli,lli>,lli> B){
    return A.y<B.y;

}
lli get_raiz(lli u){
    return u == p[u]?u:p[u] = get_raiz(p[u]);
}

bool union_(lli u,lli v){
    u = get_raiz(u);
    v = get_raiz(v);
    if(u == v)return false;
    if(sz[v]> sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return true;
}

void mst(){
    vector<pair<pair<lli,lli>,lli>> edges;
    for(int i = 0;i<=n;i++){
        for(auto c:graph[i])
            edges.push_back({{i,c.x},c.y});
    }
    sort(edges.begin(),edges.end(),comp);
    for(int i = 0;i<edges.size();i++){
        if(union_(edges[i].x.x,edges[i].x.y)){
            if(edges[i].x.x == n)stations.push_back(edges[i].x.y);
            else edg.push_back({edges[i].x.x,edges[i].x.y});
            ans+=edges[i].y;
        }
    }

}

int main(){
    lli x,y;
    cin>>n;
    vector<pair<lli,lli>> nodes(n);
    map<pair<lli,lli>,lli> mp;
    for(lli i = 0;i<n;i++){
        cin>>nodes[i].x>>nodes[i].y;
    }
    vector<lli> c(n);
    vector<lli> k(n);
    for(auto &x:c)cin>>x;
    for(auto &x:k)cin>>x;
    for(lli i = 0;i<n;i++){
        for(lli j = 0;j<n;j++){
            if(j== i)continue;
            lli d = abs(nodes[i].x-nodes[j].x)+ abs(nodes[i].y-nodes[j].y); 
            lli cost = d*(k[i]+k[j]);
            add_edge(i,j,cost);
        }
    }

    for(int i = 0;i<n;i++)
        add_edge(n,i,c[i]);
    
    iota(p.begin(),p.end(),0);
    mst();
    cout<<ans<<endl;
    cout<<stations.size()<<endl;
    for(auto c:stations)cout<<c+1<<" ";
    cout<<endl;
    cout<<edg.size()<<endl;
    for(auto c:edg)cout<<c.x+1<<" "<<c.y+1<<endl;
    return 0;
}