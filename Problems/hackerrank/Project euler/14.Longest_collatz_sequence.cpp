#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
const int maxn = 3732423;
signed main(){
    vector<int> dp(maxn+1);
    dp[1] = 1; 
    for(int i = 1;i<=maxn;i++){
        int aux = i;
        int cont = 1;
        while(aux!=1){
            if(aux&1)
                aux= (aux*3)+1;
            else aux/=2;
            cont++;
        }
        dp[i] = cont;
    }
    vector<int> ans(maxn+1);
    int last = 1,mx = 0;
    for(int i = 1;i<=maxn;i++){
        if(dp[i]>=mx)last = i,mx = dp[i];
        ans[i] = last;
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>=maxn)
            cout<<maxn<<endl;
        else 
            cout<<ans[n]<<endl;
    
    }
}
