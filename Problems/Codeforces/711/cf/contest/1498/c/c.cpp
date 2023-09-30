#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 1e9+7;
void add(int &a, int b){a+=b;if(a>=mod)a-=mod;}

int DP[1007][1007];
int n;
int solve(int idx,int k,int dir){
    if(idx<0 || idx==n || k ==1)return 0;
    int &x = DP[idx][k];
    if(x!= -1)return x;
    x = 0;
    if(dir){
        int z =1;
        add(z,solve(idx-1,k-1,!dir));
        add(z,solve(idx+1,k,dir));
        add(x,z);
    }
    else{
        int z =1;
        add(z,solve(idx+1,k-1,!dir));
        add(z,solve(idx-1,k,dir));
        add(x,z);
    }
    return x;
}

signed main(){__
	int t= 1,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 0;i<=n;i++)
            for(int j =0;j<=k;j++)
                DP[i][j] = -1;
        int ans = 1;
        add(ans,solve(0,k,1));
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}  
