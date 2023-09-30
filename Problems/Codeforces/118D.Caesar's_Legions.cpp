#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
typedef long long int lli;
const int mod = 100000000;

lli dp[maxn][maxn][11][11];
int n,m,k,k2;
lli _dp(int dn,int dm,int conth,int conts){
    if(conth>k|| dn<0)return 0;
    if(conts>k2 || dm<0)return 0;
    if(dn == 0 && dm == 0 )return 1;
    if(dp[dn][dm][conth][conts]!= -1)return dp[dn][dm][conth][conts];
    lli &d = dp[dn][dm][conth][conts];
    d = 0;
    d += _dp(dn-1,dm,conth+1,0);
    d%=mod;
    d += _dp(dn,dm-1,0,conts+1);
    d%=mod;
    return d;    
}


int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k>>k2;
    _dp(n,m,0,0); 
    cout<<dp[n][m][0][0]<<endl;
    return 0; 
}