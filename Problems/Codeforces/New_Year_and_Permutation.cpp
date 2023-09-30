#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli n,mod;
    cin>>n>>mod;
    vector<lli> factmod(n+1);
    factmod[0] =1;
    for(lli i = 1;i<=n;i++)
        factmod[i] = (factmod[i-1]*i)%mod;
    lli ans = 0;
    for(lli i = 1;i<=n;i++){
        lli x =  ((n-i+1) * (factmod[i]*factmod[n-i+1]%mod));
        ans+=x;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}