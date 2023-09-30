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
        for(auto &c:nums)cin>>c,c*=-1;
        next_permutation(nums.begin(),nums.end());
        for(auto c:nums)cout<<-c<<" ";
        cout<<endl;

    }
    return 0;
}