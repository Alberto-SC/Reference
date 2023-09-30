#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

int32_t main(){__
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int X = nums[n-1]-nums[0];

        int l = 0,r = n-1;
        
        int mn = 0,mx = 0,s = 0;
        vector<int> ans;
        while(l<=r){
            s+=nums[r];
            if(s-mn>=X){
                s-=nums[r];
                s+=nums[l];
                ans.push_back(nums[l]);
                l++;
                
            }
            else{
                ans.push_back(nums[r]);
                r--;
            }
            mn = min(mn,s);
            mx = max(mx,s-mn);
        }
        if(mx>=X)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}
