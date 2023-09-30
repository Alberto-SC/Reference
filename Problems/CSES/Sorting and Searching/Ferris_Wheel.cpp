#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    sort(nums.begin(),nums.end());
    int r = n-1;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(r<i)break;
        while(r>i && nums[i]+nums[r]>k){
            r--;
            ans++;
        }
        if(r == i){
            ans++;
            break;
        }
        if(nums[i]+nums[r]>k)ans+=2;
        else ans++,r--;
    }
    cout<<ans<<endl;
    return 0;
}