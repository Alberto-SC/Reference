#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = n/2;
        if(n ==1)cout<<0<<endl;
        else if(n&1)cout<<ans<<endl;
        else cout<<ans-1<<endl;
    }
}