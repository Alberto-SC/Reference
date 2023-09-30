#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,m;
    cin>>n>>m;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    lli mx = 0,sum = 0;
    for(lli i = 0;i<n;i++){
        mx = max(mx,nums[i]);
        sum+=nums[i];
    }
    sort(nums.begin(),nums.end());
    int pos = 0,last= 0;
    for(int i = 0;i<n;i++){
        pos++;
        if(nums[i]>last)last++;
    }
    pos+= nums[n-1]-last;
    cout<<sum-pos<<endl;
    return 0;
}