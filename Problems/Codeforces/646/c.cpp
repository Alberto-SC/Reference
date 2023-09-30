#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int cont = 0;
int x;
void dfs(int u,int p = -1){
    if(u != x)cont++;
    for(auto v:graph[u]){
        if(v== p)continue;
        dfs(v,u);
    }
}

int main(){__
    int t,n,v,u;
    cin>>t;
    while(t--){
        cin>>n>>x;
        x--;
        for(int i = 0;i<maxn;i++)graph[i].clear();
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            add_edge(u,v);
        }
        cont = 0;   
        dfs(x);
        if(graph[x].size()== 1|| graph[x].size()== 0)cout<<"Ayush"<<endl;
        else if((cont-1)&1)cout<<"Ashish"<<endl;
        else cout<<"Ayush"<<endl;

    }
    return 0;
}