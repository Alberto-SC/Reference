#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    while(k--){
        cin>>x;
        int l = -1,r = n;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(nums[mid]<=x)l = mid;
            else r = mid;
        }
        if(l == -1)cout<<0<<endl;
        else cout<<l+1<<endl;
    }
    return 0;
}