#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
const lli mod = 998244353;
const int maxn = 300007;
vector<int> depth(maxn);
vector<int> vis;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

vector<int> colors(maxn);
int a,b;
bool dfs(int u,int p = -1,int d = 0){
    depth[u] = d;
    if(colors[u])b++; 
    else a++;
    vis[u] = true;
    for(auto v:graph[u]){
        if(vis[v]){
            if(colors[v] == colors[u])return false;
            continue;
        }
        colors[v] = !colors[u];

        if(!dfs(v,u,d+1))return false;
    }
    return true;
}
lli mod_pow(lli a,lli b){
    lli x = 1;
    while(b){
        if(b&1) x = (x*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vis.assign(n,0);
        for(int i = 0;i<n;i++)graph[i].clear();
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--,v--;
            add_edge(u,v);
        }
        lli ans = 1;
        bool flag = true;
        colors.assign(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                colors[i] = 0;
                a = 0;
                b = 0;
                if(!dfs(i)){
                    flag = false;
                    break;
                }
                else {
                    lli ans2 = 1;
                    lli ans1 = 1;
                    ans2 = mod_pow(2,a);
                    ans1 = mod_pow(2,b);
                    ans = (ans*((ans2+ans1)%mod))%mod;
                }
            }
        }
        if(flag)cout<<ans<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
