#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    lli n,r,avg;
    cin>>n>>r>>avg;
    vector<pair<lli,lli>> nums(n);
    lli sum = 0;
    for(lli i = 0;i<n;i++){
        cin>>nums[i].second>>nums[i].first;
        sum+=nums[i].second;
    }
    if(sum>= n*avg )return cout<<0<<endl,0;
    sort(nums.begin(),nums.end());
    lli ans = 0;
    for(lli i = 0;i<n;i++){
        if(sum>= n*avg)break;
        lli x = min((n*avg)-sum,r-nums[i].second);
        ans+= x*nums[i].first;
        sum+=x;
    }
    cout<<ans<<endl;
    return 0;
}