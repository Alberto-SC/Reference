#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main(){
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    if(n == 1)return cout<<nums[0]<<endl,0;
    bool pos = false,neg = false;
    lli sum = 0,mn = 1e16;
    for(int i = 0;i<n;i++){
        mn = min(mn,abs(nums[i]));
        pos|=(nums[i]>=0);
        neg|=(nums[i]<=0);
        sum+=abs(nums[i]);
    }
    if(pos&&neg)
        cout<<sum<<endl;
    else 
        cout<<sum-(2*mn);  
    return 0;

}