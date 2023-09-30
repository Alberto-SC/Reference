#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    while(T--){
        n = 4;
        vector<int> nums(n);
        int sum = 0;
        bool flag = false;
        for(auto &c:nums)cin>>c,sum+=c;
        for(int mask = 1;mask<(1<<4);mask++){
            int s= 0;
            for(int i = 0;i<n;i++){
                if((mask>>i)&1)s+=nums[i];
            }
            if(s == (sum-s))flag = true;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}