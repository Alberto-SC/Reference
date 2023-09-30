#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s,t;
        cin>>s>>t;
        int z = 0,o = 0;
        for(int i = 0;i<n;i++){
            z+=s[i]=='0';
            o+=s[i]=='1';
            z-=t[i]=='0';
            o-=t[i]=='1';
        } 
        if(z|| o)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}