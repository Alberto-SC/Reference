#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

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

int main(){__
    int t = 1,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++)graph[i].clear();
        pair<int,int> edge;
        for(int i = 0;i<n-1;i++){
            cin>>u>>v;
            graph[--u].push_back(--v);
            graph[v].push_back(u);
            edge = {u,v};
        }
        auto centroids = Centroid(n);
        if (centroids.size() == 1) {
            cout<<edge.first+1<<" "<<edge.second+1<<endl;
            cout<<edge.first+1<<" "<<edge.second+1<<endl;
        } 
        else if (centroids.size() == 2){
            u = centroids[0];
            v = centroids[1];
            for(auto d:graph[u]){
                if(d!=v){
                    cout<<d+1<<" "<<u+1<<endl;
                    cout<<v+1<<" "<<d+1<<endl;
                    break;
                }
            }

        } 
    }
 

    return 0;
}

