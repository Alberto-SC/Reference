#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    lli ans = 0;
    n--;
    for(lli i = 1;i<=n;i<<=1)
        ans+= (((n-i)/(i<<1))+1)*i;

    cout<<ans<<endl;
    return 0;
}