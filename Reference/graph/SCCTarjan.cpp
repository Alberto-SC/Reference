#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 100007;
vector<int> graph[maxn], graph_rev[maxn];
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (auto u : graph[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : graph_rev[v])
        if (!used[u])
            dfs2(u);
}

signed main(){__
    int n,m,u,v;
    cin>>n>>m;
    vector<int> in(n);
    vector<int> out(n);
    for(int i = 0;i<m;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph_rev[v].push_back(u);
    }
    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
        dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> graphC(n);
    for (auto v : order){
        if (!used[v]) {
            dfs2(v);
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }
    }
}
