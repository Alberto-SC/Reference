#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  int T = 1,n,m,r;
  cin>>T;
  while(T--){
    cin>>n>>m>>r;

    vector<vector<vector<bool>>> valid(n+1,vector<vector<bool>>(m+1,vector<bool>(r+1,true)));
    vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(m+1,vector<bool>(r+1,false)));
    int aux = r;
    while(aux--){
      int type,t,x;
      cin>>t>>type>>x;

      if(type==1){
        for(int i = 0;i<=m;i++){
          int invalid = t-x-i;
          if(invalid>=0 && invalid<=r)valid[x][i][invalid] = false;
        }
      } 
      else{
        for(int i = 0;i<=n;i++){
          int invalid = t-x-i;
          if(invalid>=0 && invalid<=r)valid[i][x][invalid] = false;
        }
      }     
    }

    dp[0][0][0] = true;

    for(int i = 0;i<=n;i++){
      for(int j = 0;j<=m;j++){
        for(int k = 0;k<=r;k++){
          if(valid[i][j][k]){
            if(i && dp[i-1][j][k])dp[i][j][k] = true;
            if(j && dp[i][j-1][k])dp[i][j][k] = true;
            if(k && dp[i][j][k-1])dp[i][j][k] = true;
          }
        }
      }
    }
    int ans = -1;
    for(int i = r;i>=0;i--){
      if(dp[n][m][i])ans = n+m+i;
    }
    cout<<ans<<endl;
  }
  return 0;
}