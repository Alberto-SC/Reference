#include <bits/stdc++.h>
using namespace std;
const int maxn = 1007;
int dp1[maxn][maxn];
int dp2[maxn][maxn];
int dp3[maxn][maxn];
int dp4[maxn][maxn];
int grid[maxn][maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>grid[i][j];
        }
    }


    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dp1[i][j] = grid[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            dp2[i][j] = grid[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
    
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            dp3[i][j] = grid[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp4[i][j] = grid[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
    int ans = 0;
    for (int i = 2; i <= n-1; i++)
        for (int j = 2; j <= m-1; j++) {
            ans = max(ans, dp1[i-1][j] + dp4[i+1][j] + dp3[i][j-1] + dp2[i][j+1]);
            ans = max(ans, dp1[i][j-1] + dp4[i][j+1] + dp3[i+1][j] + dp2[i-1][j]);
        }

    cout<<ans<<endl;
    return 0;
}