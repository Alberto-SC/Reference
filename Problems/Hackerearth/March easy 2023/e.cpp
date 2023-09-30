#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

const int maxn = 100007;

vector<int> graph[maxn];
vector<int> val(maxn);
vector<int> leaf(maxn);
void dfs(int u,int p = -1){
    int c = 0;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs(v,u);
        val[u]+=(val[v]==1);
        c++;
    }
    if(c == 0)val[u] = u%2,leaf[u] = true;;
}

vector<int> ans(maxn);

void dfs2(int u,int p = -1,int x = 0){
    int res = 0;
    for(auto v:graph[u]){
        if(v == p)continue;
        res+=val[v];
    }
    ans[u] = x+ res;

    for(auto v:graph[u]){
        if(v == p)continue;
        res-=val[v];
        dfs2(v,u,res>=1 | x );
        res+=val[v];
    }
}


signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear(),leaf[i] = false,val[i] = 0,ans[i] = 0;
        for(int i= 0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0);
        dfs2(0);
        for(int i = 0;i<n;i++){
            cout<<ans[i]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}

