#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
#define x first
#define y second
vector<pair<int,int>> graph[maxn];

void add_edge(int u,int v,int r){
    graph[u].push_back({v,r});
    graph[v].push_back({u,r});
}
set<int> s;
void dfs(int u,int r,int p = -1){
    bool poss;
    r ==1? poss =true:poss = false;
    // cout<<u<<" "<<r<<endl;
    for(auto v:graph[u]){
        if(v.x == p)continue;
        dfs(v.x,v.y,u);
        if(v.y == 0)poss = false;
    }
    if(poss)s.insert(u);
}
int main(){
    int n,p,r;
    cin>>n;
    int root = -1;
    for(int i = 0;i<n;i++){
        cin>>p>>r;
        if(p == -1){root = i+1;continue;}
        add_edge(i+1,p,r);
    }
    dfs(root,0);
    if(s.size()==0)return cout<<-1<<endl,0;
    for(auto c:s)cout<<c<<" ";
    cout<<endl;
    return 0;
}