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
        int gcd  = 0;
        for(auto &c:nums)cin>>c,gcd = __gcd(c,gcd);
    
        int ans = 0;
        bool flag = true;
        for(int i = 0;i<n;i++){
            int x = nums[i]/gcd;
            while(x%2 ==0){
                x/=2;
                ans++;
            }
            while(x%3 ==0){
                x/=3;
                ans++;
            }
            if(x>1)flag = false;
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}