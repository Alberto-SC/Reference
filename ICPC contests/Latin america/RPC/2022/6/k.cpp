#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn =1e6+7;
int mod;
vector<int> color(maxn,-1);
bool bipartite = true;
vector<int> graph[maxn];
void dfs(int u,int p = -1){
    if(p == -1)
        color[u] = 0;
    else 
        color[u] = color[p]^1;
    for(auto v:graph[u]){
        if(color[v]!=-1){
            if(color[v]== color[u])bipartite = false;
            continue;
        }
        dfs(v,u);
    }
}

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}


signed main(){__
    int t,n,m,p,u,v;
    cin>>n>>m>>p;
    mod = p;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cont = 0;
    for(int i = 0;i<n;i++){
        if(color[i]==-1){
            cont++;
            dfs(i);
            if(!bipartite)return cout<<"impossible"<<endl,0;
        }
    }
    cout<<(mod_pow(2,cont-1)+1)%p<<endl;
}   