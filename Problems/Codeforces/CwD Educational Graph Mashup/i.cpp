#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 200007;
vector<int> graph[maxn];
vector<int> degree(maxn);
vector<int> dep(maxn);
vector<int> ans;
vector<bool> vis(maxn);
void dfs(int u,int p = -1,int d = 0){
    dep[u] = d;
    for(auto v:graph[u]){
        if(v == p)continue;
        dfs(v,u,d+1);
    }
}

int main(){
    int n,p;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>p;
        if(p){
            graph[i].push_back(p-1);
            graph[p-1].push_back(i);
            degree[i]++;
            degree[p-1]++;
        }
    }
    if(n%2 ==0)return cout<<"NO"<<endl,0;
    dfs(0);
    priority_queue<pair<int,int>> pq;
    for(int i = 0;i<n;i++)
        pq.push({dep[i],i});
    cout<<"YES"<<endl;
    while(!pq.empty()){
        auto u = pq.top().second;
        pq.pop();
        if(vis[u])continue;
        if(degree[u]%2)continue;
        cout<<u+1<<endl;
        vis[u] = true;
        for(auto v:graph[u]){
            if(vis[v])continue;
            degree[v]--;
            pq.push({dep[v],v});
        }
    }
    return 0;
}