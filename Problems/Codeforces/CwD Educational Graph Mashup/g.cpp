#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
set<int> graph[maxn];
vector<int> disc(maxn);
vector<int> low(maxn);
vector<bool> bridge(maxn);
vector<bool> vis(maxn,false);
vector<int> label(maxn,-1);
vector<int> p(maxn);
int idx = 0;
int lbl = -1;
void dfs(int u,int parent =-1){
    disc[u] = idx++;
    vis[u] = true;
    label[u] = lbl;
    p[u] = parent;
    low[u] =disc[u];
    for(auto v:graph[u]){
        if(v == parent)continue;
        if(!vis[v]){
            dfs(v,u);
            if(low[v]>disc[u])bridge[v] = true;
        }
        low[u] = min(low[u],low[v]);
    }
}
vector<bool> vis2(maxn);
void dfs2(int u,int parent){
    // cout<<u<<endl;
    vis2[u] = true;
    p[u] = parent;
    for(auto v:graph[u]){
        if(!vis2[v])
            dfs2(v,u);
    }
}
int main(){__
	int n,m,d,u,v;
    cin>>n>>m>>d;
    iota(p.begin(),p.end(),0);
    vector<pair<int,int>> edges;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    dfs(0);
    for(int i = 0;i<n;i++)
        vis[i] = false;
    vis[0] = true;
    lbl = 0;
    int br = 0;
    for(auto v:graph[0]){
        if(bridge[v]){
            dfs(v,0);
            lbl++;
            br++;
            d--;
        }


    }
    if(d<0)return cout<<"NO"<<endl,0;
    for(int i = 1;i<n;i++){
        if(!vis[i]){
            dfs(i);
            lbl++;
        }
    }
    for(int i = 0;i<n;i++)
        vis[i] = false;
    
    vis[0] = true;
    if(lbl-br>d)return cout<<"NO"<<endl,0;
    // cout<<lbl<<endl;
    vector<int> used(lbl);
    vector<int> rep(lbl);
    for(int i = 1;i<n;i++){
        // cout<<label[i]<<" ";
        if(used[label[i]])continue;
        if(bridge[i] && graph[i].count(0)){
            rep[label[i]] = i;
            vis[i] = true;
            p[i] = 0;
        }
        else if(graph[i].count(0)){
            used[label[i]] = true;
            p[i] = 0;
            vis[i] = true;
            d--;
            rep[label[i]] = i;
        }
    }
    // cout<<endl;
    if(d<0)return cout<<"NO"<<endl,0;
    if(d>0){
        for(int i = 0;i<n;i++){
            if(d == 0)break;
            if(!vis[i]&& graph[i].count(0)){
                vis[i] = true;
                p[i] = 0;
                d--;
            }
        }
    }
    if(d)return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    for(int i = 0;i<n;i++){
        vis2[i]= vis[i];
        // cout<<vis[i]<<" ";
    }
    // cout<<endl;
    // cout<<"AFTER"<<endl;

    for(int i = 1;i<n;i++){
        // if(!vis[i] && graph[i].count(rep[label[i]]))
            // dfs(i,rep[label[i]]);
        if(vis[i])
            dfs2(i,0);
    }
    for(int i = 1;i<n;i++)
        cout<<i+1<<" "<<p[i]+1<<endl;
    
    return 0;
}  

