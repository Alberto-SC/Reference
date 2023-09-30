#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli a,b;
    cin>>a>>b;
    cout<<"YES"<<endl;
    for(lli i = a;i<=b;i+=2)cout<<i<<" "<<i+1<<endl;
    return 0;
}