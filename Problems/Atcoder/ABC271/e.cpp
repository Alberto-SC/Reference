#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
int dp[maxn];

struct st{
    int u,v,c;
};
int N,k;
vector<st> road;

vector<int> nxt[maxn];

const int inf = 1e18;
int solve(int idx,int sum = 0){
    if(idx == k)return inf;
    if(road[idx].u == N)return 0;

    int &x = dp[idx];
    if(x!=-1)return x;

    int ans = inf;
    int u = road[idx].u;
    int v = road[idx].v;
    int c = road[idx].c;

    if(v == N){
        ans = c;
    }

    int nxtu = upper_bound(nxt[u].begin(),nxt[u].end(),idx)-nxt[u].begin();
    int nxtv = upper_bound(nxt[v].begin(),nxt[v].end(),idx)-nxt[v].begin();


    if(nxtu<nxt[u].size())
        ans = min(ans,solve(nxt[u][nxtu]));
    
    if(nxtv<nxt[v].size())
        ans = min(ans,solve(nxt[v][nxtv],sum+c)+c);
    if(ans >inf)ans = inf;
    return x = ans;
}

signed main(){__
    int m,u,v,c;
    cin>>N>>m>>k;
    vector<st> V(m);
    for(int i = 0;i<m;i++){
        cin>>u>>v>>c;
        V[i] = {u,v,c};
    }

    

    for(int i = 0;i<k;i++){
        int x;cin>>x;
        road.push_back(V[x-1]);
    }

    for(int i = 0;i<k;i++){
        nxt[road[i].u].push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    int ans = inf;
    if(nxt[1].size())
        ans = solve(nxt[1][0]);
    if(ans == inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
