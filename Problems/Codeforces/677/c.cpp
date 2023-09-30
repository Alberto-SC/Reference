#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int mx = *max_element(nums.begin(),nums.end());
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] == mx && ((i+1<n && nums[i+1]<nums[i]) || i-1>=0 && nums[i-1]<nums[i]))
                ans = i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}

