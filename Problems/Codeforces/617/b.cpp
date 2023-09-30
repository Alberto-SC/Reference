#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans = n;
        while(n/10>0){
            ans += n/10;
            int aux = n/10;
            n-=10*(n/10);
            n+=aux;
        }
        cout<<ans<<endl;
    }
    return 0;
}