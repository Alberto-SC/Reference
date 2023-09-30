#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int check(int m,vector<int> &v,int d){
    int sum = 0;
    int n = v.size();
    for(int i = 0;i<d;i++){
        sum+=(i%(m+1))>=n?0:v[i%(m+1)];
    }
    return sum;
}

signed main(){__
    int T = 1,n,c,d;
    cin>>T;
    while(T--){
        cin>>n>>c>>d;
        vector<int> nums(n);
        int sum = 0;
        for(auto &x:nums)cin>>x;
        sort(nums.rbegin(),nums.rend());
        sum = nums[0]*d;
        if(sum<c){
            cout<<"Impossible"<<endl;
            continue;
        }
        int l = 0,r = 1e18;

        while(l+1<r){
            int m = (l+r)>>1;
            if(check(m,nums,d)>=c) l = m;
            else r = m;
        }
        if(r == 1e18)cout<<"Infinity"<<endl;
        else
            cout<<l<<endl;
    }
    return 0;
}