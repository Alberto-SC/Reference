#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
signed main(){__
    int t,n,l,r,k;
    cin>>t;
    while(t--){
        cin>>l>>r>>k;
        int s = (r-l)+1;
        if(s ==1 && l>1)cout<<"YES"<<endl;
        else if(l&1 && k>=(s/2) +s%2)cout<<"YES"<<endl;
        else if(l%2==0 && k>= s/2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;

}