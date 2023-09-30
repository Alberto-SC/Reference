#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        bool flag = false;
        for(int i = 0;i<n;i++){
            if((s-nums[i])% (n-1) == 0 && (s-nums[i])/(n-1)== nums[i])
                flag = true;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
