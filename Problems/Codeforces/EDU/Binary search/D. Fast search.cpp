#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,k,a,b;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    cin>>k;
    sort(nums.begin(),nums.end());
    while(k--){
        cin>>a>>b;
        int l = -1,r = n;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(nums[mid]<a)l = mid;
            else r = mid;
        }

        int f = r+1;
        l = -1,r = n;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(nums[mid]<=b)l = mid;
            else r = mid;
        }
        int e = l+1;
        if(e== 0 || f ==n+1)cout<<0<<" ";
        else cout<<e-f+1<<" ";
    }
    cout<<endl;
    return 0;
}