#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        lli grid[n][m];
        for(lli i = 0;i<n;i++){
            for(lli j = 0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        lli ans = 0;
        for(lli i = 0;i<n/2;i++){
            for(lli j = 0;j<m/2;j++){
                lli a1 = 0,a2 = 0,a3 = 0,a4 = 0,to1,to2,to3,to4;     
                to1 = grid[i][j];
                to2 = grid[n-i-1][j];
                to3 = grid[n-i-1][m-j-1];        
                to4 = grid[i][m-j-1];        
                a1= abs(to1-grid[i][j]);
                a1+= abs(to1-grid[n-i-1][j]);
                a1+= abs(to1-grid[n-i-1][m-j-1]);
                a1+= abs(to1-grid[i][m-j-1]);
                a2= abs(to2-grid[i][j]);
                a2+= abs(to2-grid[n-i-1][j]);
                a2+= abs(to2-grid[n-i-1][m-j-1]);
                a2+= abs(to2-grid[i][m-j-1]);
                a3= abs(to3-grid[i][j]);
                a3+= abs(to3-grid[n-i-1][j]);
                a3+= abs(to3-grid[n-i-1][m-j-1]);
                a3+= abs(to3-grid[i][m-j-1]);
                a4= abs(to4-grid[i][j]);
                a4+= abs(to4-grid[n-i-1][j]);
                a4+= abs(to4-grid[n-i-1][m-j-1]);
                a4+= abs(to4-grid[i][m-j-1]);
                ans+= min({a1,a2,a3,a4});
            }
        }
        if(n&1){
            for(lli i = 0;i<m/2;i++){
                ans+=max(grid[n/2][(m-i)-1],grid[n/2][i])-grid[n/2][i];
                ans+=max(grid[n/2][(m-i)-1],grid[n/2][i])-grid[n/2][m-i-1];
            }
        }
        if(m&1){
            for(lli i = 0;i<n/2;i++){
                ans+=max(grid[i][m/2],grid[(n-i)-1][m/2])-grid[i][m/2];
                ans+=max(grid[i][m/2],grid[(n-i)-1][m/2])-grid[(n-i)-1][m/2];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

