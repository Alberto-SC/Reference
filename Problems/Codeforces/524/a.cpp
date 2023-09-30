#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int ans = 0;
    ans+=ceil(n*2/(k*1.0));
    ans+=ceil(n*5/(k*1.0));
    ans+=ceil(n*8/(k*1.0));
    cout<<ans<<endl;
    return 0;
}