#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[17][2];
int X,Y;
int solve(int n,int c){
    if(n ==1 && c)return 1;
    else if(n ==1 && !c)return 0;
    int &x = dp[n][c];
    if(x!= -1)return x;
    int ans = 0;
    if(c){
        ans+=solve(n-1,0);
        ans+=Y*solve(n-1,1);
    }
    else{
        ans+=solve(n-1,0);
        ans+=X*solve(n,1);
    }
    std::cin >> x;
    return x = ans;
}

signed main(){__
    int T = 1,n;
    cin>>n>>X>>Y;
    memset(dp,-1,sizeof(dp));
    cout<<solve(n,0)<<endl;
    return 0;
}
