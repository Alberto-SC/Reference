#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int m,n;
char grid[1040][1040];
bool vis[1040][1040];

vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,+1,-1};

bool valid(int x,int y){
    if(x<0 || y<0 )return false;
    if(x>= n || y>=m)return false;
    return true;
}

void bfs(int sr,int sc){
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = true;
    while(!q.empty()){
        auto z = q.front();
        q.pop();
        int x = z.first,y = z.second;
        for(int i = 0;i<4;i++){
            int nx = x+fx[i];
            int ny = y+fy[i];
            if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]== '.'){
                q.push({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
}

signed main(){__
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && grid[i][j]== '.'){
                bfs(i,j);
                ans++;
            
            }
        }
    }
    cout<<ans<<endl;
}   