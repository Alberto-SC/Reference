#include <bits/stdc++.h>
using namespace std;
vector<int>nums;
int k;
bool check(int x){
    int box = 0;
    int n = nums.size();
    int l = 0;
    for(int i =n-1;i>=0 && i>l;i--){
        if(i+1<nums.size() &&nums[i]+nums[l]<=x)i++,box++;
        else if(nums[i]<=x)box++;
        else return false;
    }
    if(box>k)return false;
    return true;
}
int main(){
    int n;
    cin>>n>>k;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    int ans = nums[n-1];
    for(int i = 0;i<n-k;i++){
        ans = max(ans,nums[i]+nums[2*(n-k)-i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
