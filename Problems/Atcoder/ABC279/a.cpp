#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        string s;
        cin>>s;
        int ans = 0;
        for(auto c:s){
            if(c=='w')ans+=2;
            else ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}