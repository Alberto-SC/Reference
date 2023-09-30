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
        vector<int> ans(n);
        ans[0] = nums[0];
        bool flag = false;
        for(int i= 1;i<n;i++){
            int x = ans[i-1]+nums[i];
            int y = ans[i-1]-nums[i];
            ans[i] = x;
            if(x>=0 && y>=0 && x!=y)flag = true;
        }
        if(flag)cout<<-1<<endl;
        else {
            for(auto c:ans)cout<<c<<" ";
            cout<<endl;
        }
    }
    return 0;
}