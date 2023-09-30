#include <bits/stdc++.h>
using namespace std;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  
vector<vector<int>> grid;
vector<int> vis(10000,0);

int dfs(int time,int s){
	vis[s] = 1;

	for( auto u : grafo[s] )
		if(vis[u] == -1)
			DFS(u);
}
int main(){
    int n,m,c,r;
    cin>>n>>m>>c>>r;
    grid.resize(c,vector(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int mn = 10000000000;
    for(int i = 0;i<8;i++)
        mn = min(dfs(c+fx[i],r+fy[i]),mn,grid[c+fx[i]][r+fy[i]]);
    cout<<mn<<endl;
    return 0;
}