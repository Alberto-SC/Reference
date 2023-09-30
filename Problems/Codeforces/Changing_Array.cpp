#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gauss(lli a){
    return (a*(a-1))/2;
}
int main(){
    lli n,k;
    cin>>n>>k;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    lli x = 0;
    map<lli,lli> mp;
    mp[0] = 1;
    for(lli i = 0;i<n;i++){
        x^= min(nums[i],(1<<k)-1-nums[i]);
        mp[x]++;
    }
    lli res = 0;
    for(auto c:mp){
        res += gauss(c.second/2);
        res +=gauss((c.second+1)/2);
    }
    cout<<gauss(n+1)-res<<endl;
    return 0;
}