#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100005;
vector<int> graph[maxn];
set<int> poss;
vector<bool> used(maxn);
vector<int> deep(maxn);
int k;
void dfs1(int u,int p = -1,int d = 0){
    deep[u] = d;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs1(v,u,d+1);
    }
}

void dfs (int u, int p = -1,int d = 0) {
    if(d>k)return ;
    if(!used[u])
        poss.insert(u);
    for (int v : graph[u]){   
        if(v ==p)continue;
        dfs(v,u,d+1);
    }
}

signed main(){__
    int n,u,v;
    cin>>n>>k;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    used[0] = true;
    vector<int> ans;
    ans.push_back(1);
    dfs1(0);
    dfs(0);
    while(poss.size()){
        auto it = poss.begin();
        ans.push_back(*it+1);
        used[*it] = true;
        dfs(*it);
        poss.erase(it);
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
}

 