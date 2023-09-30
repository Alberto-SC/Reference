#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct edge{
    int u,v,c;
    bool operator < (const edge b){
        return c<b.c;
    }
};

int dist(int x1,int y1,int x2,int y2){
    int x = (x2-x1)*(x2-x1);
    int y = (y2-y1)*(y2-y1);
    return x+y;
}

vector<int> sz;
vector<int> P;

int root(int u){
    return P[u]==u?u:P[u] = root(P[u]);
}

int unionBySize(int u,int v){
    u = root(u);
    v = root(v);
    if(u == v)return false;
    if(sz[u]<sz[v])swap(u,v);
    sz[u]+= sz[v];
    P[v] = u;
    return true;
}

signed main(){__
	int t= 1,n,x,y;
    cin>>n;
    sz.resize(n,1);
    P.resize(n);
    iota(P.begin(),P.end(),0);
    vector<pair<int,int>> p(n);
    for(int i = 0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }

    vector<edge> E;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(i == j)continue;
            E.push_back({i,j,dist(p[i].first,p[i].second,p[j].first,p[j].second)});
        }
    }

    sort(E.begin(),E.end());    
    int ans = 0;
    for(int i = 0;i<E.size();i++){
        int u = E[i].u;
        int v = E[i].v;
        int c = E[i].c;
        if(unionBySize(u,v)){
            ans+=c;
        }
    }

    cout<<ans<<endl;

    return 0;
}  
