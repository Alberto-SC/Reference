#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int mod = 1e9+7;
const int maxn = 200017;

int DP[10][maxn];
int solve(int x,int m){
    if(m ==0)return 1;
    int &ans = DP[x][m];
    if(ans!=-1)return ans;
    ans = 0;
    if(x+1 == 10){
        (ans+=solve(1,m-1))%=mod;
        (ans+=solve(0,m-1))%=mod;
    }
    else 
        (ans+=solve(x+1,m-1))%=mod;
    return ans;
}

signed main(){__
	int t= 1,n,m;
    vector<int> pre(maxn);
    cin>>t;
    for(int i = 0;i<=9;i++){
        for(int j = 0;j<=maxn;j++){
            DP[i][j] =-1;
        }
    }
    while(t--){
        cin>>n>>m;
        int aux = n;
        int ans = 0;    
        while(aux){
            int x = aux%10;
            aux/=10;
            (ans += solve(x,m))%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
