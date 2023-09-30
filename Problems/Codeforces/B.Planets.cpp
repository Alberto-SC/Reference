#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<pair<int,int>> graph[maxn];
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
int main(){__
    int n,m,u,v,c,k;
    cin>>n>>m; 
    for(int i = 0;i<m;i++){
        cin>>u>>v>>c;
        graph[--u].push_back({--v,c});
        graph[v].push_back({u,c});
    }
    vector<int> times[n];
    for(int i = 0;i<n;i++){
        cin>>k;
        int x;
        for(int j  = 0;j<k;j++)
            cin>>x,times[i].push_back(x);
    }
    int inf = 2e9;
    vector<int> dist(n,inf);
    int first = 0;
    if(times[0].size() && times[0][0] == 0){
        int j = 1;
        first = 1;
        while(j<times[0].size() && times[0][j] == times[0][j-1]+1){
            first++;
            j++;
        }
    }
    dist[0] = first;
    auto f = [&times](int node,int t){
        auto idx = lower_bound(times[node].begin(),times[node].end(),t);
        if(idx==times[node].end())return 0;
        if(*idx!=t)return 0;
        auto prev = idx;
        idx++;
        int x = 1;
        while(idx!= times[node].end()){
            if((*prev)+1 != *idx)return x;
            prev =idx;
            idx++; 
            x++;
        }
        return x;
    };
    set<pair<int,int>> s;
    s.insert({dist[0],0});
    while(!s.empty()){
        int u = s.begin()->second;
        s.erase(s.begin());
        int t = f(u,dist[u]);
        for(auto c:graph[u]){
            int w = c.second;
            int v = c.first;
            if(dist[u]+t+w<dist[v]){
                s.erase({dist[v],v});
                dist[v] = dist[u]+t+w;
                s.insert({dist[v],v});
            }
        }
    } 
    if(dist[n-1]== inf)return cout<<-1<<endl,0;
    cout<<dist[n-1]<<endl;
    return 0;
}