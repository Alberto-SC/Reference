#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){
    int n,m,b,mod;
    cin>>n>>m>>b>>mod;
    vector<int> v(n);
    for(auto &c:v)cin>>c;

    vector<vector<int>> DP(m+1,vector<int>(b+1,0));
    DP[0][0] = 1;

    for(int i = 0;i<n;i++){
        vector<vector<int>> NDP(m+2,vector<int> (b+1,0));
        for(int j = 0;j<=m;j++){
            for(int k = 0;k<=b;k++){
                (NDP[j][k] += DP[j][k])%=mod;
                if(j<m && k+v[i]<=b) (DP[j+1][k+v[i]]+=DP[j][k])%=mod;
            } 
        }
     
        DP = NDP;
    }
    int ans = 0;
    for(int i = 0;i<=b;i++)(ans+=DP[m][i])%=mod;
    cout<<ans<<endl;
    return 0;
}
