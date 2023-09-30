#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
vector<int> sz(maxn);
set<int> nodes;
set<int> complexes;
void dfs(int u,int p = -1){
    if(complexes.count(u)){
        nodes.insert(u);
    }  
    else {
        int x = sz[u];
        int y = sz[0]-sz[u];
        int cont = 0;
        for(auto v:graph[u]){
            if(v.second==p)continue;
            if(sz[v.second])cont++;
        }
        if((y>=1)+cont>=2)nodes.insert(u);
    }
    for(auto v:graph[u]){
        if(v.second == p)continue;
        dfs(v.second,u);
    }
}

void dfs_sz(int u,int p = -1){
    if(complexes.count(u))
        sz[u] = 1;
    for(auto v:graph[u]){
        if(v.second ==p)continue;
        dfs_sz(v.second,u);
        sz[u]+=sz[v.second];
    }
}

int main(){__
	int t= 1,n,k,u,v,c,x;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v>>c;
        u--,v--;
        graph[u].push_back({c,v});
        graph[v].push_back({c,u});
    }
    for(int i = 0;i<k;i++){
        cin>>x;
        x--;
        complexes.insert(x);
    }
    dfs_sz(0);
    dfs(0);
    cout<<nodes.size()<<endl;
    return 0;
}  

