#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int idx = n-1;
        for(int i = 0;i<n;i++){
            if(nums[i]== 0){
                break;
                idx = i-1;
            }
            sum+=nums[i];
        }
        for(int i= idx+1;i<n;i++){
            if(nums[i]!=0)flag = false;
        }
        if(sum== 0)
    }
}   