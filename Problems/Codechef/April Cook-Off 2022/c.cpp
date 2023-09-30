#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

signed main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> l(n);
        vector<int> r(n);
        for(auto &c:l)cin>>c;
        for(auto &c:r)cin>>c;
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            ans+=min(r[i],l[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
