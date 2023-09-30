#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
vector<vector<int>> grid;
vector<vector<int>> vis;


struct Point{
	int x,y,h;
	bool operator<(const Point& b) const{
		return (h<b.h);
	}
};


int n,m;
bool valid(int x,int y){
    if(x<0 || y<0)return false;
    if(x>= n ||y>=m)return false;
    return true;
}

void bfs(int x,int y){
    vis[x][y] = true;
    for(int i =0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && grid[nx][ny]>1 && grid[nx][ny]<=grid[x][y]&& !vis[nx][ny])
            bfs(nx,ny);
    }
}

signed main(){__
	int t= 1;
    while(t--){
        cin>>n>>m;
        grid.resize(n,vector<int> (m));
        vis.resize(n,vector<int> (m));
		priority_queue<Point> q;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
				if(grid[i][j]>1)
					q.push({i,j,grid[i][j]});
			}
		}
        int cont = 0;
		while(!q.empty()){
			auto t = q.top();
			if(!vis[t.x][t.y]){
				bfs(t.x,t.y);
				cont++;
			}
			q.pop();
		}
		cout<<cont<<endl;
    }
    return 0;
}  
