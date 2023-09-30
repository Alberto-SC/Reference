#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    cin>>s;
    lli n = s.size();
    string a = string(n-1, '9');
    a= string(1,s[0]-1)+a;
    lli x = stoll(a),y = stoll(s);
    lli z = y-x;
    // cout<<x<<"  "<<z<<endl;
    lli ans= 0;
    while(x){
        ans+=x%10;
        x/=10;
    }
    while(z){
        ans+=z%10;
        z/=10;
    }

    cout<<ans<<endl;
    return 0;
}