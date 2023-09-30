#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int gcd = 0;
        for(int i = 0;i<n;i+=2){
            gcd = __gcd(gcd,nums[i]);
        }
        bool flag = true;
        for(int i = 1;i<n;i+=2){
            if(nums[i]%gcd==0)flag = false;
        }

        if(flag){
            cout<<gcd<<endl;
            continue;
        }
        gcd = 0;
        for(int i = 1;i<n;i+=2){
            gcd = __gcd(gcd,nums[i]);
        }
        flag = true;
        for(int i= 0;i<n;i+=2){
            if(nums[i]%gcd ==0)flag = false;
        }
        if(flag)cout<<gcd<<endl;
        else cout<<0<<endl;
    }
    return 0;
}