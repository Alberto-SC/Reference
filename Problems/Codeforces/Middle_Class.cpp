#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,t,x;
    cin>>t;
    while(t--){
        cin>>n>>x;
        lli ans = 0;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        lli sum = 0;
        while(ans<n &&  sum+nums[ans] >= (ans+1)*x){
            sum+=nums[ans];
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}