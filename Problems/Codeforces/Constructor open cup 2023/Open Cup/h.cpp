#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        string s;
        cin>>s;
        n = s.size();
        
        vector<vector<vector<int>>> dp(8,vector<vector<int>>(8,vector<int>(8,0))); 

        for(int i = n-1;i>=0;i--){
            auto ndp = dp;
            for(int j = 1;j<=7;j++){
                for(int k = 1;k<=7;k++){
                    for(int l = 1;l<=7;l++){
                        int ans = 0;
                        if((j>2 || k>2) && (j>6 || k>6 || l>6)){
                            int nwLast1 = 1;
                            int nwLast2 = min(7ll,j+1);
                            int nwLast3 = min(7ll,k+1);

                            ans = (s[i]-'a')+1+dp[nwLast1][nwLast2][nwLast3];
                        }
                        ndp[j][k][l] = max(dp[min(7ll,j+1)][min(7ll,k+1)][min(7ll,l+1)],ans);
                    }
                }
            }
            dp = ndp;
        }
        int ans = 0;
        cout<<dp[7][7][7]<<endl;
    }
    return 0;
}

