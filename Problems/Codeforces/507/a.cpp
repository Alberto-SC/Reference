#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> nums(n);
    for(auto &x:nums)cin>>x;
    int ans = 0;
    vector<int> price(2);
    price[0] = a;
    price[1] = b;
    for(int i = 0, j = n-1;i<j;i++,j--){
        if(nums[i]== nums[j] && nums[j]!= 2)continue;
        else if(nums[i]<2 && nums[j]<2)return cout<<-1<<endl,0;
        else if(nums[i] == nums[j])ans+=min(a,b)*2;
        else if(nums[i] == 2)ans+=price[nums[j]];
        else if(nums[j] == 2)ans+=price[nums[i]];

    }
    if(n&1)if(nums[n/2] == 2)ans+=min(a,b);
    cout<<ans<<endl;
    return 0;
}