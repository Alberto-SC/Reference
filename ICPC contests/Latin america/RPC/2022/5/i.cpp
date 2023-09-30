#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'


struct Edge{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;
void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v); 
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    N+=7;
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;
        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }
        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }
    if (flow < K)
        return -1;
    else{
        return cost;
    }
}

char M[10][10];
int n,m;
vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};
bool valid(int x ,int y){
    if(x<0 || y<0 )return false;
    if(x>=n || y>= m)return false;
    return true;
}
bool valid2(int x,int y){
    int c = 0;
    c+=M[x][y]== '#';
    for(int i = 0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        // if(!valid(nx,ny))return false;
        if(valid(nx,ny))
            c+=M[nx][ny] == '#';
    }
    return c== 5;
}

signed main(){__
    int t;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>M[i][j];

    vector<Edge> E;
    auto f = [&](int x,int y){
        return (x*m)+y;
    };



    int N = n*m,cont = 0;
    vector<int> rev;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(M[i][j]== '.')continue;
            cont++;
      
            E.push_back({f(i,j)+N,(2*N)+1,1,0});
            if(valid2(i,j)){
                E.push_back({f(i,j),f(i,j)+N,1,0});
                for(int k = 0;k<4;k++){
                    int nx = i+fx[k];
                    int ny = j+fy[k];
                    E.push_back({f(i,j),f(nx,ny)+N,1,0});
                }
                E.push_back({(2*N),f(i,j),5,1});
            }
        }
    }
    cout<<cont<<endl;
    cout<<min_cost_flow((2*N)+2,E,cont,2*N,(2*N)+1)<<endl;
    
}   