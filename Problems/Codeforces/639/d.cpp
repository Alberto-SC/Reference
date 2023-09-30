#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

int grid[maxn][maxn];
bool vis[maxn][maxn];
int n,m;
void bfs(int x,int y){
    vis[x][y] = true;
    int nx,ny;
    for(int i = 0;i<4;i++){
        nx = x+fx[i];
        ny = y+fy[i];
        if(nx>=0 && nx<n && ny>= 0 && ny<m && grid[nx][ny] == 1 && !vis[nx][ny])
            bfs(nx,ny);
    }
}
int main(){
    cin>>n>>m;
    char c;
    int black =0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>c;
            if(c == '#')grid[i][j] = 1,black++;
        }
    }
    if(black == 0)return cout<<0<<endl,0;
    int cont = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 1 && !vis[i][j])bfs(i,j),cont++;

        }
    }
    

    vector<bool> rows(n,false);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 1){rows[i] = true;break;}
        }
    }
    vector<bool> cols(m,false);
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(grid[j][i] == 1){cols[i] = true;break;}
        }
    }

    // for(int i = 0;i<n;i++)if(rows[i] == false)return cout<<-1<<endl,0;
    // for(int i = 0;i<m;i++)if(cols[i] == false)return cout<<-1<<endl,0;

    for(int i = 0;i<n;i++){
        int f = -1,l = -1;
        for(int j = 0;j<m;j++)
            if(grid[i][j] == 1){f = j;break;}
        for(int j = m-1;j>=0;j--)
            if(grid[i][j] == 1){l = j;break;}
        if(f == l)continue;
        for(int j = f;j<=l;j++)
            if(grid[i][j] == 0)return cout<<-1<<endl,0;
        
    }

    for(int i = 0;i<m;i++){
        int f = -1,l = -1;
        for(int j = 0;j<n;j++)
            if(grid[j][i] == 1){f = j;break;}
        for(int j = n-1;j>=0;j--)
            if(grid[j][i] == 1){l = j;break;}
        if(f == l)continue;
        for(int j = f;j<=l;j++)
            if(grid[j][i] == 0)return cout<<-1<<endl,0;
        
    }


    cout<<cont<<endl;

    return 0;
}