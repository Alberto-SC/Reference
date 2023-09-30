#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int k,p,n,ans;
        cin>>k>>p>>n;
        p=p*n;
        k=k*n;
        ans=k-p;
        if(ans<0)
            ans=0;
        cout<<ans<<endl;
    }
    return 0;
}
