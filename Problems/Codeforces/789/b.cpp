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
        vector<char> nums(n);
        for(auto &c:nums)cin>>c;
        int mn = 0,ans = 0;
        int last = -1;
        for(int i = 0;i<n;i+=2){
            if(nums[i]!=nums[i+1])mn++;
            else{
                if(nums[i]!=last)ans++;
                last = nums[i];
            }
        }

        cout<<mn<<" "<<max(1ll,ans)<<endl;

    }
    return 0;
}