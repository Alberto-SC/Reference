#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t = 1,n;
    // cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());
        int gcd = 0;
        for(int i = 0;i<n-1;i++){
            gcd = __gcd(gcd,nums[i+1]-nums[i]);
        }
        vector<int> ans;
        if(gcd !=1)ans.push_back(gcd);
        for(int i = 2;i*i<=gcd;i++){
            if(gcd%i == 0){
                ans.push_back(i);
                if(gcd/i != i)
                    ans.push_back(gcd/i);
            }
        }
        sort(ans.begin(),ans.end());
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
}   