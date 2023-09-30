#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 100007;
vector<int> graph[maxn];

void dfs(int u ,int pr = -1,int lev = 0){
    lvl[u] = lev;
    sz[u]= 1;
    int mx= 0;
    p[u] = pr;
    for(auto v:graph[u]){
        if(v.x == pr)continue;
        val[v.x] = v.y;
        dfs(v.x,u,lev+1);
        if(sz[v.x]>mx){
            mx = sz[v.x];
            heavy[u] = v.x;
        }
        sz[u]+=sz[v.x];
    }
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
    }
    return 0;
}