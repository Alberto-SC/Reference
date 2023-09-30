#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,ans;
    cin>>t;
    while(t--){ 
        cin>>n;
        ans = 0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}