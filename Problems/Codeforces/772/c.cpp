#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

struct ANS{
    int x,y,z;
};

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        if(nums[n-2]>nums[n-1]){
            cout<<-1<<endl;
            continue;
        }
        vector<int> S = nums;
        sort(S.begin(),S.end());
        if(nums==S){
            cout<<0<<endl;
            continue;
        }
        vector<ANS>ans;
        for(int i = 0;i<n-2;i++){
            ans.push_back({i+1,n-1,n});
            nums[i]  = nums[n-2]-nums[n-1];
        }
        if(nums[n-2]<0 && nums[n-1]<0){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans.size()<<endl;
        for(auto c:ans)cout<<c.x<<" "<<c.y<<" "<<c.z<<endl;
        cout<<endl;
    }
    return 0;
}