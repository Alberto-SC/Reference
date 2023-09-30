
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int dp[5007][5007];
int main(){
	int t= 1,n,m;
    while(t--){
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        int ans = 0;
        for(int i = n-1;i>=0;i--) {
            for(int j = m-1;j>=0;j--) {
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]) - 1;
                dp[i][j] = max(0, dp[i][j]);
                if(s[i] == t[j]) 
                    dp[i][j] = 2 + dp[i+1][j+1];
                ans = max(ans, dp[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  

 