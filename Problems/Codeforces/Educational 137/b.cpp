#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> ans(n);
        iota(ans.begin(),ans.end(),1);
        swap(ans[1],ans.back());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}