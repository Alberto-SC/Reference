#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define y second
#define x first
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 200007;
const int INF = 1000000007;
vector<pair<int,int>> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back({v,1});    
    graph[v].push_back({u,1});    
}
int D[maxn];
void dijlstra(){
    for(int i = 0;i<maxn;i++)D[i] = INF;
    D[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> p = q.top();
        q.pop();
        int u = p.y;
        int dist = p.x;
        if(dist> D[u])continue;
        for(auto pr :graph[u]){
            int v = pr.x;
            int next_dist = dist+pr.y;
            if(next_dist<D[v]){
                D[v] = next_dist;
                q.push({next_dist,v});                 
            }
        }

    }
}

int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dijlstra();
    cout<<D[n-1]-1<<endl;
    return 0;
}