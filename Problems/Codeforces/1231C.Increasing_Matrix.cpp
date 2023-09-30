#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n,m;
    cin>>n>>m;
    int grid[n][m];
    lli sum = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j],sum+=grid[i][j];
    for(int i = n-2;i>=1;i--){
        for(int j = m-2;j>=1;j--){
            if(grid[i][j]!= 0)continue;
            grid[i][j] = min(grid[i][j+1],grid[i+1][j])-1;
            if(grid[i][j]<=grid[i-1][j]|| grid[i][j]<=grid[i][j-1])return cout<<-1<<endl,0;
            sum+=grid[i][j];
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 1;j<m;j++){
            if(grid[i][j]<= grid[i][j-1])return cout<<-1<<endl,0;
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 1;j<n;j++){
            if(grid[j][i] <=grid[j-1][i])return cout<<-1<<endl,0;
        }
    }
    // cout<<endl;
    // for(int i = 0;i<n;i++)
    //     for(int j = 0;j<m;j++)
    //         cout<<grid[i][j]<<" \n"[j ==m-1];

    cout<<sum<<endl;
    return 0;
}