#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,x;
    cin>>T;
    while(T--){
        cin>>n>>x;
        vector<int> nums(n);
        int odd = 0,even = 0;
        for(auto &c:nums){
            cin>>c;
            if(c&1)odd++;
            else even++;
        }

        if(x&1){
            int ans = (even+1)/2;
            cout<<ans<<endl;
        }        
        else{
            if(odd == 0)cout<<-1<<endl;
            else cout<<even<<endl;
        }
    }
    return 0;
}