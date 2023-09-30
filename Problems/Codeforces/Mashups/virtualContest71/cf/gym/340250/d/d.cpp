#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int dp[1<<18][19];
int C[19][19];

vector<int> A(18);
int n,m;
int solve(int mask,int last){
    if(__builtin_popcount(mask)==m)return 0;
    int &x = dp[mask][last];
    if(x !=-1)return x;
    int res = 0;
    for(int i = 0;i<n;i++){
        if((mask>>i)&1)continue; 
        int y = C[last][i];
        // cout<<y<<" "<<A[i]<<" "<<(mask|(1<<i))<<endl;
        res = max(res,solve(mask|(1<<i),i)+A[i]+y);
    }   
    // cout<<res<<endl;
    return x = res;
}

signed main(){__
	int t= 1,u,v,c,k;
    while(t--){
        cin>>n>>m>>k;
        memset(dp,-1,sizeof(dp));
        for(int i = 0;i<n;i++)
            cin>>A[i];
        for(int i = 0;i<k;i++){
            cin>>u>>v>>c;
            u--,v--;
            C[u][v] = c;
        }
        cout<<solve(0,18)<<endl;
    }
    return 0;
}  
