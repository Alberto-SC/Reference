#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &x:nums)cin>>x;
        sort(nums.rbegin(),nums.rend());
        int i = 0;
        while(nums[i]>=i+1 && i<n){i++;}
        cout<<i<<endl;
    }
    return 0;
}