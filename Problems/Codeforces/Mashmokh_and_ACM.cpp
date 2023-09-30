#include <bits/stdc++.h>
using namespace std;
const int MAXN =2000;
const int mod = 1000000007;
typedef long long int lli;
int dp[MAXN][MAXN];
int n,k;


lli solve(int currn,int ind){
    if(ind  ==1)return 1;
    if(dp[currn][ind]!=-1)return dp[currn][ind];
    lli ans = 0;
    for(int i =1;i<=n;i+=currn)
        ans = (ans+solve(i,ind-1))%mod;
    dp[currn][ind] = ans;
    return dp[currn][ind];
}

int main(){
    memset(dp, -1, sizeof dp);
    cin>>n>>k;
    lli ans = 0;
    for(int i = 1;i<=n;i++){
        ans +=solve(i,k);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}