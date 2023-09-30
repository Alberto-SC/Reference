#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 400007;
vector<int> graph[maxn];
vector<int> ans(maxn);
vector<int> parents[maxn];
int top = 0;
int q[maxn*4];
void bfs(){
    q[top++] = 0;
    vector<bool> vis(maxn);
    vis[0] = true;
    ans[0] = 1;
    for(int i = 0;i<top;i++){
        int u = q[i];
        vis[u] = true;
        for(auto v:graph[u]){
            if(vis[v])
                continue;
            int cont = 0;
            bool inf = false;
            for(auto p:parents[v]){
                if(ans[p]==-1|| p == v)inf = true;
                if(ans[p]==2)cont+=2;
                if(ans[p]==1)cont++;
            }  
            if(inf)
                ans[v] = -1;
            else if(cont>1)
                ans[v] = 2;
            else
                ans[v] = 1;
            q[top++] = v;
        }
    }
}
signed main(){__
	int t= 1,n,u,v,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0 ;i<n;i++)
            graph[i].clear(),ans[i] = 0;
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            graph[u-1].push_back(v-1);
            parents[v-1].push_back(u-1);
        }
        bfs();
        for(int i = 0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  
