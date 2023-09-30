#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        lli lastg = 0;
        lli ans = 0;
        for(int i = 0;i<n;i++){
            nums[i]+=ans;
            if(nums[i]>=lastg)lastg = nums[i];
            else ans+=lastg-nums[i];
        }
        
        cout<<ans<<endl;
    }
    return 0;
}