#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int n,m;
char grid[100][100];
bool vis[100][100];
bool vis2[100][100];
void bfs(int y,int x){
    if(grid[y][x]== '#')return ;
    int nx = x;
    int ny = y;
    for(int i = 0;i<4;i++){
        nx= x+fx[i];
        ny= y+fy[i];
        // cout<<nx<<" "<<ny<<endl;
        if(nx<m && nx>=0 && ny<n && ny>= 0 && (grid[ny][nx] == '.'  || grid[ny][nx]== 'G')&& !vis[ny][nx]){
            vis[ny][nx] = true;
            bfs(ny,nx);
        }
    }
}
int main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>grid[i][j];
                vis[i][j] = false;
            }
        }
        bool flag = true;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){  
                if(grid[i][j] == 'B'){
                    if(i+1<n && grid[i+1][j]== '.')grid[i+1][j] = '#';
                    if(i-1>=0 && grid[i-1][j]=='.' )grid[i-1][j] = '#';
                    if(j+1<m && grid[i][j+1]=='.')grid[i][j+1] = '#';
                    if(j-1>=0 && grid[i][j-1]=='.') grid[i][j-1] = '#';
                    if(i+1<n && grid[i+1][j]== 'G')flag = false;
                    if(i-1>=0 && grid[i-1][j]== 'G')flag = false;
                    if(j+1<m && grid[i][j+1]== 'G')flag = false;
                    if(j-1>=0 && grid[i][j-1]== 'G')flag = false;
                }
            }
        }
        if(flag== false){cout<<"No"<<endl;continue;}
        bfs(n-1,m-1);
        for(int i = 0;i<n;i++){
            if(!flag)break;
            for(int j= 0;j<m;j++){  
                if(grid[i][j] == 'G'){
                    // cout<<vis[i][j]<<endl;
                    if(!vis[i][j])flag = false;
                }
            }
        }

        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}