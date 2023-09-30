#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A ) cout<<c<<" ";
vector<int> grafo[1000];
vector<int> vis;
void addEdge(int u,int v){
    grafo[u].push_back(v);
}
int  DFS( int s ){
    vis[s]++;
    if(vis[s] == 1)return s;
    // cout<<s<<"\n";
	for( auto u : grafo[s] )
		if(vis[u] == -1)
            DFS(u);
    
}
int main(){
    int n,ai;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>ai;
        addEdge(i,--ai);
    }
    for(int i = 0;i<n;i++){
        vis.resize(n,-1);
        cout<<DFS(i)+1<<" ";
    }
    return 0;

}