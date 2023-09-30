#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];

typedef long long int lli;
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
lli l = 0,r = 0;
void dfs(int u,int d,int p = -1){
    if(d&1)r++;
    else l++;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,d+1,u);
    }
}
int main(){
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dfs(0,0);
    cout<<(l*r)-(n-1)<<endl;
    return 0;
}