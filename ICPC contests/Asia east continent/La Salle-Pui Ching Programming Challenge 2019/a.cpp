#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
signed main(){__
    int n,k,e;
    cin>>n>>k>>e;
    vector<int> nums(n);
    int s = 0;
    for(auto &c:nums)cin>>c,s+=c;
    sort(nums.begin(),nums.end());
    int days = 0;
    for(int i = 0;i<n;i++){
        k+=e;
        int need = nums[i]-k;
        if(need<0)need =0;
        int d = ceil(need/(e*1.0));
        k += e*d;
        k-=nums[i];
        days+=d+1;
    }
    cout<<days<<endl;
    return 0;
}
