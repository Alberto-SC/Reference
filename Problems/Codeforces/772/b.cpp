#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans1 = 0,ans2 =0;
        vector<int> copy = nums;
        for(int i =1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]> nums[i+1]){
                ans1++;
                if(i+2<n)   
                    nums[i+1] = max(nums[i],nums[i+2]);
                else 
                    nums[i+1] = nums[i];
            }
            
        }   
        for(int i = n-2;i>=1;i--){
            if(copy[i]>copy[i-1] && copy[i]> copy[i+1]){
                ans2++;
                if(i-2>=0)
                    copy[i-1] = max(copy[i],copy[i-2]);
                else 
                    copy[i-1] = copy[i];
            }
        }
        cout<<ans1<<endl;
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}