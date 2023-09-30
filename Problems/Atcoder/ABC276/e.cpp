#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n;
vector<vector<int>> adj;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

pair<int,int> S;
int tm = 0;
vector<vector<bool>> vis;
vector<int> fx = {0,0,-1,+1};
vector<int> fy = {-1,+1,0,0};
int n,m;
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>= n || y>=m)return false;
    return true;
}
void bfs(int x,int y){
    
    for(int i = 0;i<4;i++){ 
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny)  && !vis[nx][ny] && M[nx][ny]=='.')bfs(nx,ny);
    }

}

signed main(){__
    int T = 1,n,m;
    while(T--){
        cin>>n,m;
        char M[n][m];
        vis.resize(n,vector<bool >(m));
        for(int i = 0;i<n;i++){
            for(int j= 0 ;j<m;j++){
                cin>>M[i][j];
                if(M[i][j])S = {i,j};
            }
        }

        bfs()

        
        
    }
    return 0;
}