#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ans = n/2;
        ans*=m;
        if(n&1)ans+=ceil(m/2.0);
        cout<<ans<<endl;
    }
    return 0;
}