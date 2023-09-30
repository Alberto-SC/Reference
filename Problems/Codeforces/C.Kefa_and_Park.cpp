#include <bits/stdc++.h> 
using namespace std;
int n,m;
vector<int> cats;
const int MAXN = 10e5+7;
vector<int> graph[MAXN];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
int ans; n nmn
void dfs(int u,int p,int ncats){
    // cout<<u+1<<" "<<ncats<<endl;
    if(ncats>m)return;
    int ok = 1;
    for(auto c:graph[u]){
        if(c!= p){
            ok = 0;
            if(ncats+cats[c]>m)
                dfs(c,u,1000000000);
            else{
                if(cats[c])
                    dfs(c,u,ncats+1);
                else dfs(c,u,0);
            }
        }
    }
    ans+=ok;
}
int main(){
    int u,v;
    cin>>n>>m;
    cats.resize(n);
    for(auto &c:cats)cin>>c;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        add_edge(--u,--v);
    }
    dfs(0,0,cats[0]);
    cout<<ans<<endl;
    return 0;
}