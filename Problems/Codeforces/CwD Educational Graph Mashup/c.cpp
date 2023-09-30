#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
vector<int> C(maxn);
vector<int> parent(maxn,-1);
void dfs(int u,int prev = -1,int l = 0){
    vis[u] = true;
    if(prev!= -1)parent[u] = prev; 
    C[u] =l&1;
    for(auto v:graph[u]){
        if(vis[v]){
            if(C[v] == C[u]){
                cout<<"NO"<<endl;
                exit(0);
            }
            else
                continue;
        }
        dfs(v,u,l+1);
    }
}

int main(){
	int t= 1,n,m,u,v;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        edges.push_back({u,v});
        graph[u].push_back(v);        
        graph[v].push_back(u);            
    }
    dfs(0);
    string ans(m,'0');
    for(int i = 0;i<m;i++){
        u = edges[i].first;
        v = edges[i].second;
        if(u == parent[v]){
            if(C[v] == 1)
                ans[i] = '1';
        }
        else if(v == parent[u]){
            if(C[u] == 0)
                ans[i] = '1';
        }
        else{
            if(C[u] == 0){
                ans[i] = '1';
            }
        }
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    return 0;
}  

