#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1000;
vector<int> graph(maxn,-1);
vector<bool> vis(maxn);
int cont = 0;
void dfs(int u,int d = 0){
    vis[u] = true;
    if(graph[u]==-1)return;
    if(vis[graph[u]]){
        cont = d+1;
        return;
    }
    dfs(graph[u] ,d+1);
}
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        map<string,int> mp;
        int key = 0;
        string x,y,z;
        for(int i = 0;i<n;i++){
            cin>>x>>y>>z;
            if(!mp.count(y))
                mp[y]=key++;
            if(!mp.count(z))
                mp[z] = key++;
            graph[mp[y]] =mp[z];
        }
        int ans = 0;
        for(int i = 0;i<key;i++){
            if(vis[i])continue;
            cont = 0; 
            dfs(i);
            ans = max(ans,cont);
        }
        if(ans)
            cout<<ans<<endl;
        else
            cout<<"No trades possible"<<endl;
    }
    return 0;
}  
