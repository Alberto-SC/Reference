#include <bits/stdc++.h>
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
 
signed main() {__
    int n,k;
    cin>>n>>k;
    vector<string> v(n);
    for(auto &c:v)cin>>c;
    sort(v.begin(),v.end());
    cout<<v[k-1]<<endl;
    return 0;
}
