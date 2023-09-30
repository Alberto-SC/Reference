#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";


int main(){
    long long n,a,ans;
    cin>>n>>a;
    if(__gcd(n,a) == 1)ans = a*(n-1);
    else{
    long long lcma = (n*a)/__gcd(n,a);
    lcma = (n*a)/__gcd(n,a);
    ans = (a)*( ((lcma/(a)) - 1) * (n/(lcma/(a)))) + (a-1)*((n/(lcma/(a)))-1);
    }
    cout<<ans;
    return 0;
}