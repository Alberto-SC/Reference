#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(vector<int> v,int x){
    for(int i = 0;i<v.size();i++){
        v[i] = abs(v[i]-x);
    }
    vector<int> copy = v;
    sort(copy.begin(),copy.end());
    if(copy ==v)return true;
    else return false;
}

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> copy = nums;
        sort(copy.begin(),copy.end());
        if(copy ==nums){
            cout<<0<<endl;
            continue;
        }
        int l = 0,r = 1e12;
        for(int i = 1;i<n;i++){
            if(nums[i-1]>nums[i]){
                int x = (nums[i-1]+nums[i]+1)/2;
                l = max(l,x);
            }
            else if(nums[i-1]==nums[i]){
                continue;
            }
            else{   
                int x = (nums[i-1]+nums[i])/2;
                r = min(r,x);
            }
        }
        if(l>r)cout<<-1<<endl;
        else {
            cout<<l<<endl;
        }
    }
    return 0;
}