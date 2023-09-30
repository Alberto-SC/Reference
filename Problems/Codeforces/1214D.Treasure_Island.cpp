#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
vector<vector<char>> grid;
vector<vector<int>> vis;
vector<vector<int>> vis2;

int n,m;
void bfs(int x,int y){
    vis[x][y]++;
    if(x+1<n && grid[x+1][y]!= '#' && !vis[x+1][y])bfs(x+1,y);
    if(y+1<m && grid[x][y+1]!= '#' && !vis[x][y+1])bfs(x,y+1);
}

void bfs2(int x,int y){
    vis2[x][y]++;
    if(x-1>=0 && grid[x-1][y]!= '#' && !vis2[x-1][y])bfs2(x-1,y);
    if(y-1>=0 && grid[x][y-1]!= '#' && !vis2[x][y-1])bfs2(x,y-1);
}

int main(){__
    cin>>n>>m;
    vis.resize(n,vector<int>(m));
    vis2.resize(n,vector<int>(m));
    grid.resize(n,vector<char>(m));
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];
        
    bfs(0,0);
    if(!vis[n-1][m-1])return cout<<0<<endl,0;
    if(n ==1 || m == 1)return cout<<1<<endl,0;
    bfs2(n-1,m-1);
    vector<int> cells[n+m+1];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            // cout<<vis[i][j]+vis2[i][j]<<" \n"[j == m-1];
            if(vis[i][j] && vis2[i][j])cells[i+j].push_back(1);
        }
    }
    for(int i  =1;i<n+m-2;i++){
        // cout<<cells[i].size()<<" ";
        if(cells[i].size()==1)return cout<<1<<endl,0;
    }
    cout<<2<<endl;

    return 0;
}