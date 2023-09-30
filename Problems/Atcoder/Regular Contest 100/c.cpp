#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<lli> nums;
lli n;

lli func(lli x){
    lli diff = 0;
    for(lli i = 0;i<n;i++){
        diff+=abs(nums[i]-x);
        x++;
    }
    return diff;
}
int main(){__
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    lli l = -(2e9+7);
    lli r = 2e9+7;
    while(l<r){
        lli mid = (l+r)>>1;
        // cout<<mid<<" "<<func(mid)<<" "<<func(mid+1)<<endl;
        if(func(mid)<func(mid+1)) 
            r = mid;
        else 
            l = mid+1;
    }
    // cout<<l<<" "<<r<<endl;
    cout<<min(func(l),func(r))<<endl;
    return 0;
}  

