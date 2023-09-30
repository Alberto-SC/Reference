#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n';

using namespace std;

int dp[307];
vector<int> primes;
int N ;
int solve(int idx){
    if(idx == N)return 1;
    int &X = dp[idx];
    if(X!=-1)return X;

    int ans = 0;
    for(int j = idx+1;j<=N;j++){
        if(primes[j]-primes[idx]<=14)
            ans+=solve(j);
    }
    return X = ans;
}

signed main(){__
    int p;
    primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271};
    cin>>p;

    N = lower_bound(primes.begin(),primes.end(),p)-primes.begin();
    memset(dp,-1,sizeof(dp));
    cout<<solve(0)<<endl;
    return 0;
}
