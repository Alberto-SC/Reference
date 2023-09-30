#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<string> v(n);
        for(auto &c:v)cin>>c;
        reverse(v.begin(),v.end());
        for(auto c:v)cout<<c<<endl;
    }
    return 0;
}