#include <bits/stdc++.h>
using namespace std;
const int maxn= 500007;
vector<int> vis;
vector<int> edge[maxn];
 
int bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=0;
    int max_d=0,last = u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        if(vis[u]>max_d){
            max_d=vis[u];
            last=u;
        }
        for(auto c :edge[u]){
            if(vis[c] == -1){
                q.push(c);
                vis[c] = vis[u]+1;
            }
        }
    }
    return last;
}
int main(){
    int n,u,v,p,q,t,s= 1,ans = 0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        edge[u-1].push_back(v-1);
        edge[v-1].push_back(u-1);
    }
    vis.resize(n,-1);
    p = bfs(0);
    vis.clear();
    vis.resize(n,-1);
    q = bfs(p);
    ans = ceil(log2(vis[q]));
    cout<<ans;
    return 0;
}