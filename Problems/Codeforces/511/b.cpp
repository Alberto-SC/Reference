#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,a,b;
    cin>>n;
    lli ans = -100000;
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        lli x = a+b;
        ans = max(x,ans);
    }
    cout<<ans<<endl;
    return 0;
}