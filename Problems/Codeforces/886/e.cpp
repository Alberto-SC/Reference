#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n,c;
    cin>>T;
    while(T--){
        cin>>n>>c;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        int l = 0,r = 1e9;
        while(l+1<r){
            int m = (l+r)>>1;
            int res = 0;
            for(int i = 0;i<n;i++){
                int l = nums[i]+(2*m);
                res+=l*l;
                if(res>c)break;
            }

            if(res>=c)r = m;
            else l = m;
        }
        cout<<r<<endl;
    }
    return 0;
}