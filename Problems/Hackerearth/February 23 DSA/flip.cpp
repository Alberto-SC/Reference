#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

using namespace std;
const int maxn = 100007;

vector<int> graph[maxn];
vector<int> st(maxn);
vector<int> End(maxn);
vector<int> bit(maxn);
int TM = 0;


void add(int idx,int val){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=val;
}

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

void dfs(int u,int p = -1){
    st[u] = TM++;

    for(auto v:graph[u]){
        if(v == p)continue;

        dfs(v,u);
    }

    End[u] = TM-1;
}

signed main(){__
    int T,n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(auto &c:v)cin>>c;
        
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);

    while(q--){
        int x;
        cin>>x;
        x--;
        add(st[x],1);
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(sum(st[i],End[i])&1)
            v[i]^=1;
        ans+=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
