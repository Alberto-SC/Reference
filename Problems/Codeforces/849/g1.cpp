#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,c;
    cin>>T;
    while(T--){
        cin>>n>>c;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;

        for(int i = 0;i<n;i++)
            nums[i]+=i+1;
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<n;i++){
            if(nums[i]<=c){
                ans++;
                c-=nums[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}