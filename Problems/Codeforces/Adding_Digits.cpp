#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n;
    cin>>a>>b>>n;
    int mod = (a*10)%b;
    // cout<<mod<<endl;
    if(b-mod >9 && mod!= 0)return cout<<-1<<endl,0;
    a*=10;
    if(mod!= 0)
        a+=b-mod;
    string ans =to_string(a);
    for(int i =0;i<n-1;i++)
        ans = ans+to_string(0);
    cout<<ans<<endl;
    return 0;
}