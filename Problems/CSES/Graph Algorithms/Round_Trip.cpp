#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

const int maxn = 100007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
vector<int> parent(maxn);
vector<int> ans;
int startV = -1 ,endV = -1;
bool flag;

void dfs(int u,int p = -1){
    vis[u] = true;
    for(auto v:graph[u]){
        if(v == p)continue;
        if(!vis[v]){
            parent[v] = u;
            dfs(v,u);
        }
        else if(!flag){
            flag = true;
            int aux = u;
            ans.push_back(v);
            while(aux!= v){
                ans.push_back(aux);
                aux = parent[aux];
            }
            ans.push_back(v);
        }
    }
}

signed main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()){
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c+1<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
    cout<<endl;
}