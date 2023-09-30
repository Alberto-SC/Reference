#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){
    int T,n;
    cin>>T;
    while(T--){
        vector<int> nums(3);
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        
        if(sum%3){
            cout<<-1<<endl;
            continue;
        }

        sort(nums.begin(),nums.end());
        
        int target = sum/3;
        int ans = 0;
        while(nums[2]>target){
            nums[2]--;
            if(nums[0]==target)
                nums[1]++;
            else nums[0]++;
            ans++;
        }
        while(nums[1]>target){
            nums[1]--;
            nums[0]++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

