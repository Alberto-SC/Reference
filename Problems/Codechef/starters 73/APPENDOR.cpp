#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,y;
    cin>>T;
    while(T--){
        cin>>n>>y;
        vector<int> nums(n);
        int x = 0;
        for(auto &c:nums)cin>>c,x|=c;
        bool flag = true;
        int ans = 0;
        for(int i = 22;i>=0;i--){
            int a = (y>>i)&1;
            int b = (x>>i)&1;
            if(b && !a)flag = false;
            else if(a && !b)ans|=(1<<i);
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}