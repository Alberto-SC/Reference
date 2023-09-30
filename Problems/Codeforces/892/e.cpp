#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 3007;
vector<int> a(maxn),b(maxn);

int dp[3007][3007][2];

int solve(int idx,int k,int f){
    if(a.size()-idx<k){
        return -1e18;
    }
    if(k == 0)return 0;
    if(idx == a.size() ){
        if(f|| k)return -1e18;
        return 0;
    }

    int &x = dp[idx][k][f];
    if(x !=-1)return x;

    int ans = 0; 
    if(f){
        if(k==1)
            return a[idx]+b[idx];
        else{
            ans = max(ans,solve(idx+1,k-1,f));
            ans = max(ans,a[idx]+b[idx] + solve(idx+1,k-1,0));
        }
    }
    else{
        ans = max(ans,solve(idx+1,k,f));
        ans = max(ans,abs(b[idx]-a[idx])*2 + solve(idx+1,k-1,f));


        if(k>1){

            int x = solve(idx+1,k-1,1);
            if(x != -1e18){
                ans = max(ans,abs(a[idx]+b[idx] - x));
            }
        }
    }  
    if(ans<=-1e14) ans = -1e18;
    return x= ans;
}


signed main(){__
    int T = 1,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        a.resize(n);
        b.resize(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;

        memset(dp,-1,sizeof(dp));
        cout<<solve(0,k,0)<<endl;
    }
    return 0;
}