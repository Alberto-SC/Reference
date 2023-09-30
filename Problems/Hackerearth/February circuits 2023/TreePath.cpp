#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

const int maxn = 100007;
const int inf = 1e9;

vector<int> vis(maxn);
vector<int> graph[maxn];
vector<int> val(maxn);
vector<int> dist(maxn);

pair<int,int> bfs(int s,int n,vector<vector<int>> &g){
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    int nu = s,mx = 0;
    vector<int> clean;
    while(q.size()){
        int u = q.front();
        vis[u] = true;
        q.pop();
        clean.push_back(u);

        for(auto v:g[u]){
            if(dist[v]> dist[u]+1){
                dist[v] = dist[u]+1;
                q.push(v);
                if(dist[v]>mx){
                    mx = dist[v];
                    nu = v;
                }
            }
        }
    }
    for(auto c:clean)dist[c] = inf;
    return {nu,mx};
}

int check(int n,int mx,int k){
    vector<vector<int>> g;
    g.resize(n);

    for(int i = 0;i<n;i++){
        if(val[i]>mx)continue;
        for(auto c:graph[i]){
            if(val[c]<=mx)g[i].push_back(c);
        }
    }

    vis.assign(n,false);
    dist.assign(n,inf);
    for(int i = 0;i<n;i++){
        if(!vis[i] && val[i]<=mx){
            pair<int,int> x = bfs(i,n,g);
            pair<int,int> y = bfs(x.first,n,g);
            if(y.second>=k)return true;
        }
    }

    return false;
}

signed main(){__
    int T,n,k;
    cin>>n>>k;
    for(int i = 0;i<n;i++)
        cin>>val[i];
    
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }

    int l = 0,r = 100001;

    while(l+1<r){
        int m = (l+r)>>1;
        if(check(n, m, k))r = m;
        else l = m;
    }
    if(r ==100001)cout<<-1<<endl;
    else cout<<r<<endl;

    return 0;
}
