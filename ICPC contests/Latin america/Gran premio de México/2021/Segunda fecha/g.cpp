#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1007;
char M[maxn][maxn];
int n,m; 
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
bool valid(int x, int y) { 
    if(x<0 || y<0)return false;
    if(x>=n || y>=m)return false;
    return true;
}

int dp[maxn][maxn];
bool vis[maxn][maxn];
int dfs(int x,int y){
    if(vis[x][y])return dp[x][y];
    dp[x][y] = 1;
    vis[x][y] = true;
    int mx = 0;
    for(int i = 0;i<8;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && M[nx][ny] == M[x][y]+1)
            mx = max(mx,dfs(nx,ny));
    }
    dp[x][y]+=mx;
    return dp[x][y];
}

signed main(){__
    cin >> n >> m;
	vector<string> grid(n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>M[i][j];
        }
    }

	int mx = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j]){
				mx = max(mx, dfs(i,j));
			}
		}
	}

	cout << mx << endl;

	return 0;
}