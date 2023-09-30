#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    vector<int> a(7);
    for(auto &c:a)cin>>c;
    int ans = 0;
    ans+=a[0]-(a[0]&1);
    ans+=a[3]-(a[3]&1);
    ans+=a[4]-(a[4]&1);
    ans+=a[1];
    if((a[0]&1) && (a[3]&1) && (a[4]&1))
        ans+=3;
    cout<<ans<<endl;
}