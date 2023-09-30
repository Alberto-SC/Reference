#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int MOD(int a,int b){
    return ((a%b)+b)%b;
}

signed main(){__
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int ans = 1e15;
    vector<int> b = nums;
    for(int k = 0;k<n;k++){
        int res = k*x;
        for(int i = 0;i<n;i++)
            res+=b[i];
        for(int i = 0;i<n;i++){
            b[i] = min(b[i],nums[MOD(i-(k+1),n)]);
        }
        ans = min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}