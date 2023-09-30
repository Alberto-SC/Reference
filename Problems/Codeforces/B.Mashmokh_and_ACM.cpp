#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int mod = 1000000007;
const int maxn = 2007;
lli dp[maxn][maxn];
int n,k;
lli _get(int y,int l){
    // cout<<y<<" "<<l<<endl;
    if(y>n)return 0;
    if(l == k-1)return 1;
    else if(dp[y][l] != 0)return dp[y][l];
    lli &x = dp[y][l];
    for(int i = 1;i<=n/y;i++)
            x+=_get(y*i,l+1),x%=mod;
    return x;
}


int main(){
    cin>>n>>k;
    if(k == 1)return cout<<n<<endl,0;
    for(int i = 1;i<=n;i++){
        _get(i,0);
    }
    lli ans = 0;
    // cout<<endl;
    for(int i = 1 ;i<=n;i++){
        ans+=dp[i][0];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}