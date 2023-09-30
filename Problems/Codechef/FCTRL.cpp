#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long ans = 0;
        for(int i = 5;n/i>=1;i*=5){
            ans+=n/i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}