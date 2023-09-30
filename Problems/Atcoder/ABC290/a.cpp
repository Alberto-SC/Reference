#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);

    for(auto &c:a)cin>>c;
    for(auto &c:b)cin>>c,c--;
    int ans = 0;
    for(auto c:b){
        ans+=a[c];
    }
    cout<<ans<<endl;
        
    return 0;

}
