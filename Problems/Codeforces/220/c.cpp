#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 1000007;
vector<int> graph[maxn];
char grid[1000][1000];
vector<int> dp(maxn,-1);
vector<int> fx = {1,0,-1, 0};
vector<int> fy = {0,1, 0,-1};
int n,m;
bool valid(int x,int y){
    if(x>=n || y>=m)return false;
    if(x<0 ||y <0)return false;
    return true;
}

int dfs(int u){
    dp[u] =-2;
    int mx = 0;
    for(auto v: graph[u]){
        if(dp[v] == -2)return dp[u]= maxn;
        if(dp[v] == -1)dfs(v);
        mx = max(mx,dp[v]); 
    }
    // cout<<u<<" "<<mx<<endl;
    return dp[u] = mx+1;
}


int main(){__
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];

    auto f = [&](int x,int y){
        return (x*m)+y;
    };
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            // cout<<f(i,j)<<" ";
            for(int k = 0;k<4;k++){
                int nx = i+fx[k];
                int ny = j+fy[k];
                if(valid(nx,ny)){
                    if(grid[i][j] == 'D' && grid[nx][ny]== 'I'){
                        graph[f(i,j)].push_back(f(nx,ny));
                    }
                    else if(grid[i][j] == 'I' && grid[nx][ny]== 'M'){
                        graph[f(i,j)].push_back(f(nx,ny));
                    }
                    else if(grid[i][j]== 'M'  && grid[nx][ny]== 'A'){
                        graph[f(i,j)].push_back(f(nx,ny));
                    }
                    else if(grid[i][j] == 'A'  && grid[nx][ny]== 'D'){
                        graph[f(i,j)].push_back(f(nx,ny));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]== 'D'){
                ans = max(ans,dfs(f(i,j)));
            }
        }
    }
    if(ans>n*m)cout<<"Poor Inna!"<<endl;
    else if(ans<4)cout<<"Poor Dima!"<<endl;
    else cout<<ans/4<<endl;
    return 0;
}  

