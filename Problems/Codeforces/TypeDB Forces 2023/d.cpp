#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> vis(maxn);
vector<int> dp(maxn,1e9);
vector<int> check;
int cont = 0;
int n;
vector<int> graph[maxn];

bool dfs(int u,vector<int> &v,int p = 0){
    if(u<=0 || u>n){
        return true;
    }
    if(vis[u]){
        if(dp[u] != 1e9)return dp[u];
        else return false;
    }
    vis[u] = true;

    if(p == 1)check.push_back(u);

    dp[u] = dfs(u+v[u],v,p);

    if(dp[u])cont++;
    return dp[u];
}

vector<int> sz(maxn);
void dfs2(int u,int p = -1){
    sz[u] = 1;
    for(auto v:graph[u]){
        if(v ==p)continue;
        dfs2(v,u);
        sz[u]+=sz[v];
    }
}

signed main(){__
    int T = 1;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n+1);
        check.clear();
        for(int i = 0;i<=n;i++){
            graph[i].clear();
            dp[i]= 0;
            vis[i] = false;
            sz[i] = 0;
        }

        for(int i = 1;i<=n;i++){
            cin>>nums[i];
            if(i +nums[i]<= 0 || i+nums[i]>n)
                graph[0].push_back(i);
            else
                graph[i+nums[i]].push_back(i);
        }

        cont = 0;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                if(i ==1)
                    dfs(i,nums,1);
                else 
                    dfs(i,nums);
            }
        }


        int ans = 0;
        dfs2(0);
        for(auto c:check){
            ans+=n+1;
            if(dp[c]==1)
                ans+=cont-sz[c];
            else
                ans+=cont;
        }
        if(dp[1]==1)
            ans+=(n-check.size())*((2*n)+1);
        cout<<ans<<endl;
    }
    return 0;
}