#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int f;

int dp[107][5007];
int n,D,B,inf = 1e15;
vector<int> p(107);
bool check(int x){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=D;j++){
            dp[i][j] = inf;
        }
    }
    for(int i = 0;i<=x;i++){
        dp[0][i] = abs(p[0]-i);
    }
    for(int i = 1;i<n;i++){
        for(int j = 0;j<=D;j++){
            dp[i][j] = abs(j-p[i]);
            int z = inf;
            for(int k = 0;k<=x;k++){
                if(j-k<0)break;
                z  = min(z,dp[i-1][j-k]);
            }
            dp[i][j]+=z;
        }
    }
    int ans = inf;
    for(int i = max(0ll,D-x);i<=D;i++){
        ans = min(ans,dp[n-1][i]);
    }
    if(ans<=B)
        return true;
    else return false;
}

signed main(){
    cin>>D>>B>>n;
    for(int i = 0;i<n;i++)
        cin>>p[i];
    
    int l = 0,r = 5001;
    while(l+1<r){
        int m= (l+r)>>1;
        if(check(m))r = m;
        else l = m;
    }
    cout<<r<<endl;
    return 0;
}