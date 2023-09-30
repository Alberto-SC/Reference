#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,b;
    cin>>n>>b;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> v(n);
    iota(v.begin(),v.end(),0);
    sort(v.begin(),v.end(),[&](int a,int b){
        return nums[a]<nums[b];
    });

    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        int id = v[i];
        int num = nums[id];
        int idl = (((id-1)%n)+n)%n;
        int idr = (id+1)%n;
        int l = nums[idl];
        int r = nums[idr];
        // cout<<id<<" "<<num<<" "<<l<<" "<<r<<" "<<idl<<" "<<idr<<endl;
        if(num==0)ans[id] = 0;
        else if(num==1)ans[id] = 1;
        else {
            ans[id] = 1;
            if(num>l)ans[id] = max(ans[id],ans[idl]+1);
            if(num>r)ans[id] = max(ans[id],ans[idr]+1);
        }
    }
    for(int i = 0;i<n;i++){
        cout<<ans[i]*b;
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;

    return 0;
}