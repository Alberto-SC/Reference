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
        vector<int> ans;
        int l = 0,r = n-1;
        bool odd = -1;
        int res = 0;
        while(l<=r){
            if(l==r){
                odd = nums[l]; 
                break;
            }
            if(nums[l]==nums[r]){
                l++;
                r--;
            }
            else if(nums[l]<nums[r]){
                ans.push_back(nums[l]);
                nums[r]-=nums[l];
                l++;
                res++;
            }
            else if(nums[r]<nums[l]){
                ans.push_back(nums[r]);
                nums[l]-=nums[r];
                r--;
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}