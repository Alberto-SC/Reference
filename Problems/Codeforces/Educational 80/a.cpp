#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t,n,d;
    cin>>t;
    while(t--){
        cin>>n>>d;
        int x = n/2;
        if(d<=n)cout<<"YES"<<endl;
        else if(ceil(d/((x+1)*1.0))+(x)<=n)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}