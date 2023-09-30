#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

double M[19][19];
int n;

double dp[1<<19][19];
double solve(int mask ,int last){
    if(__builtin_popcount(mask)== n-1){
        if(mask&1)return 0;
        else return 1;
    }
    double &x = dp[mask][last];
    if(x!=-1)return x;
    double ans = 0;
    for(int i = 0;i<n;i++){
        if(!((mask>>i)&1) && i!= last){
            double y =  solve(mask|(1<<i),last)*M[last][i];
            double z =  solve(mask|(1<<last),i)*M[i][last];
            ans= max(y+z,ans);
        }
    }
    return x = ans;
}

signed main(){__
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>M[i][j];
        }
    } 
    for(int i = 0;i<(1<<n);i++){
        for(int j = 0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    double ans = 0;
    for(int i = 0;i<n;i++)
        ans= max(ans,solve(0,i));   
    cout<<ans<<endl;
    return 0;
}  
