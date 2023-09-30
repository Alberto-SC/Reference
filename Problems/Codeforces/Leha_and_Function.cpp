#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<pair<int,int>> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    sort(nums.rbegin(),nums.rend());
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        ans[a[i].second] = nums[i];
    }
    for(auto c:ans)cout<<c<<" ";
    cout<<endl;
    
    return 0;
}