#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.begin(),nums.end());

        int gcd  = 0;
        for(int i = 1;i<n;i++){
            gcd = __gcd(gcd,nums[i]-nums[0]);
        }
        if(gcd==1)cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}