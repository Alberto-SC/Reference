#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);

        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int s = 0;
            int x = 0;
            for(int j = i;j<n;j++){
                s+=nums[j];
                x^=nums[j];
                if(s!=x)break;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
