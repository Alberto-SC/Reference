#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,s,r;
    cin>>T;
    while(T--){
        cin>>n>>s>>r;
        vector<int> ans(n);
        int diff = 0;
        ans[0] = s-r;
        int mx = s-r;
        s = r;
        for(int i = 1;i<n;i++){
            int rem = (n-i)-1;
            int x = min(s-rem,mx);
            ans[i] = x;
            s-=x;
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}