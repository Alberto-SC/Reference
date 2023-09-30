#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string LCS(string X, string Y, int m, int n){
    int mx = 0;         
    int last = m;    
    int DP[m + 1][n + 1];
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (X[i - 1] == Y[j - 1]){
                DP[i][j] = DP[i - 1][j - 1] + 1;
                if (DP[i][j] > mx){
                    mx = DP[i][j];
                    last = i;
                }
            }
        }
    }
    return X.substr(last - mx, mx);
}
 
signed main(){__
    int t;
    cin>>t;
    while(t--){
        string X,Y;
        cin>>X>>Y;
        int m = X.length(), n = Y.length();
        int x =  LCS(X, Y, m, n).size();
        cout<<(X.size()-x)+(Y.size()-x)<<endl;
    }
    return 0;
}