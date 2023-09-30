#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 0;
    sort(nums.begin(),nums.end());
    int i = 0;
    while(i<n-1){
        int cont = 0;
        while(i<n-1 && nums[i+1]>nums[i] && nums[i+1]<= nums[i]*2){
            i++;
            cont++;
        }
        i++;
        ans = max(ans,cont);
    }
    cout<<ans+1<<endl;
    return 0;
}