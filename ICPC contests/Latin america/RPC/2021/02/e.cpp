#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int INF = 100000000;

vector<vector<int>> grid;
bool check(int r, int c){
    if(r == 0 || c == 0 || r == grid.size()-1 || c == grid[r].size()-1)
        return false;
    if(grid[r][c] == -1 || grid[r-1][c] == -1 ||
        grid[r+1][c] == -1 || grid[r][c-1] == -1 ||
        grid[r][c+1] == -1)
        return false;
    if(grid[r-1][c] > grid[r][c] &&
        grid[r+1][c] > grid[r][c] &&
        grid[r][c-1] < grid[r][c] &&
        grid[r][c+1] < grid[r][c])
        return true;
    else
        return false;
            
}

vector<vector<vector<int>>> dp;
int solve(int r, int c, int p){
    if(p < 0)
        return INF;
    if(c == grid[0].size()-1){
        if(p == 0)return 0;
        else return INF;
    }
    if(dp[r][c][p] != -2)
        return dp[r][c][p];
    int mn = INF,cur;
    if(r > 0 && grid[r-1][c+1] != -1){
        if(check(r-1, c+1))
            cur = solve(r-1, c+1, p-1) + grid[r-1][c+1];
        else
            cur = solve(r-1, c+1, p) + grid[r-1][c+1];
        if(cur < mn)
        mn = cur;
    }
    if(grid[r][c+1] != -1){
        if(check(r,c+1))
            cur = solve(r, c+1, p-1) + grid[r][c+1];
        else
            cur = solve(r, c+1, p) + grid[r][c+1];
        if(cur < mn)
        mn = cur;
    }
    if(r < grid.size()-1 && grid[r+1][c+1] != -1){
        if(check(r+1, c+1))
            cur = solve(r+1, c+1, p-1) + grid[r+1][c+1];
        else
            cur = solve(r+1, c+1, p) + grid[r+1][c+1];
        if(cur < mn)
        mn = cur;
    }
    if(mn > INF)
        mn = INF;
    dp[r][c][p] = mn;
    return mn;
}
        
int main(){__
    int r,c,n;
    cin >> r >> c >> n;
    grid.resize(r);
    for(int i = 0; i<r; i++){
        grid[i].resize(c);
        for(int j = 0; j<c; j++)
            cin>>grid[i][j];
    }

    int mn = INF;
    dp.resize(r);
    for(int i = 0; i < r; i++){
        dp[i].resize(c);
        for(int j = 0; j < c; j++){
            dp[i][j].resize(n+1);
            for(int k = 0; k < n+1; k++)
                dp[i][j][k] = -2; 
        }
    }
    for(int i = 0; i < r; i++){
        if(grid[i][0] != -1){
            int cur = grid[i][0] + solve(i, 0, n);
            mn = min(cur,mn);
        }
    }
    if(mn<INF)
        cout<<mn<<endl;
    else
        cout<<"impossible"<<endl;
    return 0;
}
    
    
