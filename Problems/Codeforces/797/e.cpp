#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans+=nums[i]/k;
            nums[i]%=k;
        }
        sort(nums.begin(),nums.end());
        int j = 0;
        for(int i = n-1;i>=0;i--){
            if(j>=i)break;
            while(nums[i]+nums[j]<k && j<i){
                j++;
            }       
            if(i == j)break;
            j++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
