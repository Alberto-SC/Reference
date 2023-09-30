#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli n,m,k;
    cin>>n>>m>>k;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    lli ans1 = 0;
    lli c = m/(k+1);
    lli x = ((nums[n-1]*k)+nums[n-2])*c;
    if(m%(k+1)== 0)return cout<<x<<endl,0;
    x+=nums[n-1]*(m%(k+1));
    cout<<x<<endl;
    return 0;
}