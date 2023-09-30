#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define mod 1000000007
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    lli t,n;
    cin>>t;
    vector<lli> ans(2000007);
    ans[0] = ans[1] = ans[2] = 0;
    ans[3] = ans[4] = 4;
    lli x = 1;
    for(lli i = 5;i<2000007;i++){
        ans[i] = ((((1*x)*ans[i-1])%mod) + (((2*x)*ans[i-2])%mod) ) %mod;
        x++;
    }
    while(t--){
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}