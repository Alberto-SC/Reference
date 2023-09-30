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
        iota(nums.begin(),nums.end(),1);
        if(n&1){
            int idx = 1;
            for(int i = 0;i<n-3;i+=2)
                swap(nums[i],nums[i+1]);
            rotate(nums.begin()+n-3,nums.begin()+n-1,nums.end());
        }
        else{
            for(int i = 0;i<n;i+=2){
                swap(nums[i],nums[i+1]);
            }
        }
        for(auto c:nums)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
