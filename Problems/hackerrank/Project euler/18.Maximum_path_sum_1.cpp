#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int M[20][20];
int n;
int dp[20][20];
int solve(int x,int y){
    if(x == n)return 0;
    if(dp[x][y]!= -1)return dp[x][y];
    int a1 = solve(x+1,y);
    int a2 = solve(x+1,y+1);
    dp[x][y] = M[x][y]+max(a1,a2);
    return dp[x][y];
}

signed main(){__
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<=i;j++){
                cin>>M[i][j];
                dp[i][j] = -1;
            }
        }
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
