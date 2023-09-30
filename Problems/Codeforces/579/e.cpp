#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        map<int,int> mp;
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        int last = nums[0]+2;
        int ans = 0;
        for(int i = 0;i<n;i++){
            int x = -1;
            for(int y = 1;y>=-1;y--){
                if(nums[i]+y>0 && nums[i]+y<last){
                    x = nums[i]+y;
                    break;
                }
            }
            if(x ==-1)continue;
            ans++;
            last = x;
        }
        cout<<ans<<endl;
    }
    return 0;
}