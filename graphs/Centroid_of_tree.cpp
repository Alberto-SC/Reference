const int maxn = 100007;
vector<int> graph[maxn];

vector<int> Centroid(int n){
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : graph[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        graph[--u].push_back(--v);
        graph[v].push_back(u);
        edge = {u,v};
    }
    auto centroid = centroid(n);
}