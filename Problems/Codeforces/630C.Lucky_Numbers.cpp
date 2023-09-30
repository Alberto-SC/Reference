#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    lli ans = 1;
    ans<<=n+1;
    ans-=2;
    cout<<ans<<endl;
    return 0;
}