#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli a,b,c,d,t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d;
        if(b>=a)cout<<b<<endl;
        else if(d>=c)cout<<-1<<endl;
        else {
            lli total = b;
            lli rest = b;
            lli l = a-b;
            lli sleep = c-d;
            lli x = l/sleep;
            if(l % sleep == 0)cout<<total+(x*c)<<endl;
            else cout<<total+((x+1)*c)<<endl;
        }
    }
    return 0;
}