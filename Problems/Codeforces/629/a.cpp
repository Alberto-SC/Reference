#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        lli c = a/b;
        if(b*c == a)cout<<0<<endl;
        else cout<<b*(c+1)-a<<endl;
    }
    return 0;
}
