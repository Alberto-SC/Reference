#include <bits/stdc++.h>
using namespace std;

void add_edge(int u,int v){
   graph[u].push_back(v);
}


int main(){
    int n,u,v;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>u>>v;
        u--,v--;
        add_edge(u,v);
    }
    return 0;
}

