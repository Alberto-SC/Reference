#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
int binomial_Coeff_without_MOD(int n,int k){
    int ans = 1;
    for(int i = 1;i<=min(n-k,k);i++){
            ans = (ans*(n-(i-1)))/i;
    }
    return ans;
}

signed main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        cout<<binomial_Coeff_without_MOD(n,k)<<endl;
        int ans = 1;
        for(int i = 1;i<=min(n-k,k-1);i++){
            ans= (ans * (n-i))/i;       
        }
        cout<<ans<<endl;
    }
    return 0;
}
