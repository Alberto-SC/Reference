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
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        bool flag = true;
        int idx = n-1;
        for(int i = n-1;i>=1;i-=2,idx-=2){
            if(nums[i] != copy[idx] && nums[i]!=copy[idx-1])flag = false;
            if(nums[i-1] != copy[idx] && nums[i-1]!=copy[idx-1])flag = false;
        }
        if(n&1 && nums[0]!=copy[0])flag = false;

        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}