#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    lli x = 0,y = 0;
    for(lli i = 0;i<n/2;i++){
        x+=nums[(n-1)-i];
        y+=nums[i];
    }
    if(n&1)x+=nums[n/2];
    lli dist = x*x+y*y;
    cout<<dist<<endl;
    return 0;
}