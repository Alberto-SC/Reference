#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> A,pair<int,int>B){
    if(A.first == B.first)return A.second>B.second;
    return A.first<B.first;
}
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        map<int,int> mp;
        vector<int> segments((2*k)+1);
        for(int i = 0;i<n/2;i++){
            int sum = nums[i]+nums[(n-1)-i];
            mp[sum]++;
            int r = sum+(max(k-nums[i],k-nums[(n-1)-i]));
            int l = sum-(max(nums[i]-1,nums[(n-1)-i]-1));
            segments[l]++;
            segments[r+1]--;
        }
        for(int i = 1;i<=2*k;i++){
            segments[i]+=segments[i-1];
        }
        // for(int i = 0;i<=2*k;i++)cout<<segments[i]<<" ";
        // cout<<endl;
        int mx =10000000,count = 0,idx,l;
        for(int i = 1;i<=2*k;i++){
            int ans  = segments[i]-mp[i];
            ans+=2*((n/2)-segments[i]);
            mx = min(ans,mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}