#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> nums(n);
    vector<int> a(m);
    for(auto &c:nums)cin>>c;
    for(auto &c:a)cin>>c;
    sort(nums.begin(),nums.end());
    sort(a.begin(),a.end());
    int idx = 0;
    int ans = 0;
    for(int i = 0;i<n;i++){
        while(idx<m && abs(a[idx]-nums[i])>k &&a[idx]<nums[i]){
            idx++;
        }
        if(idx>=m)break;
        if(abs(a[idx]-nums[i]<=k)){
            idx++;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}