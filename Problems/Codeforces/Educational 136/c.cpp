#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int binomial_Coeff_without_MOD(int n,int k){
    int ans = 1;
    for(int i = 1;i<=min(n-k,k);i++){
        ans = (ans* (n-(i-1)))/i;
    }
    return ans;
}

const int mod = 998244353;
signed main(){__
    int T = 1,n;
    int dp[31];
    dp[1] = 1;
    dp[2] = 3; 
    // dp[3] = 12;
    // dp[4] = 42;
    for(int i = 3;i<31;i++){
        int x = binomial_Coeff_without_MOD(i*2,i);
        int y = binomial_Coeff_without_MOD((i-1)*2,i-1);
        int z = y-1-dp[i-1];
        dp[i] = binomial_Coeff_without_MOD((i*2)-1,i-1)+z;
    } 
    cin>>T;
    while(T--){
        cin>>n;
        n/=2;
        int a = dp[n]%mod;
        int b = binomial_Coeff_without_MOD(n*2,n)-1-dp[n];
        b%=mod;

        cout<<a<<" "<<b<<" "<<1<<endl;
    }

    return 0;
}