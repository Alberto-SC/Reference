#include <bits/stdc++.h>
using  namespace std;
typedef long long int lli;
int main(){
    lli t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        lli i;
        if(n%2 == 0)cout<<n+(k*2ll)<<endl;
        else {
            for(i = 3;i*i<=n;i+=2)
                if(n%i == 0)break;
            if(n%i != 0)i = n;
            lli x = n+i;
            x+= ((k-1)*2ll);
            cout<<x<<endl;
        }
    }
    return 0;
}