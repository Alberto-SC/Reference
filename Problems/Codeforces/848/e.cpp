#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct Basis {
    vector<int> a;
    void insert(int x) {
        for (auto &i: a) x = min(x, x ^ i);
        if (!x) return;
        for (auto &i: a) if ((i ^ x) < i) i ^= x;
        a.push_back(x);
        sort(a.begin(), a.end());
    }

    int maxxor(int x = 0) {
        for (auto &i: a) x = max(x, x ^ i);
        return x;
    } 
    void clean(){
        a.clear();
    }
    Basis operator+(const Basis &b) const {
        Basis nw = b;
        for (auto c:a)
            nw.insert(c);
        return nw;
    }
};

const int maxn = 200007;
vector<Basis> bs(maxn);
vector<int> graph[maxn];
vector<int> vals(maxn);
vector<int> ans(maxn);
vector<pair<int,int>> queries[maxn];

void dfs(int u,int p = -1){
    bs[u].insert(vals[u]);

    for(auto v:graph[u]){
        if(v == p)continue;
        
        dfs(v,u);
        for(auto c:bs[v].a)
            bs[u].insert(c);
        
    }
}

Basis zero;
void dfs2(int u,int p = -1){
    for(auto c:queries[u])
        ans[c.second] = bs[c.first].maxxor();
    
    int M = graph[u].size();
    if(M == 0)return;
    vector<Basis> pref(M);
    vector<Basis> suff(M);

    pref[0] =  bs[graph[u][0]];
    suff.back() = bs[graph[u].back()];

    for(int i = 1;i<M;i++){
        int v = graph[u][i];
        pref[i] = pref[i-1]+bs[v];
    }

    for(int i = M-2;i>=0;i--){
        int v = graph[u][i];
        suff[i] = suff[i+1]+bs[v];
    }

    Basis copy = bs[u];

    for(int i = 0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(v== p)continue;

        Basis nw;
        nw.insert(vals[u]);

        if(i-1>=0){
            for(auto c:pref[i-1].a){
                nw.insert(c);
            }
        }
        if(i+1<graph[u].size()){
            for(auto c:suff[i+1].a){
                nw.insert(c);
            }
        }
        
        bs[u] = nw;
        Basis copyv = bs[v];
        bs[v] = copy;
        dfs2(v,u);
        bs[v] = copyv;
    }
    bs[u] = copy;
}

signed main(){__
    int T = 1,n,u,v,r;
    cin>>T;
    while(T--){
        cin>>n;

        for(int i = 0;i<n;i++){
            graph[i].clear();
            bs[i].clean();
            queries[i].clear();
        }

        for(int i = 0;i<n;i++)
            cin>>vals[i];

        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int q;
        cin>>q;
        for(int i = 0;i<q;i++){
            cin>>r>>u;
            r--,u--;
            queries[r].push_back({u,i});
        }

        dfs(0);

        dfs2(0);

        for(int i = 0;i<q;i++){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}