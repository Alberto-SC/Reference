#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    lli ans = 0;
    for(int i =2;i<=n/2;i++){
        lli x = n/i;
        x = (x*(x+1))/2;
        x--;
        ans+= x*4;
    }
    cout<<ans<<endl;
    return 0;
}