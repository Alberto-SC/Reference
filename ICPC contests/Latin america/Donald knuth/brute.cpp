#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1000000007;
int main(){
    lli n;
    cin>>n;
    lli ans = 0;
    map<lli,lli> mp;
    for(int i = 1;i<=n;i++){
        double x = sqrt(i);
        // mp[round(x)]++;
        // cout<<round(x)<<endl;
        ans+= round(x);
        ans%=mod;
    }
    for(auto c:mp)cout<<c.first<<" "<<c.second<<endl;
    // cout<<ans<<endl;
    return 0;
}