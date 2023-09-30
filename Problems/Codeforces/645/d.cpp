#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli n,x;
    cin>>n>>x;
    vector<lli> nums(2*n);
    vector<lli> ac;
    vector<lli> ach;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        nums[i+n] = nums[i];
    }
    n*=2;
    ac.push_back(nums[0]);
    ach.push_back((nums[0]*(nums[0]+1))/2);
    for(lli i = 1;i<n;i++)ac.push_back(ac.back()+nums[i]);
    for(lli i = 1;i<n;i++)ach.push_back(ach.back()+(nums[i]*(nums[i]+1))/2); 
    lli ans = 0;
    for(int i = 0;i<n;i++){
        if(ac[i]<x)continue;
        int idx = lower_bound(ac.begin(),ac.end(),ac[i]-x)-ac.begin();
        lli y = ach[i]-ach[idx];
        lli z = x-(ac[i]-ac[idx]);
        z = nums[idx]-z;
        z = (z*(z+1))/2;
        lli k = (nums[idx]*(nums[idx]+1))/2;
        y+=k-z;
        ans = max(ans,y);
    }
    cout<<ans<<endl;
    return 0;
}