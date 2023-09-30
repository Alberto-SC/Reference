#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int cont = 0;

const int maxn = 100007;
vector<int> vis(maxn);
vector<int> graph[maxn];
const int INF = 1e9;
void dfs(int u){
    vis[u] = true;
    cont++;
    for(auto v:graph[u]){
        if(vis[v])continue;
        dfs(v);
    }
}

bool Lucky(int x){
    while(x){
        if(x%10!= 4 && x%10 !=7)return false;
        x/=10;
    }
    return true;
}

signed main(){__
	int t,n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    map<int,int> mp;

    vector<bool> isLucky(maxn);
    for(int i = 1;i<maxn;i++)
        if(Lucky(i))isLucky[i] = true;
    
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            cont = 0;
            dfs(i);
            mp[cont]++;
            if(isLucky[cont])return cout<<0<<endl,0;
        }
    }

    vector<int> dp(n+1,INF);

    dp[0] = 0;
    for(auto c:mp){
        vector<int> ndp  = dp;
        int k = c.second;
        for(int i = 0;i<c.first;i++){
            int sum = 0;
            deque<pair<int,int>> window;
            for(int j = i,mul = 0;j<=n;j+=c.first,mul++){
                while (!window.empty() && window.front().second < mul - k){
                    window.pop_front();
                }

                if (!window.empty())ndp[j] = min(ndp[j],window.front().first + mul);
                
                while (!window.empty() && window.back().first >= dp[j] - mul){
                    window.pop_back();
                }
                
                window.emplace_back(dp[j] - mul, mul);
            }
            
        }
        swap(dp,ndp);
    } 
    int ans = INF;
    for(int i = 1;i<=n;i++){
        if(isLucky[i] && dp[i]!= INF)
            ans = min(ans,dp[i]);
    }
    if(ans == INF)cout<<-1<<endl;
    else cout<<ans-1<<endl;
    return 0;
} 

