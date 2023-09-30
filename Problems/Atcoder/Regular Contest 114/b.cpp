#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;

const int mod = 998244353;
int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}
vector<int> g[maxn],gr[maxn],graph[maxn];
vector<bool> used(maxn),vis(maxn);
vector<int> order, component;
void dfs1(int u) {
    used[u] = true;
    for(auto v:g[u]){
        if(!used[v])
            dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u) {
    used[u] = true;
    component.push_back(u);
    for(auto v:gr[u]){
        if(!used[v])
            dfs2(v);
    }
}

void dfs(int u){
    vis[u] = true;
    for(auto v:graph[u]){
        if(!vis[v])
            dfs(v);
    }
}

signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> z[n+1];
    for(int i = 0;i<n;i++){
        g[i].push_back(nums[i]-1);
        gr[nums[i]-1].push_back(i);
        z[nums[i]].push_back(i); 
    }

    for(int i= 0;i<=n;i++){
        for(int j = 1;j<z[i].size();j++){
            g[z[i][j-1]].push_back(z[i][j]);
            g[z[i][j]].push_back(z[i][j-1]);
            gr[z[i][j]].push_back(z[i][j-1]);
            gr[z[i][j-1]].push_back(z[i][j]);
        }
    }

    int c = 0;
    used.assign(n,false);
    for(int i=0;i<n;i++)
        if(!used[i])
            dfs1(i);
    used.assign(n,false);
    vector<int> p(n);
    for(int i=0;i<n;i++){
        int v = order[n-1-i];
        if(!used[v]){
            dfs2(v);
            for(auto d:component)
                p[d] = c;
            c++;
            component.clear();
        }
    }
    // for(auto d:p)cout<<d<<" ";
    // cout<<endl;
    for(int i = 0;i<n;i++){
        graph[p[nums[i]-1]].push_back(p[i]);
        graph[p[i]].push_back(p[nums[i]-1]);
    }

    int cont = 0;
    for(int i = 0;i<c;i++){
        if(!vis[i]){
            dfs(i);
            cont++;
        }
    }

    int ans = mod_pow(2,cont)-1;
    if(ans<0)ans+=mod;
    cout<<ans<<endl;
    return 0;
}  
