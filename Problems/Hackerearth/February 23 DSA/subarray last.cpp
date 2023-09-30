#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        int ans = 0;
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            ans+=nums[i]*(i+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
