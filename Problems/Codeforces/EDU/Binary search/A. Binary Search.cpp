#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    while(k--){
        cin>>x;
        int l = 0,r = n-1;
        bool flag = false;
        while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]==x)flag = true;
            if(nums[mid]<x)l = mid+1;
            else r = mid-1;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}