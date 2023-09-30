#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1007][207][207][2];

int n,m;
string s,t;
const int mod = 1e9+7;

int solve(int idxi,int idxj,int k,int f){
    if(idxj == m){
        if (k-f == 0)return 1;
        return 0;
    }

    if(k<=0)return 0;
    if(idxi == n)return 0;

    int &x = dp[idxi][idxj][k][f];
    if(x!=-1)return x;
    
    int ans = 0;

    if(f){
        if(s[idxi]!=t[idxj]){
            ans += solve(idxi+1,idxj,k-1,0);
            ans%=mod;
        }
        else{
            ans += solve(idxi+1,idxj+1,k,1);
            ans += solve(idxi,idxj,k-1,0);
            ans%=mod;
        }
    }
    else{
        if(s[idxi]==t[idxj]){
            ans += solve(idxi+1,idxj+1,k,1);
            ans += solve(idxi+1,idxj,k,0);
            ans%=mod;
        }
        else{
            ans += solve(idxi+1,idxj,k,0);
            ans%=mod;
        }
    }
    return x = ans;
}

signed main(){__
    int k;
    cin>>n>>m>>k;
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,k,0)<<endl;
    return 0;
}