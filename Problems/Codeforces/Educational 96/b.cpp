#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<lli> nums(n);
        for(auto &c:nums)cin>>c;
        sort(nums.rbegin(),nums.rend());
        for(lli i = 1;i<n&& k;i++,k--){
            nums[0] +=nums[i];
        }
        cout<<nums[0]<<endl;

    }
    return 0;
}

