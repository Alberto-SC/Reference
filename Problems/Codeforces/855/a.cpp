#include <bits/stdc++.h>
#define ing long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string t = "meow";
        s.erase(unique(s.begin(),s.end()),s.end());
        if(s == t)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

