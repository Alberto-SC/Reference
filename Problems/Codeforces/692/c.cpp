#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
bool ciclo;
unordered_map<int,bool> vis;
unordered_map<int,vector<int>> graph;
int cont = 0;
int s;
void dfs(int u,int p = -1){
    cont++;
    // cout<<u<<endl;
    vis[u] = true;
    for(auto v:graph[u]){
        if(v == p)continue;
        if(vis[v] && v == s)ciclo = true;
        else if(!vis[v])
            dfs(v,u);
    }
}

int main(){__
	int t= 1,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        auto f = [&](int x,int y){
            return (x*n)+y;
        };
        vector<pair<int,int>> rocks;
        vector<int> cols(n,-1);
        vector<int> rows(n,-1);
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            rows[u] = v;
            cols[v] = u;
            rocks.push_back({u,v});
        }
        for(auto [x,y]:rocks){
            if(x == y)continue;
            if(rows[y]!= -1){
                // cout<<x<<" "<<y<<endl;
                graph[f(x,y)].push_back(f(y,rows[y]));
                graph[f(y,rows[y])].push_back(f(x,y));
            }
        }
        int ans = 0;
        for(auto [x,y]:rocks){
            if(!vis[f(x,y)] && x!=y){
                ciclo = false;
                s = f(x,y);
                // cout<<"S: "<<s<<endl;
                cont = 0;
                dfs(f(x,y));
                // cout<<cont<<endl;
                if(cont == 2){
                    if(graph[s].size()==2 && graph[s][0]== graph[s][1] && graph[graph[s][0]].size()==2 && 
                    graph[graph[s][0]][0] == graph[graph[s][0]][1]){
                        ans+=3;
                    }
                    else
                        ans+=2;                    
                }
                else{
                    if(ciclo)ans+=cont+1;
                    else ans+=cont;
                }
            }
        }
        graph.clear();
        vis.clear();
        cout<<ans<<endl;
    }
    return 0;
}  

