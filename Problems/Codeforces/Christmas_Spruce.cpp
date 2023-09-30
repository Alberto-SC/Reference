#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
vector<int> graph[maxn];
void add_edge(int u,int v){
    graph[v].push_back(u);
}
int mn = 100000;
bool dfs(int u){
    int cont = 0;
    for(auto v:graph[u]){
        if(graph[v].size()==0)cont++;
        else 
            dfs(v);
    }    
    mn = min(cont,mn);
    if(cont>=3)return true;
    return false;
}
int main(){
    int n,p;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        cin>>p;
        add_edge(i+2,p);
    }
    dfs(1);
    cout<<"No\0Yes\0" +3*(mn>=3)<<endl;
    return 0;
}