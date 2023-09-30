/**
 * Author: Chen Xing
 * Date: 2009-10-13
 * License: CC0
 * Source: N/A
 * Description: Flow algorithm with guaranteed complexity $O(VE^2)$. To get edge flow values, compare
 * capacities before and after, and take the positive values only.
 * Status: stress-tested
 * Usage: 
 *     graph.clear();graph.resize(n);capacity.resize(n,vector<int> (n,0));
 *     capacity[u][v] = x;
 *     graph[u].push_back(v);
 */
vector<vector<int>> capacity;
vector<vector<int>> graph;

const int INF = 1e9;
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t,int n) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

struct edge{
    int u,v,c;
};

void get_min_cut(int S,int n){
    vector<bool> cut(n); 
    int idx = 0;
    cut[S] = 1;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:graph[u]){
            if(capacity[u][v]) 
                q.push(v),cut[v] = 1;
        }
    }
    for(auto c:cut)cout<<c<<" ";
    cout<<endl;
    vector<edge> edges;
    for(int i = 0;i<n;i++){
        if(cut[i]){
            for(auto v:graph[i]){
                if(!cut[v])
                    edges.push_back({i,v,capacity[v][i]});
            }
        }
    }
    for(auto c:edges)
        cout<<c.u<<" "<<c.v<<" "<<c.c<<endl;

}