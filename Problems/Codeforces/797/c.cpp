#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        vector<int> ans(n);
        ans[0] = b[0]-a[0];
        for(int i = 1;i<n;i++){
            if(a[i]>=b[i-1])
                ans[i] = b[i]-a[i];
            else 
                ans[i] = b[i]-b[i-1];
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
