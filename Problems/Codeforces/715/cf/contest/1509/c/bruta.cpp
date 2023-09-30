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
        vector<int> ans;
        int resmn = 1e15;
        sort(nums.begin(),nums.end());
        do{
            int res = 0,mn = 1e15,mx = -1;
            for(int i = 0;i<n;i++){
                mn = min(mn,nums[i]);
                mx = max(mx,nums[i]);
                res+=mx-mn;
            }
            if(res<resmn){
                ans = nums;
                resmn = res;
            }
        }while(next_permutation(nums.begin(),nums.end()));
        sort(nums.begin(),nums.end());
        do{
            int res = 0,mn = 1e15,mx = -1;
            for(int i = 0;i<n;i++){
                mn = min(mn,nums[i]);
                mx = max(mx,nums[i]);
                res+=mx-mn;
            }
            if(res==resmn){
                ans = nums;
                for(auto c:nums)cout<<c<<" ";
                cout<<endl;
            }
        }while(next_permutation(nums.begin(),nums.end()));
    }
    return 0;
}  
