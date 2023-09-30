#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
bool vis[maxn][maxn];
bool used[maxn][maxn];
char grid[maxn][maxn];
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  
int n,m;
bool valid(int x,int y){
    if(x>= 0 && x<m && y>= 0 && y<n)return true;
    return false;
}
int checksquare(int x,int y){
    if(grid[y][x] == '\\'){
        if(x-1 >= 0 && y+1<n && grid[y][x-1] == '/' && grid[y+1][x] == '/' && grid[y+1][x-1] == '\\')return 1;
        else return 0;
    }
    else if(grid[y][x] == '/'){
        if(x+1 <m && y+1<n && grid[y][x+1] == '\\' && grid[y+1][x] == '\\' && grid[y+1][x+1] == '/')return 1;
        else return 0;
    }
    return 0;
}

bool flag = false;
void dfs(int x,int y){
    int nx,ny;
    vis[y][x] = true;
    for(int i = 0;i<8;i++){
        nx = x+fx[i];
        ny = y+fy[i];
        if(!valid(nx,ny))flag = true;
        if(valid(nx,ny) && !vis[ny][nx] && grid[ny][nx] == '.'  ){
            if(i== 4 && grid[y][x-1] == '\\' && grid[y+1][x] == '\\')continue;
            else if(i == 5 && grid[y][x+1] == '/' && grid[y+1][x] == '/')continue;
            else if(i == 6 && grid[y-1][x] == '/' && grid[y][x-1] == '/')continue;
            else if(i == 7 && grid[y][x+1] == '\\' && grid[y-1][x] == '\\')continue;
            dfs(nx,ny);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>grid[i][j];
            vis[i][j] = false;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                flag = false;
                dfs(j,i);
                if(!flag)
                ans++;
            }
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == '\\' || grid[i][j] == '/'){
                ans+= checksquare(j,i);
                if(checksquare(j,i) == 1 && grid[i][j]== '/')j++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}