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
        int neg = 0;
        bool zero = false;
        int sum = 0;
        int mn = 1e12;
        for(auto &c:nums){
            cin>>c;
            if(c<0)neg++;
            if(c == 0)zero = true;
            mn = min(abs(c),mn);
            sum+=abs(c);
        }
    
        if(neg%2 ==0 || (neg&1 && zero))cout<<sum<<endl;
        else cout<<sum-(2*mn)<<endl;
    }

    return 0;
}