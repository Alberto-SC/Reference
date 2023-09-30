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
        for(auto &c:nums)cin>>c;
        int q;
        cin>>q;
        while(q--){
            int t,k,x;
            cin>>t;
            if(t ==1){
                cin>>k>>x;
                k--;
                nums[k] = x;
            }
            else {
                cin>>k;
                k--;
                cout<<nums[k]<<endl;
            }
        }
    }
    return 0;
}