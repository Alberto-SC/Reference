#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxn = 1000007;
vector<int> graph[maxn];
vector<int> bit(maxn);
vector<int> start(maxn);
vector<int> End(maxn);

int Tm = 0;
void dfs(int u){
    start[u] = Tm++;
    for(auto v:graph[u]){
        dfs(v);
    }
    End[u] = Tm-1;
}

void add(int idx,int v){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=v;
}

int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[idx];
    return res;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}

signed main(){__
    int T = 1,n,m,q,p,u,v,x,t;
    while(T--){
        cin>>n>>m>>q;

        int root = 0;
        for(int i = 0;i<n;i++){
            cin>>p;
            if(p ==0){
                root = i;
                continue;
            }
            p--;
            graph[p].push_back(i);
        }
        dfs(root);
        vector<pair<int,int>> pend;
        vector<int> ans(n);
        for(int i = 0;i<m;i++){
            cin>>t>>u>>x;
            u--;
            if(t ==1)
                pend.push_back({u,x});
            else
                add(start[u],x);
        }


        for(int i = 0;i<n;i++){
            ans[i] = sum(start[i],End[i]);
        }
        bit.assign(maxn,0);
        for(int i = 0;i<n;i++){
            add(start[i],ans[i]);
        }
        for(auto c:pend){
            add(start[c.first],c.second);
        }
        while(q--){
            cin>>t>>u;
            u--;
            if(t ==1)
                cout<<sum(start[u],start[u])<<endl;
            else
                cout<<sum(start[u],End[u])<<endl;
        }
    }
    return 0;
}