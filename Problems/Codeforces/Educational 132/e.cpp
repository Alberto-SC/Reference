#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> graph[maxn];

vector<int> A(maxn);
vector<int> val(maxn);
void dfzx(int u,int p = -1,int x = 0){
    x^=A[u];
    val[u] = x;
    for(auto v:graph[u]){
        if(v==p)continue;
        dfzx(v,u,x);
    }
}

int ans = 0;
set<int> vals[maxn];

void solve(int u,int p = -1){
    vals[u].insert(val[u]);
    bool flag = false;
    for(auto v:graph[u]){
        if(v == p)continue;
        solve(v,u);
        if(vals[v].size()>vals[u].size())vals[u].swap(vals[v]);
        for(auto x:vals[v]){
            if(vals[u].count(A[u]^x))
                flag = true;
        }
        for(auto x:vals[v]){
            vals[u].insert(x);
        }
        vals[v].clear();
    }

    if(flag){
        vals[u].clear();
        ans++;
    }
}

signed main(){__
    int T = 1,n;
    cin>>n;
    A.resize(n);
    for(auto &c:A)cin>>c;
    for(int i= 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfzx(0);
    solve(0);
    cout<<ans<<endl;
    return 0;
}