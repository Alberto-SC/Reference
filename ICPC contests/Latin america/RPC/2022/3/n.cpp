#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int a = 0,b = 0;
    for(int i = 0;i<n;i++){
        if(nums[i]>x)
            b++;
        else if(x>nums[i])
            a++;
    }
    if(a>b)cout<<1<<endl;
    else if(b>a)cout<<2<<endl;
    else cout<<0<<endl;
}   