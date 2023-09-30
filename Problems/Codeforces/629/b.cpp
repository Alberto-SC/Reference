#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,n,k;
    cin>>t;
    vector<lli> g;
    for(lli i = 1;i<200007;i++)
        g.push_back((i*(i-1))/2);
    while(t--){
        cin>>n>>k;
        string ans= string(n,'a');
        lli index = lower_bound(g.begin(),g.end(),k)-g.begin();
        ans[(n-index)-1] = 'b';
        int remaind = g[index]-k;
        if(g[index]>k)
            remaind = k-g[index-1];
        if(g[index] ==k)ans[(n-index)] = 'b';
        else ans[(n-1)-(remaind-1)] = 'b';
        cout<<ans<<endl;
    }
    return 0;
}
