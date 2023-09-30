#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn  =100007;
#define x first
#define y second
const int INF = 1000000007;
set<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].insert(v);
    graph[v].insert(u);
}
int top;
vector<int> q(maxn);
vector<int> D(maxn);
int n;
void bfs(int s){
    for(int i = 0;i<n;i++)D[i] = INF;
    q[top++] = s;
    D[s] = 0;
    for(int i = 0;i<top;i++){
        int u = q[i];
        for(auto v:graph[u]){
            if(D[v] <= D[u]+1)continue;
            D[v] = D[u]+1;
            q[top++] = v;
        }
    }
}   

int main(){__
    cin>>n;
    vector<lli> nums(n);
    for(auto &c :nums)cin>>c;
    vector<pair<int,int>> edges;
    for(int i = 0;i<60;i++){
        int f = -1,s = -1;
        int cont = 0;
        for(int j = 0;j<n;j++){
            if((nums[j]>>i)&1){
                if(f == -1)
                    f =j;
                else s = j;
                cont++;
            }
        }
        if(cont>2)return cout<<3<<endl,0;
        if(cont== 2){
            add_edge(f,s);
            edges.push_back({f,s});
        }
    }

    int ans = 10000000;
    for(int i = 0;i<edges.size();i++){
        graph[edges[i].x].erase(edges[i].y);
        graph[edges[i].y].erase(edges[i].x);
        bfs(edges[i].x);
        ans = min(ans,D[edges[i].y]+1);
        graph[edges[i].x].insert(edges[i].y);
        graph[edges[i].y].insert(edges[i].x);
    }
    if(ans == 10000000)return cout<<-1<<endl,0;
    cout<<ans<<endl;
    return 0;
}