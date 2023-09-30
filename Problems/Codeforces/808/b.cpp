#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,L,R;
    cin>>T;
    while(T--){
        cin>>n>>L>>R;
        bool flag = true;
        vector<int> ans(n);
        for(int i = 1;i<=n;i++){
            int l = (L+(i-1))/i;
            int r = R/i;
            if(l>r)flag = false;
            ans[i-1] = i*l;
        }
        if(flag){
            cout<<"YES"<<endl;
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}