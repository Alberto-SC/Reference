#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli inf = 1e15;
const int maxn =100007;
vector<int> dist(maxn);
#define x first
#define y second
vector<pair<int,int>> graph[maxn];
vector<int >parent(maxn);
int t,nmx = -1;
lli ans;
void dfs(int u,int p = -1,int d = 0){
    dist[u] = d;
    if(u ==nmx)ans -= d;

    for(auto v:graph[u]){
        if(v.x == p)continue;
        dfs(v.x,u,d+v.y);
    }
}


int main(){
    int n,u,v,w;
    cin>>n;
    pair<int,int> edge;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v>>w;
        graph[--u].push_back({--v,w}); 
        graph[v].push_back({u,w}); 
        ans+=2*w;
    }
    dfs(0);
    int mx = -1;
    for(int i = 0;i<n;i++){
        if(dist[i]>mx){
            mx = dist[i];
            nmx = i;
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}