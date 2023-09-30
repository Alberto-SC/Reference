#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> graph[maxn];
vector<int> degree(maxn);
int cont;
vector<int> d(maxn);
void add_edge(int u ,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
    degree[u]++;
    degree[v]++;
}
void dfs(int u,int p,int dist = 1){
    bool flag = false;
    for(auto c:graph[u]){
        if(degree[c] == 1)flag = true;
        if(c==p)continue;
        d[c] =dist;
        dfs(c,u,dist+1);
    }
    flag?cont++:cont+=0;
}
int main(){
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>u>>v;
        u--;
        v--;
        add_edge(u,v);
    }
    bool flag = true,par = true;
    int leaves= 0;
    for(int i = 0;i<n;i++)
        if(degree[i]== 1){
            leaves++;
            if(flag)dfs(i,i),flag = false;
        }
    for(int i = 0;i<n;i++)
        if(degree[i]== 1 && d[i]&1)par = false;
    par?cout<<1<<" ":cout<<3<<" ";
    cout<<((n-1)-leaves)+cont<<endl;
    return 0;
}