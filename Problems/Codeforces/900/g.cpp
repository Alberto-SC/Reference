#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

const int LOG = 20;
const int maxn = 200007;
vector<int> graph[maxn];
vector<vector<int>> parent(maxn, vector<int>());
vector<vector<int>> orBin(maxn, vector<int>());
vector<int> depth(maxn);
vector<int> a(maxn);

void dfs(int u, int p, int d) {
    parent[u][0] = p;
    orBin[u][0] = a[u];

    if (p != -1) {
        orBin[u][0] |= a[p];
    }

    depth[u] = d;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

pair<int, int> lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int diff = depth[u] - depth[v];
    int OR = a[u] | a[v];

    for (int x = LOG - 1; x >= 0; --x) {
        if ((diff >> x) & 1) {
            OR |= orBin[u][x];
            u = parent[u][x];
        }
    }

    if (u == v) {
        return {OR, u};
    }

    for (int x = LOG - 1; x >= 0; --x) {
        if (parent[u][x] != parent[v][x]) {
            OR |= orBin[u][x];
            OR |= orBin[v][x];
            u = parent[u][x];
            v = parent[v][x];
        }
    }

    OR |= orBin[u][0] | orBin[v][0];
    return {OR, parent[u][0]};
}

int dist(int u, int v, int LCA) {
    return depth[u] + depth[v] - 2 * depth[LCA];
}

int getParent(int u, int x) {
    for (int i = LOG - 1; i >= 0; --i) {
        if ((x >> i) & 1) {
            u = parent[u][i];
        }
    }
    return u;
}

int getNode(int u, int v, int LCA, int x) {
    if (dist(u, LCA, LCA) >= x) {
        return getParent(u, x);
    } else {
        return getParent(v, dist(v, LCA, LCA) - (x - dist(u, LCA, LCA)));
    }
}

void solve() {
    int n;
    cin >> n;    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        graph[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        parent[i] = vector<int>(LOG, -1);
        orBin[i] = vector<int>(LOG, 0);
    }

    dfs(0, -1, 0);

    for (int u = 1; u < LOG; ++u) {
        for (int i = 0; i < n; ++i) {
            if (parent[i][u - 1] == -1)continue;
            parent[i][u] = parent[parent[i][u - 1]][u - 1];
            orBin[i][u] = orBin[i][u - 1] | orBin[parent[i][u - 1]][u - 1];
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        pair<int, int> result = lca(u, v);
        int LCA = result.second;
        int LEN = dist(u, v, LCA);
        int ans = __builtin_popcount(result.first);

        for (int bits = 1; bits <= __builtin_popcount(result.first); ++bits) {
            int L = -1;
            int R = LEN;

            while (L + 1 < R) {
                int mid = (L + R) / 2;
                int NODE = getNode(u, v, LCA, mid);
                pair<int, int> result1 = lca(u, NODE);

                if (__builtin_popcount(result1.first) >= bits) {
                    R = mid;
                } else {
                    L = mid;
                }
            }

            int NODE = getNode(u, v, LCA, R);
            pair<int, int> res1 = lca(u, NODE);
            pair<int, int> res2 = lca(NODE,v);
            ans = max(ans, (int )__builtin_popcount(res1.first) + __builtin_popcount(res2.first));
        }

        cout << ans << " ";
    }
    cout<<endl;
}


signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}