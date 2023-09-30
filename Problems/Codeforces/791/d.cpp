#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long

const int maxn = 2e5+7;
vector<int> graph[maxn];


vector<int> dp(maxn);
vector<int> vis(maxn);
vector<int> nums;
int upper;

bool findCycle(int v) {
    vis[v] = 1;
    for (int u : graph[v]) {
        if(nums[u]>upper)continue;
        if (vis[u] == 0) {
            if (findCycle(u)){
                return true;
            }
        } else if (vis[u] == 1) {
            return true;
        }
    }
    vis[v] = 2;
    return false;
}

int mx =0;
void dfs(int u){
    dp[u] = 1;
    for(auto v:graph[u]){
        if(nums[v]>upper || dp[v]!=0){
            dp[u] = max(dp[u],dp[v]+1);
            continue;
        };
        dfs(v);
        dp[u] = max(dp[u],dp[v]+1);
    }
    mx = max(mx,dp[u]);
}

int n,m,k;
bool check(int x){
    upper = x;
    dp.assign(n,0);
    vis.assign(n,false);
    for(int i = 0;i<n;i++){
        if(!vis[i] && nums[i]<=x){
            bool areCycle = findCycle(i);
            if(areCycle)return true;
        }
    }
    mx = 0;
    for(int i = 0;i<n;i++){
        if(!dp[i] && nums[i]<=x)
            dfs(i);
    }
    return mx>=k;
}

signed main(){__
    int T = 1,u,v;
    cin>>n>>m>>k;
    
    nums.resize(n);
    for(auto &c: nums)cin>>c;

    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
    }
    vector<int> U = nums;

    sort(U.begin(),U.end());
    U.erase(unique(U.begin(),U.end()),U.end());
    
    int N = U.size();
    int l = 0,r = 1e9+1;
    while(l+1<r){
        int mid = (l+r)>>1;
        if(check(mid))
            r = mid;
        else 
            l = mid;
    }
    if(r == 1e9+1)r =-1;
    cout<<r<<endl;
    return 0;
}