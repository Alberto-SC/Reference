
const int maxn = 100007;
vector<int> graph[maxn];
vector<bool> vis(maxn);
int sz = 0,mn = maxn;
void dfs(int u){
    vis[u] = true;
    mn = min(u,mn);
    sz++;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
    }
}
int main(){__
    int n,m,u,v;
    while(cin>>n>>m){
        for(int i = 0;i<n;i++){
            graph[i].clear();
            vis[i] = false;
        }
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<pair<int,int>> ans;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                mn =maxn;
                sz = 0;
                dfs(i);
                ans.push_back({mn,sz});
            }
        }

        sort(ans.begin(),ans.end());
        for(auto c:ans){
            cout<<c.first+1<<" "<<c.second<<endl;
        }

    }
    return 0;
}  

