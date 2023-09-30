#include <bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int x = (n*(n+1)*((2*n)+1))/6;
        int y = (n*(n+1))/2;
        y*=y;
        int ans = y-x;
        cout<<ans<<endl;
    }
    return 0;
}
