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
        for(int i = 0;i<n;i++){
            if(i&1)ans[i] = 2;
            else ans[i] = 1;
        }
        
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}