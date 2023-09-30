#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> dist[1007];
vector<int> graph[1007];
const int inf = 1e9;
int k;
void bfs(int s,int n){
    dist[s].assign(n,inf);
    dist[s][s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:graph[u]){
            if(dist[s][v]>(dist[s][u]+k)){
                dist[s][v]  = dist[s][u]+k;
                q.push(v);
            }
        } 
    }
}

vector<int> P(1007);
vector<int> D(1007);
vector<int> S(1007);
vector<int> K(1007);
vector<int> E(1007);
int T,O;

int dp[1007][10001];
int solve(int idx,int t){
    if(t<0)return -inf;
    if(idx == O)return 0;
    int &x = dp[idx][t];
    if(x!=-1)return x;

    int ans = -inf;
    ans = max(ans,solve(idx+1,t-K[idx]));
    ans = max(ans,solve(idx+1,t-E[idx])+S[idx]);
    return x= ans;
}

signed main(){__
    int n,m,u,v;
    cin>>n>>m>>k;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0;i<n;i++){
        bfs(i,n);
    }
    cin>>O>>T;
    for(int i = 0;i<O;i++){
        cin>>P[i];
        P[i]--;
    }
    int last = 0;
    for(int i = 0;i<O;i++){
        cin>>D[i];
        D[i]--;
        cin>>S[i];
        if(i!=O-1){
            K[i] = dist[P[i]][P[i+1]];
            E[i] = dist[P[i]][D[i]]+dist[D[i]][P[i+1]];
        }
        else{
            K[i] = dist[P[i]][0];
            E[i] = dist[P[i]][D[i]]+dist[D[i]][0];
        }
    }

    memset(dp,-1,sizeof(dp));
    int ans = solve(0,T-dist[0][P[0]]);
    if(ans <0)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}