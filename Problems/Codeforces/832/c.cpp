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
        int mn = 1e9+1;
        for(auto &c:nums)cin>>c,mn = min(c,mn);

        if(nums[0]==mn)cout<<"BOB"<<endl;
        else cout<<"ALICE"<<endl;
    }
    return 0;
}