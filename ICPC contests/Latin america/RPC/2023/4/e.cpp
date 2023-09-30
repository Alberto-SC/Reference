#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    while(T--){
        cin>>n>>x;
        int sum = 0;

        vector<int> nums(n);
        for(auto &c:nums)cin>>c;

        for(int i = 0;i<n;i++){
            sum+=(nums[i]*nums[i]);
        }

        long double z = sqrt((x*n)/(sum*1.0));

        for(int i = 0;i<n;i++){
            long double res = nums[i]*z;
            cout<<fixed<<setprecision(10)<<res;
            if(i !=n-1)cout<<" ";
        }        
    }
    return 0;
}