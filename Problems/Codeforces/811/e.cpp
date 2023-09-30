#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            while(nums[i]%10 != 2 && nums[i]%10 != 0){
                nums[i]+=nums[i]%10;
            }
            mp[nums[i]%10]++;
        }
        if(mp[2] && mp[0])cout<<"NO"<<endl;
        else if(mp[2]){
            int mx = *max_element(nums.begin(),nums.end());
            bool flag = true;
            for(int i = 0;i<n;i++){
                if((mx-nums[i])%20)flag = false;
            }
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            int mx = *max_element(nums.begin(),nums.end());
            int mn = *min_element(nums.begin(),nums.end());
            if(mx ==mn)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  
