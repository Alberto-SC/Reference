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
        int sum = 0;
        for(int i = 1;i<=n;i++){
            ans[i-1] = i;
            sum+=i;
        }

        int need =sum%n;

        ans[0]+=n-need;

        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}