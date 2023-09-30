#include <bits/stdc++.h>
using namespace std;
const int maxn = 100007;
vector<int> leaves(maxn);
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u,int p =-1){
    int cont = 0;
    for(auto v:graph[u]){
        if(v == p)continue; 
        cont++;
        dfs(v,u);
        leaves[u]+=leaves[v];
    }
    if(cont == 0)leaves[u] = 1;
}
int main(){
    int n,p;
    cin>>n;
    for(int i = 1;i<n;i++){
        cin>>p;
        p--;
        add_edge(i,p);
    }
    dfs(0);
    int pos = 0;
    vector<int> leafs(n);
    for(int i = 0;i<n;i++)
        leafs[leaves[i]]++;
    int i = 1;
    while(pos<n){
        while(pos<n && leafs[i]){
            cout<<i<<" ";
            pos++;
            leafs[i]--;
        }
        i++;
    }
    return 0;
}