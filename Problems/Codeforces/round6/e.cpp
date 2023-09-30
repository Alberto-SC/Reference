#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n;
    cin>>n;
    vector<lli>nums(n);
    for(auto &c:nums)cin>>c;
    vector<lli> diff;
    sort(nums.begin(),nums.end());
    lli a = accumulate(nums.begin(),nums.end(),0ll);
    lli ans = *max_element(nums.begin(),nums.end());
    lli l = ans+1,r = 1ll<<40;
    // while(l<r-1){
    //     lli m = (l+r)/2;
    //     lli s;
    //     for(int i = 0;i<n;i++){s+=m-nums[i];if(s>m)break;}
    //     if(s>=m)r = m;
    //     else l = m;
    // }    
    cout<<max(ans,(lli)ceil(a*1.0/(n-1)))<<endl;
    return 0;
}