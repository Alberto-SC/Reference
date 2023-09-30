#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int l = 0,r =n-1;
        for(int i = 0;i<n;i++){
            if(i&1)
                cout<<nums[r--]<<" ";
            else 
                cout<<nums[l++]<<" ";
        }
    }
    return 0;
}  
