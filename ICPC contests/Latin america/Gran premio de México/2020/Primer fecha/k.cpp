#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 100007; 
vector<int> p(maxn);
vector<int> sz(maxn,1);

int get_root(int u){
    return u==p[u]?u:p[u] = get_root(p[u]);
}

struct edge{
    int u,v,c;
    bool operator < (edge B){
        return c<B.c;
    }
};

bool union_sz(int u,int v){
    u = get_root(u);
    v = get_root(v);
    if(u ==v)return false;
    if(sz[v]>sz[u])swap(u,v);
    sz[u]+=sz[v];
    p[v] = u;
    return true;
}

vector<edge> kruskal(vector<edge> edges){
    sort(edges.begin(),edges.end());
    vector<edge> tree;
    for(int i = 0;i<edges.size();i++){
        int u = edges[i].u;
        int v = edges[i].v;
        if(union_sz(u,v)){
            tree.push_back(edges[i]);
        }
    }
    return tree;
}

int main(){
    int n;
    iota(p.begin(),p.end(),0);
    cin>>n;
}