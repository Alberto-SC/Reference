#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1007][2007][4];
const int mod = 998244353;
int n; 
int solve(int idx,int k,int last){
    if(k<0)return 0;
    if(idx ==n){
        if(k)return 0;
        return 1;
    }

    int &x = dp[idx][k][last];
    if(x!=-1)return x;
    int res = 0;
    for(int i = 0;i<4;i++){
        if(last== 0){
            if(i==0)
                (res+=solve(idx+1,k,i))%=mod;
            else 
                (res+=solve(idx+1,k-1,i))%=mod;
        }
        else if(last ==1){
            if(i ==2)
                (res+=solve(idx+1,k-2,i))%=mod;
            else 
                (res+=solve(idx+1,k,i))%=mod;
        }
        else if(last ==2){
            if(i ==1)
                (res+=solve(idx+1,k-2,i))%=mod;
            else 
                (res+=solve(idx+1,k,i))%=mod;
        }
        else {
            if(i==3)
                (res+=solve(idx+1,k,i))%=mod;
            else
                (res+=solve(idx+1,k-1,i))%=mod;
        }
    }
    return x = res;
}

signed main(){__
    int k;
    cin>>n>>k;
    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<4;i++){
        if(i== 0|| i==3)
            (ans+=solve(1,k-1,i))%=mod;
        else if(k>=2)   
            (ans+=solve(1,k-2,i))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}  
