#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t,v;
    cin>>s>>t>>v;
    int n = s.size(),m = t.size(),k= v.size();
    int idx = 0;
    int dp[n+1][m+1];

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            if(i == 0 || j == 0)dp[i][j] = 0;
            else if(s[i-1]==t[j-1]){
                if(s[i-1] == v[idx])
                    idx++;
                else 
                    idx = 0;
                
                if(idx == k)
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]),idx--;
                
                else 
                    dp[i][j] =dp[i-1][j-1]+1;
            }
            else 
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        
        }
    }
    string ans;
    int i = n, j = m; 
    while (i > 0 && j > 0) { 
      if (s[i-1] == t[j-1]) {  
          ans.push_back(s[i-1]); 
          i--; j--; 
      } 
      else if (dp[i-1][j] > dp[i][j-1]) 
         i--; 
      else
         j--; 
    }
    reverse(ans.begin(),ans.end());
    // for(int i = 0;i<=n;i++)
        // for(int j = 0;j<=m;j++)
            // cout<<dp[i][j]<<" \n"[j ==m];
    if(dp[n][m]== 0)return cout<<0<<endl,0;
    cout<<ans<<endl;
    return 0;
}