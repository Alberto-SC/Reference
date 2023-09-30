#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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
	int t= 1,n,q,type,u,v;
    cin>>n>>q;
    for(int i = 0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>u>>v;
            u--,v--;
            unionBySize(u,v);
        }
        else{
            
        }
    }
    return 0;
}  
