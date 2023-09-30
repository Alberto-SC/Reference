#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string s;

int dp[100007][2][21];
const int mod = 1e9+7;
int solve(int idx,int f,int k){
    if(k<0)return 0;
    if(idx ==s.size()){
        if(k==0)return 1;
        return 0;
    }

    int &x = dp[idx][f][k];
    if(x!=-1)return x;
    int lim = f?25:(s[idx]-'a');
    int ans = 0;
    for(int i = 0;i<=lim;i++){
        if(i ==lim)
            (ans+= solve(idx+1,f,k-(char(i+'a') != s[idx])))%=mod;
        else
            (ans+= solve(idx+1,1,k-(char(i+'a') != s[idx])))%=mod;
        
    }
    return x =ans;
}

signed main(){__
	int t= 1,n,k;
    cin>>t;
    vector<int> DP(2);
    while(t--){
        cin>>n>>k;
        cin>>s;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<=k;j++)
                dp[i][0][j] = -1,dp[i][1][j] = -1;
        cout<<solve(0,0,k)<<endl;
    }
    return 0;
}  
