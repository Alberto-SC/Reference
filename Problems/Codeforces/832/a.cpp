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
        int sum = 0;
        for(auto &c:nums)cin>>c,sum+=c;
        cout<<abs(sum)<<endl;
    }
    return 0;
}