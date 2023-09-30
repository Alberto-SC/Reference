#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
vector<int> graph[maxn];
vector<bool> used (maxn,false);
vector<int> degree(maxn,0);
vector<int> dist(maxn,0);
vector<int> nodes(maxn,1);
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
    degree[u]++;
    degree[v]++;
}
int  dfs(int u, int p = 1,int d = 0){
    dist[u] = d;
    for(auto c:graph[u]){
        if(c==p)continue; 
        nodes[u]+=dfs(c,u,d+1);
    }
    return nodes[u];
}   
int  main(){
    int n,u,v,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        add_edge(u,v);
    }
    int  ans = 0;
    dfs(1);
    vector<pair<int,int>> happines(n);
    for(int i = 1;i<=n;i++)
        happines[i-1] = {nodes[i],dist[i]};
    sort(happines.begin(),happines.end(),
    [](const pair<int,int> & a, const pair<int,int> & b)
    { 
        return a.second-(a.first-1) > b.second-(b.first-1); 
    });
    int i = 0;
    while(k){
        ans-=happines[i].first-1;
        ans+=happines[i].second;
        k--;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}