#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

const int N = 100;
vector<vector<vector<int>>> dp;

int n;
vector<int> C;
vector<int> H;
vector<int> v;
int solve(int idx,int l1,int l2){
    if(idx == n)return 0;
    
    int &x = dp[idx][l1][l2];
    if(x!=-1)return x;

    int ans = 1e18;
    
    ans = min(ans,solve(idx+1,v[idx],l2)+(v[idx]==l1?H[v[idx]]:C[v[idx]]));
    ans = min(ans,solve(idx+1,l1,v[idx])+(v[idx]==l2?H[v[idx]]:C[v[idx]]));

    return x = ans;
}

signed main(){__
    int T,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        dp.assign(n+1,vector<vector<int>> (k+7,vector<int>(k+7,-1)));
        v.resize(n);
        H.resize(k+1);
        C.resize(k+1);
        for(int i = 0;i<n;i++)cin>>v[i];
        for(int i = 1;i<=k;i++)cin>>C[i];
        for(int i = 1;i<=k;i++)cin>>H[i];

        cout<<solve(0,0,0)<<endl;
    }
    return 0;
}

