#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 2007;
vector<int> nxt[maxn];
vector<int> graph[maxn];
int dp[maxn][maxn];
string s;

int root;
void dfs(int u,int p = -1){
    for(auto v:graph[u]){
        if(v ==p)continue;
        nxt[root][v] = u;
        dfs(v,u);
    }
}

int solve(int u,int v){
    if(u == v)return 1;
    int &x = dp[u][v];
    if(x!=-1)return x;
    int ans = 0;
    
    if(s[u]== s[v]){
        if(nxt[v][u]==v)return x = 2;
        else ans = 2 + solve(nxt[v][u],nxt[u][v]);
    }
    else 
        ans = max({ans,solve(nxt[v][u],v),solve(u,nxt[u][v])});
    return x = ans;
}

signed main(){__
    int T = 1,n,u,v;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        for(int i = 0;i<n;i++){
            graph[i].clear();
            nxt[i].clear();
        }
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            u--,v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i = 0;i<n;i++){
            root = i;
            nxt[i].resize(n);
            dfs(i);
        }
        int ans = 1;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                ans = max(ans,solve(i,j));
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}