#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        n = s.size();
        if(s[1]==s[0]|| s[1]<s[0]){
            cout<<s[0]<<" "<<s[1]<<" "<<s.substr(2)<<endl;
        }
        else {
            cout<<s[0]<<" "<<s.substr(1,n-2)<<" "<<s.back()<<endl;
        }
    }
    return 0;
}