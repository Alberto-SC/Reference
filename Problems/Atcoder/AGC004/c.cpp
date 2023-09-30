#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

const int maxn = 507;
char grid[maxn][maxn];
bool vis[maxn][maxn];

vector<int> fx = {+1,-1,+0,+0};
vector<int> fy = {+0,+0,-1,+1};

int n,m,mn,mx;

int getNum(int x,int y){
    return (x*m)+y;
}

bool valid(int x,int y){
    if(x<0 || y<0 )return false;
    if(x>= n || y>= m)return false;
    return true;
}

void dfs(int x,int y){
    mn = min(mn,getNum(x,y));
    mx = max(mx,getNum(x,y));
    vis[x][y] = true;
    for(int i = 0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny]== '#')
            dfs(nx,ny);
    }
}

signed main(){__
    int x,y;
    cin>>n>>m;
    char A[n][m];
    char B[n][m];
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j],A[i][j] ='.',B[i][j] = '.';
    for(int i = 0;i<m;i++)
        A[0][i] = '#',B[n-1][i] = '#';
    xz
    for(int i = 0;i<m;i++){
        if(i&1){
            for(int j = 0;j<n-1;j++)
                A[j][i] = '#';
        }
        else{
            for(int j = n-1;j>0;j--)
                B[j][i] = '#';
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == '#'){
                A[i][j] = '#';
                B[i][j] = '#';
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            cout<<A[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            cout<<B[i][j];
        cout<<endl;
    }

    return 0;
}