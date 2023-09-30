#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int mx = 0;
void dfs(int u,int p = -1,int d = 0){
    mx = max(d,mx);
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
}

int main(){
    int n,p;
    cin>>n;
    vector<int> parent(n);
    for(int i = 0;i<n;i++){
        cin>>p;
        parent[i] = p;
        if(p ==-1)continue;
        p--;
        add_edge(i,p);
    }
    int ans = 0;
    for(int i= 0;i<n;i++){
        if(parent[i] == -1){
            mx = 0;
            dfs(i);
            ans = max(ans,mx+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}