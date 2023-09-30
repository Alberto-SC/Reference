#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct Edge{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;
vector<pair<int,int>>graph[100]; 
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
int N;
 

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    N+=7;
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        graph[e.from].push_back({e.to,e.cost});
        // graph[e.to].push_back({e.from,-e.cost});
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }
    show_graph();
    // cout<<"HI"<<endl;
    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        // cout<<"Shortest Path "<<d[t]<<endl;
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
    // cout<<flow<<endl;
    if (flow < K)
        return -1;
    else
        return cost;
}

int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> u(n+1);
        for(int i = 0;i<n;i++){
            u[nums[i]]++;
        }
        vector<Edge> edges;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=2*n;j++){
                edges.push_back({i+1,j+n,1,abs(nums[i]-j)});
            }
        }
        // cout<<endl;
        for(int i = 1;i<=n;i++)
            edges.push_back({0,i,1,0});
        
        for(int i = 1;i<=2*n;i++)
            edges.push_back({i+n,3*n+2,1,0});
        N = 3*n+2;
        cout<<min_cost_flow(3*n+3,edges,n,0,3*n+2)<<endl;
    }
    return 0;
}
