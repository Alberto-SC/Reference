#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long int lli;
const int maxn = 5007;
vector<int> graph[maxn];
vector<int> sz(maxn);
int n;
vector<bool> possible(maxn),DP(maxn);
int dfs(int u,int p = -1){
    int s = 1;
    vector<int> sizes;
    for(auto v:graph[u]){
        if(v == p)continue;
        int z = dfs(v,u);
        s+=z;
        sizes.push_back(z);
    }
    if(sizes.size()){
        if(p!= -1)
            sizes.push_back(n-s);
        for(int i = 0;i<n;i++)DP[i] = 0;
        DP[0] = 1;
        for(auto x:sizes){
            for(int i = n-x;i>=0;i--){
                if(DP[i])possible[i+x]= true,DP[i+x] = true;
            }
        }
    }
    return s;
}

int main(){__  
    int u,v;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);
    vector<pair<int,int>> ans;
    for(int i = 1;i<=n-2;i++){
        if(possible[i]){
            ans.push_back({i,n-1-i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto [u,v]:ans)cout<<u<<" "<<v<<endl;
    return 0;
}