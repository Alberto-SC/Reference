#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 300007;
#define x first
#define y second
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
vector<int> depth(maxn);
int q[maxn];
int top;
vector<int> dist[2];
const int INF = 10000000;
pair<int,int> bfs(int s,int n,int who){
    for(int i = 0;i<n;i++)dist[who][i] = INF;
    q[top++] = s;
    dist[who][s] = 0;
    pair<int,int> ans;
    ans.x = -1;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(dist[who][v]< dist[who][u]+1)continue;
            dist[who][v] = dist[who][u]+1;
            q[top++] = v;
            if(dist[who][v]>ans.y){
                ans.y = dist[who][v];
                ans.x = v; 
            }
        }
    }
    return ans;
}


int main(){__
    int n,u,v;
    cin>>n;
    if(n == 1)return cout<<1<<endl,0;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    dist[0].resize(n+5);
    dist[1].resize(n+5);
    auto dim = bfs(0,n,0);
    top = 0;
    dim = bfs(dim.x,n,1);   
    // bfs(dim,n,0);
    top = 0;
    for(int i = 0;i<n;i++)
        if(dist[1][i] == dim.y){bfs(i,n,0);break;}
    for(int i = 0;i<n;i++){
        if(dist[0][i] == dim.y||dist[1][i] == dim.y || dist[0][i]== 0 || dist[1][i] == 0)cout<<dim.y+1<<endl;
        else cout<<dim.y<<endl;
    }
    return 0;
}

