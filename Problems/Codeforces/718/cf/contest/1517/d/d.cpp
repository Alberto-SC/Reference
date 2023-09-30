#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int DP[507][507][20];
int rows[507][507];
int cols[507][507];
int n,m;
bool valid(int x,int y){
    if(x<0 || y<0)return 0;
    if(x>=n ||y>=m)return 0;
    return 1;
}
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
int solve(int x,int y,int k){
    if(k==0)return 0;
    int &ans = DP[x][y][k];
    if(ans!=-1)return ans;
    int res = 1e18;
    for(int i = 0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if(valid(nx,ny)){
            if(i ==0)
                res = min(res,solve(nx,ny,k-2)+(2*(cols[x][y])));
            if(i ==1)
                res = min(res,solve(nx,ny,k-2)+(2*(cols[x-1][y])));
            if(i ==2)
                res = min(res,solve(nx,ny,k-2)+(2*(rows[x][y])));
            if(i ==3)
                res = min(res,solve(nx,ny,k-2)+(2*(rows[x][y-1])));
        }
    }
    return ans= res;
}
signed main(){__
    int k;
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m-1;j++){
            cin>>rows[i][j];
        }
    }
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<m;j++){
            cin>>cols[i][j];
        }
    }
    for(int i = 0;i<=n;i++)
        for(int j = 0;j<=m;j++)
            for(int z = 0;z<=k;z++)
                DP[i][j][z] = -1;
    if(k&1){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        return 0;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<solve(i,j,k)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}  
