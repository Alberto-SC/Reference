#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

bool check(int x,vector<int> &v,int m){
    int n = v.size();
    int l = 0,r = n-1;

    while(m--){
        if(l>=r)return false;
        if(v[r]>=x)r--;
        else{
            while(l<r && v[l]+v[r]<x)l++;
            if(l>=r)return false;
            l++;
            r--;
        }
    }

    return true;
}

signed main(){__
    int T,n,m;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());

        int l = 0,r = 1e7;
        while(l+1<r){
            int mid = (l+r)>>1;
            if(check(mid,nums,m))l = mid;
            else r = mid;
        }
        cout<<l<<endl;
    }
    return 0;
}
