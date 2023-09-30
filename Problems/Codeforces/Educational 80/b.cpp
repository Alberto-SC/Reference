#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli t,a,b;
    string s;
    cin>>t;
    while(t--){
        cin>>a>>b;
        s = to_string(b);
        lli count= 0;
        for(int i = 0;i<s.size();i++)
            if(s[i] == '9')count++;
        lli ans;
        if(count == s.size())ans = a*s.size();
        else ans = a*(s.size()-1);
        cout<<ans<<endl;
    }
    return 0;
}