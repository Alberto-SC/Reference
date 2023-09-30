#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t,n;
    cin>>t;
    while(t--){
        vector<int> nums(4);
        for(auto &c:nums)cin>>c;
        int x = nums[0];
        sort(nums.begin(),nums.end());
        for(int i = 0;i<4;i++){
            if(nums[i]== x){
                cout<<4-(i+1)<<endl;
                break;
            }
        }
    }
    return 0;
} 