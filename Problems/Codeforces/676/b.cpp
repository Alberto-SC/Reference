#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int fx[]={+0,+0,+1,-1};   
const int fy[]={-1,+1,+0,+0}; 
int n;
bool valid(int x,int y){
    if(x<=0 ||y<=0)return false;
    if(x>n || y>n)return false;
    return true;
}

vector<vector<bool>> vis(207,vector<bool>(207,false));
vector<vector<char>> grid(207,vector<char>(207,false));
void bfs(int x,int y,char who){
    int nx,ny;
    vis[x][y] = true;
    for(int i = 0;i<4;i++){
        nx = x+fx[i];
        ny = y+fy[i];
        if(valid(nx,ny) && !vis[nx][ny] && grid[nx][ny] == who ||grid[nx][ny]== 'F')
            bfs(nx,ny,who);
    }
}

int main(){__
    int t = 1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cin>>grid[i][j];
            }
        }

        int mask = 15;
        vector<vector<char>> aux(207,vector<char>(207,false));
        aux = grid;
        int i;
        for(i = 0;i<mask;i++){
            if(__builtin_popcount(i)<= 2){
                vis.assign(207,vector<bool> (207,false));
                grid = aux;
                if(i&1)
                    grid[n-1][n] = !((grid[n-1][n]-'0'))+'0';
                if((i>>1)&1)
                    grid[n][n-1] = !((grid[n][n-1]-'0'))+'0';
                if((i>>2)&1)
                    grid[1][2] = !((grid[1][2]-'0'))+'0';
                if((i>>3)&1)
                    grid[2][1] = !((grid[2][1]-'0'))+'0';
                bfs(1,1,'0');
                if(vis[n][n])continue;
                bfs(1,1,'1');
                if(!vis[n][n]){
                    break;
                }
            }
        }
        cout<<__builtin_popcount(i)<<endl;
        if(i&1)
            cout<<n-1<<" "<<n<<endl;
        if((i>>1)&1)
            cout<<n<<" "<<n-1<<endl;
        if((i>>2)&1)
            cout<<1<<" "<<2<<endl;
        if((i>>3)&1)
            cout<<2<<" "<<1<<endl;
    }
    return 0;
}

