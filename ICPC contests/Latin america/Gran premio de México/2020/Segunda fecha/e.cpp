#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
const int maxn = 100007;
vector<int> bit(maxn);
int edad[maxn];
int pa[25][maxn];
int ans[maxn];
vector<int> lefts[maxn];
vector<int> graph[maxn];

int sum(int idx){
    int ans = 0;
    for(++idx;idx>0;idx -=idx& -idx)ans+=bit[idx];
    return ans;
}
void add(int idx,int x){
    for(++idx;idx<maxn;idx+= idx& -idx)bit[idx]+=x;
}

void dfs(int u,int p = -1){
    pa[0][u] = p;
    for(int i = 0;i<lefts[u].size();i++)
        add(lefts[u][i],1);
    ans[u] = sum(edad[u]);
    // cout<<u<<" "<<lefts[u].size()<<endl;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u);
    }
    for(int i = 0;i<lefts[u].size();i++)
        add(lefts[u][i],-1);
}


int main(){__
    int n,e,p,u,v,l,r,q;
    cin>>n>>q;
    for(int i = 0;i<n;i++){
        cin>>e>>p;
        edad[i] = e;
        if(i){
            graph[i].push_back(--p);
            graph[p].push_back(i);
        }
    }
    dfs(0);
    for(int i = 1;i<25;i++)
        for(int u = 0;u<n;u++)
            if(pa[i-1][u]!=-1)
                pa[i][u] = pa[i-1][pa[i-1][u]];
    for(int i = 0;i<q;i++){
        cin>>u>>l>>r;
        u--;
        for(int i = 24;i>=0;i--)
            if(pa[i][u]!=-1 && edad[pa[i][u]]<=r)
                u = pa[i][u];
        // cout<<u<<endl;
        lefts[u].push_back(l);
    }
    dfs(0);
    for(int i = 0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}