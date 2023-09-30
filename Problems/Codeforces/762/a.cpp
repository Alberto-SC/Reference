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
        if(n&1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag= true;
        for(int i =0;i<n/2;i++){
            if(s[i]!=s[i+(n/2)])flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}