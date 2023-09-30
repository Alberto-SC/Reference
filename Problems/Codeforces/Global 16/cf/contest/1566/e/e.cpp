#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];

vector<int> buds;
vector<int> leafs;
vector<int> sz(maxn);
vector<int> parent(maxn);
vector<bool> bud(maxn);
void dfs(int u,int p = -1){
    sz[u] = 1;
    parent[u] = p;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
    bool flag = true;
    int cont = 0;
    for(auto v:graph[u]){
        if(v==p)continue;
        if(sz[v]>1)flag = false;
        cont++;
    }
    if(flag && cont){
        bud[u] = true;
        // buds.push_back(cont);
    }
    if(cont==0)
        leafs.push_back(u);
}
signed main(){__
	int t= 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)
            graph[i].clear(),bud[i] = false;
        leafs.clear();
        buds.clear();

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0);
        int ans = leafs.size();
        for(int i = 1;i<n;i++){
            if(bud[i] && parent[i]!= 0 && graph[parent[i]].size()==2){
                bud[i] = false;
            }
            else if(bud[i])buds.push_back(sz[i]-1);

        }
        for(auto c:leafs){
            if(bud[parent[c]])ans--;
        }
        if(ans)
            ans--;
        sort(buds.begin(),buds.end());

        int C,i = 0;
        if(ans)
            C = ans;
        else C = buds[0],i = 1;
        for(;i<buds.size();i++){
            C--;
            C+=buds[i];
        }
        cout<<ans+C<<endl;
    }
    return 0;
}  
