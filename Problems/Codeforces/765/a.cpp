#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main(){__
    int t= 1,n,l;
    cin>>t;
    while(t--){
        cin>>n>>l;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = l;i>= 0;i--){
            int cont = 0;
            for(int j = 0;j<n;j++){
                cont+=(nums[j]>>i)&1;
            }
            if(cont>n/2)
                ans+=(1<<i);
        }

        cout<<ans<<endl;
    }
    return 0;
}
