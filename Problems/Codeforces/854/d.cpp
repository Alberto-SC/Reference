#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';
#define int long long
using namespace std;


long long dp[5001][5001][2];

int n;
vector<int> C;
vector<int> H;
vector<int> v;
long long solve(int idx,int l1,int f){
    if(idx > n)return 0;
    
    long long &x = dp[idx][l1][f];
    if(x!=-1)return x;

    long long ans = 1e18;
    if(f){
        ans = min(ans,solve(idx+1,l1,1)+(v[idx-1]==v[idx]?H[v[idx]]:C[v[idx]]));
        ans = min(ans,solve(idx+1,idx-1,0)+(v[l1-1]==v[idx]?H[v[idx]]:C[v[idx]]));
    } 
    else{
        ans = min(ans,solve(idx+1,idx,1)+(v[l1]==v[idx]?H[v[idx]]:C[v[idx]]));
        ans = min(ans,solve(idx+1,l1,0)+(v[idx-1]==v[idx]?H[v[idx]]:C[v[idx]]));
    }

    return x = ans;
}

signed main(){__
    int T,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        } 
        v.resize(n+1);
        H.resize(k+1);
        C.resize(k+1);
        
        
        for(int i = 1;i<=n;i++)cin>>v[i];
        for(int i = 1;i<=k;i++)cin>>C[i];
        for(int i = 1;i<=k;i++)cin>>H[i];

        cout<<solve(1,0,0)<<endl;
    }
    return 0;
}

